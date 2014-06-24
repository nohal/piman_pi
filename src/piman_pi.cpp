/******************************************************************************
 *
 * Project:  OpenCPN
 * Purpose:  Plug-in Manager Plugin
 * Author:   Pavel Kalian
 *
 ***************************************************************************
 *   Copyright (C) 2014 by Pavel Kalian                                    *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301,  USA.         *
 ***************************************************************************
 */


// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#include "piman_pi.h"
#include "PluginManifest.h"

#include <wx/filename.h>
#include <wx/wfstream.h>
#include <wx/filefn.h> 
#include <wx/dir.h>
#include <wx/tarstrm.h>
#include "wx/curl/dialog.h"

// Define NAN, which is unavailable on Windows
#ifdef _MSC_VER
#define INFINITY (DBL_MAX+DBL_MAX)
#define NAN (INFINITY-INFINITY)
#endif


// the class factories, used to create and destroy instances of the PlugIn

extern "C" DECL_EXP opencpn_plugin* create_pi ( void *ppimgr )
{
    return new piman_pi ( ppimgr );
}

extern "C" DECL_EXP void destroy_pi ( opencpn_plugin* p )
{
    delete p;
}

//---------------------------------------------------------------------------------------------------------
//
//    PiMan PlugIn Implementation
//
//---------------------------------------------------------------------------------------------------------

#include "icons.h"

//---------------------------------------------------------------------------------------------------------
//
//          PlugIn initialization and de-init
//
//---------------------------------------------------------------------------------------------------------

piman_pi::piman_pi ( void *ppimgr )
    : opencpn_plugin_111 ( ppimgr )
{
    // Create the PlugIn icons
    initialize_images();
    
}

piman_pi::~piman_pi ( void )
{
    delete _img_piman_pi;
    delete _img_piman;
}

int piman_pi::Init ( void )
{
    AddLocaleCatalog ( _T ( "opencpn-piman_pi" ) );

    ::wxDisplaySize ( &m_display_width, &m_display_height );

    //    Get a pointer to the opencpn configuration object
    m_pconfig = GetOCPNConfigObject();
    
    //    And load the configuration items
    LoadConfig();

    // Get a pointer to the opencpn display canvas, to use as a parent for the PIMAN dialog
    m_parent_window = GetOCPNCanvasWindow();
    
    m_leftclick_tool_id = InsertPlugInTool ( _T ( "Plug-in Manager" ), _img_piman, _img_piman, wxITEM_CHECK,
                          _ ( "Plug-in Manager" ), _ ( "Plug-in Manager" ), NULL,
                          PIMAN_TOOL_POSITION, 0, this );
    
    m_pPimanDlg = new PluginMgrDlgImpl(this, m_parent_window);
    m_pSettingsDlg = new PimanSettingsDlgImpl(this, m_parent_window);
    
    m_data_dir = m_plugins_dir = *GetpPrivateApplicationDataLocation();
    m_data_dir.Append(wxFileName::GetPathSeparator()).Append(_T("piman_pi"));
    m_plugins_dir.Append(wxFileName::GetPathSeparator()).Append(_T("plugins"));
    
    if (!wxDirExists(m_data_dir))
        wxFileName::Mkdir(m_data_dir);
        
    if (!wxDirExists(m_plugins_dir))
        wxFileName::Mkdir(m_plugins_dir);
    
    m_cached_manifest_list = wxFileName(m_data_dir, _T("manifestlist.xml")).GetFullPath();
        
    if ( m_bCheckAtStartup && m_iLastUpdate <= wxDateTime::GetTimeNow() - m_iCheckAtStartupInterval * 86400 )
        UpdateManifestsFromNet();
    else
    {    
        if (wxFileExists(m_cached_manifest_list))
        {
            m_manifest_list.Load(m_cached_manifest_list.mb_str());
            LoadManifestsFromDisk();
        }
    }
    
    ApplyConfig();
    
    return ( WANTS_TOOLBAR_CALLBACK    |
             INSTALLS_TOOLBAR_TOOL     |
             WANTS_PREFERENCES         |
             WANTS_CONFIG
           );
}

void piman_pi::UpdateManifestsFromNet()
{
    DownloadManifestList();
    DownloadManifests();
    if (wxFileExists(m_cached_manifest_list))
    {
        m_iLastUpdate = wxDateTime::GetTimeNow();
        m_manifest_list.Load(m_cached_manifest_list.mb_str());
        LoadManifestsFromDisk();
        ApplyConfig();
    }
}

void piman_pi::LoadManifestsFromDisk()
{
    m_plugin_manifests.clear();
    for(std::vector<Manifest>::iterator it = m_manifest_list.Manifests.begin(); it != m_manifest_list.Manifests.end(); ++it)
    {
        wxString manifest_name = wxFileName(m_data_dir, wxString::Format(_T("%s.manifest"), it->GetName().c_str())).GetFullPath();
        if (wxFileExists(manifest_name))
            m_plugin_manifests.push_back(PluginManifest(manifest_name.mbc_str()));
    }
}

bool piman_pi::DownloadFile(const wxString url, const wxString local_file)
{
    wxCurlHTTP dldr;
    wxString tmp_name = wxFileName::CreateTempFileName(_T("piman"));
    if (dldr.Get(tmp_name, url))
    {
        wxCopyFile(tmp_name, local_file);
        wxRemoveFile(tmp_name);
        return true;
    }
    return false;
}

void piman_pi::DownloadManifests()
{
    for(std::vector<Manifest>::iterator it = m_manifest_list.Manifests.begin(); it != m_manifest_list.Manifests.end(); ++it)
    {
        wxString manifest_name = wxFileName(m_data_dir, wxString::Format(_T("%s.manifest"), it->GetName().c_str())).GetFullPath();
        DownloadFile(it->GetUrl(), manifest_name);
        if (wxFileExists(manifest_name))
        {
            PluginManifest man(manifest_name.mbc_str());
            DownloadManifestBitmaps(&man);
        }
    }
}

void piman_pi::DownloadManifestBitmaps(PluginManifest* manifest)
{
    if (!m_bDownloadPictures)
        return;
    //TODO: Maybe not if they already exist? But then how will we know that the author wants to update them? And do we care?
    wxString picture;
    picture = wxFileName(m_data_dir, wxString::Format(_T("%s.icon.png"), manifest->GetName().c_str())).GetFullPath();
    DownloadFile(manifest->GetIconUrl(), picture);
    picture = wxFileName(m_data_dir, wxString::Format(_T("%s.ss.png"), manifest->GetName().c_str())).GetFullPath();
    DownloadFile(manifest->GetScreenshotUrl(), picture);
}

wxImage* piman_pi::GetPluginIcon(PluginManifest* manifest)
{
    wxString picture;
    picture = wxFileName(m_data_dir, wxString::Format(_T("%s.icon.png"), manifest->GetName().c_str())).GetFullPath();
    if ( wxFileExists(picture) );
        return new wxImage(picture);
    return NULL;
}

wxImage* piman_pi::GetPluginScreenshot(PluginManifest* manifest)
{
    wxString picture;
    picture = wxFileName(m_data_dir, wxString::Format(_T("%s.ss.png"), manifest->GetName().c_str())).GetFullPath();
    if ( wxFileExists(picture) );
        return new wxImage(picture);
    return NULL;
}

void piman_pi::DownloadManifestList()
{
    if (DownloadFile(m_manifestListUrl, m_cached_manifest_list))
    {
        m_iLastUpdate = wxDateTime::Now().GetTicks();
        SaveConfig();
        ApplyConfig();
    }
}

void piman_pi::ApplyConfig(void)
{
    m_pPimanDlg->ClearDialog();
    for(std::vector<PluginManifest>::iterator it = m_plugin_manifests.begin(); it != m_plugin_manifests.end(); ++it)
    {
        if ((&*it)->IsAvailableForPlatform(PLATFORM_ID) && (&*it)->IsAvailableForAPILevel(GetCoreAPIVersionMajor(), GetCoreAPIVersionMinor()))
            m_pPimanDlg->AddPlugin(&*it);
    }
    m_pPimanDlg->SetLastUpdate(m_iLastUpdate);
    m_pPimanDlg->SetNrToInstall(0);
    m_pPimanDlg->SetSizeToDownload(0);
}

bool piman_pi::DeInit ( void )
{
    SaveConfig();
    m_pPimanDlg->Close(true);
    m_pPimanDlg->Destroy();
    m_pSettingsDlg->Close(true);
    m_pSettingsDlg->Destroy();
    return true;
}

int piman_pi::GetAPIVersionMajor()
{
    return MY_API_VERSION_MAJOR;
}

int piman_pi::GetAPIVersionMinor()
{
    return MY_API_VERSION_MINOR;
}

int piman_pi::GetPlugInVersionMajor()
{
    return PLUGIN_VERSION_MAJOR;
}

int piman_pi::GetPlugInVersionMinor()
{
    return PLUGIN_VERSION_MINOR;
}

wxBitmap *piman_pi::GetPlugInBitmap()
{
    return _img_piman_pi;
}

wxString piman_pi::GetCommonName()
{
    return _T ( "PiMan" );
}

wxString piman_pi::GetShortDescription()
{
    return _ ( "Plug-in Manager PlugIn for OpenCPN" );
}


wxString piman_pi::GetLongDescription()
{
    return _ ( "Plug-in Manager PlugIn for OpenCPN\n\
Provides management of plug-ins." );
}

int piman_pi::GetToolbarToolCount ( void )
{
    return 1;
}

int piman_pi::GetTransferStyle()
{
    int ret = 0;

    ret |= wxCTDS_ELAPSED_TIME;
    ret |= wxCTDS_ESTIMATED_TIME;
    ret |= wxCTDS_REMAINING_TIME;
    ret |= wxCTDS_SPEED;
    ret |= wxCTDS_SIZE;
    ret |= wxCTDS_URL;
    //ret |= wxCTDS_CONN_SETTINGS_AUTH;
    //ret |= wxCTDS_CONN_SETTINGS_PORT;
    //ret |= wxCTDS_CONN_SETTINGS_PROXY;
    //ret |= wxCTDS_CAN_ABORT;
    //ret |= wxCTDS_CAN_START;
    //ret |= wxCTDS_CAN_PAUSE;
    ret |= wxCTDS_AUTO_CLOSE;

    return ret;
}

bool piman_pi::DownloadWithDialog(const wxString url, const wxString local_file)
{
    /*
    wxString extension = url.AfterLast('.');
    if (extension.length() >= 2 || extension.length() <= 4)
        extension = wxS(".") + extension;
    else
        extension = wxEmptyString;
    */
    wxBitmap bmp;

    wxFileOutputStream fos(local_file);
    wxCurlDownloadDialog dlg(url, &fos,
                             _("Downloading..."),
                             _("File is being downloaded...\nIt may take quite some time depending on your connection."),
                             bmp,
                             m_parent_window,
                             GetTransferStyle());
    dlg.SetVerbose(true);

    if (!dlg.IsOk())
        return false;

    wxCurlDialogReturnFlag flag = dlg.RunModal();

    if (flag == wxCDRF_SUCCESS)
    {
        fos.Close();
        return true;
/*
        int reply = wxMessageBox(wxS("Do you want to open the downloaded file with your default browser?"),
                                 wxS("Open it?"), wxYES_NO, m_parent_window);
        if (reply == wxYES)
            wxLaunchDefaultBrowser(wxS("downloaded_stuff") + extension);
*/
    }
    else
    {
        return false;
    }
}

void piman_pi::DownloadManifestDataFiles(PluginManifest* manifest, std::vector<std::string> selected_urls)
{
    bool download_ok = true;
    wxString local_name, url, file;
    wxString plugin_dir = m_plugins_dir;
    plugin_dir.Append(wxFileName::GetPathSeparator()).Append(manifest->GetName());
    if (!wxDirExists(plugin_dir))
        download_ok = wxMkdir(plugin_dir);
    std::vector<wxString> files;
    std::vector<std::string> postinst_actions;
    std::vector<CommonData> common_data = manifest->GetCommonData();
    for(std::vector<CommonData>::iterator it = common_data.begin(); it != common_data.end(); ++it)
    {
        if(download_ok && (selected_urls.empty() || std::find(selected_urls.begin(), selected_urls.end(), std::string(it->GetUrl().mb_str())) != selected_urls.end()))
        {
            url = it->GetUrl();
            file = url.AfterLast('/');
            local_name = plugin_dir;
            local_name.Append(wxFileName::GetPathSeparator()).Append(file);
            download_ok &= DownloadFile(url, local_name);
            if (download_ok && wxMD5::GetFileMD5(local_name) != it->GetChecksum())
            {
                download_ok = false;
                wxRemoveFile(local_name);
            }
            else
                files.push_back(local_name);
        }
    }
    
    std::vector<PlatformData> platform_data = manifest->GetPlatformData();
    for(std::vector<PlatformData>::iterator it = platform_data.begin(); it != platform_data.end(); ++it)
    {
        if(download_ok && (selected_urls.empty() || std::find(selected_urls.begin(), selected_urls.end(), std::string(it->GetUrl().mb_str())) != selected_urls.end()))
        {
            if (PLATFORM_ID == it->GetPlatform())
            {
                url = it->GetUrl();
                file = url.AfterLast('/');
                local_name = plugin_dir;
                local_name.Append(wxFileName::GetPathSeparator()).Append(file);
                download_ok &= DownloadFile(url, local_name);
                if (download_ok && wxMD5::GetFileMD5(local_name) != it->GetChecksum())
                {
                    download_ok = false;
                    wxRemoveFile(local_name);
                }
                else
                {
                    files.push_back(local_name);
                    std::vector<std::string> actions = it->GetPostInstActions();
                    if (!actions.empty())
                        postinst_actions.insert(postinst_actions.end(), actions.begin(), actions.end());
                }
            }
        }
    }
    if (download_ok)
    {
        for(std::vector<wxString>::iterator it = files.begin(); it != files.end(); ++it)
        {
            if (!download_ok)
                break;
            download_ok &= DecompressFile(*it, plugin_dir);
        }
    }
    if (download_ok && !postinst_actions.empty())
    {
        for(std::vector<std::string>::iterator it = postinst_actions.begin(); it != postinst_actions.end(); ++it)
        {
            wxString cmd = wxString::FromUTF8(it->c_str());
            if (cmd != wxEmptyString)
            {
                wxSetWorkingDirectory(plugin_dir);
                wxExecute(cmd);
                //TODO: should we check the results? Should we execute ASYNC or SYNC?
            }
        }
    }
    //TODO: Should we do some more cleanup if something failed? Should we keep backup of the previous version?
    for(std::vector<wxString>::iterator it = files.begin(); it != files.end(); ++it)
        wxRemoveFile(*it);
}

bool piman_pi::DecompressFile(const wxString tarxz_name, wxString target_path)
{
    bool res = true;
    Xz xz;
    wxString tmp_file = wxGetTempFileName(_T("piman_pi"));
    res = xz.Decompress(tarxz_name, tmp_file);
    if (res)
    {
        std::auto_ptr<wxTarEntry> entry;
        wxFFileInputStream in(tmp_file);
        wxTarInputStream tar(in);
        while (res && (entry.reset(tar.GetNextEntry()), entry.get() != NULL))
        {
            wxString fn = entry->GetName();
            wxString name = target_path.Append(wxFileName::GetPathSeparator()).Append(fn);
            
            wxString outputdir = wxFileName(name).GetPath();
            if (!wxDirExists(outputdir))
                wxFileName(outputdir).Mkdir(0777, wxPATH_MKDIR_FULL);
            
            wxFileOutputStream out(name);
            res = out.IsOk();
            if (res)
                out.Write(tar);
            out.Close();
        }
    }
    
    if (wxFileExists(tmp_file))
        wxRemoveFile(tmp_file);
    return res;
}

void piman_pi::OnToolbarToolCallback ( int id )
{
    ApplyConfig();
    m_pPimanDlg->ShowModal();
    /*
    DownloadManifestList();
    m_manifest_list.Load(m_cached_manifest_list.mb_str());
    DownloadManifests();
    LoadManifestsFromDisk();
    for(std::vector<PluginManifest>::iterator it = m_plugin_manifests.begin(); it != m_plugin_manifests.end(); ++it)
    {
        DownloadManifestBitmaps(&*it);
        DownloadManifestDataFiles(&*it, std::vector<std::string>());
    }
    */
}

bool piman_pi::LoadConfig ( void )
{
    wxFileConfig *pConf = ( wxFileConfig * ) m_pconfig;

    if ( !pConf )
        return false;

    pConf->SetPath ( _T ( "/PlugIns/PIMAN" ) );
    pConf->Read( _T( "WindowWidth" ), &m_iWindowWidth, DEFAULT_WIDTH );
    pConf->Read( _T( "WindowHeight" ), &m_iWindowHeight, DEFAULT_HEIGHT );
    pConf->Read( _T( "LastUpdate" ), &m_iLastUpdate, 0 );
    pConf->Read( _T( "ManifestListUrl" ), &m_manifestListUrl, DEFAULT_MANIFESTLISTURL );
    pConf->Read( _T( "CheckAtStartup" ), &m_bCheckAtStartup, false );
    pConf->Read( _T( "CheckAtStartupInterval" ), &m_iCheckAtStartupInterval, 30 );
    pConf->Read( _T( "DownloadPictures" ), &m_bDownloadPictures, true );
    pConf->Read( _T( "AutoUpdate" ), &m_bAutoUpdate, true );
    pConf->Read( _T( "AutotUpdateBlacklist" ), &m_autoUpdateBlacklist, wxEmptyString );

    return true;
}

bool piman_pi::SaveConfig ( void )
{
    wxFileConfig *pConf = ( wxFileConfig * ) m_pconfig;

    if ( !pConf )
        return false;

    pConf->SetPath ( _T ( "/PlugIns/PIMAN" ) );
    pConf->Write( _T( "WindowWidth" ), m_iWindowWidth );
    pConf->Write( _T( "WindowHeight" ), m_iWindowHeight );
    pConf->Write( _T( "LastUpdate" ), m_iLastUpdate );
    pConf->Write( _T( "ManifestListUrl" ), m_manifestListUrl );
    pConf->Write( _T( "CheckAtStartup" ), m_bCheckAtStartup );
    pConf->Write( _T( "CheckAtStartupInterval" ), m_iCheckAtStartupInterval );
    pConf->Write( _T( "DownloadPictures" ), m_bDownloadPictures );
    pConf->Write( _T( "AutoUpdate" ), m_bAutoUpdate );
    pConf->Write( _T( "AutotUpdateBlacklist" ), m_autoUpdateBlacklist );

    return true;
}

void piman_pi::SetColorScheme ( PI_ColorScheme cs )
{
}

void piman_pi::ShowPreferencesDialog( wxWindow* parent )
{
    m_pSettingsDlg->m_cbAutoUpdate->SetValue(m_bAutoUpdate);
    m_pSettingsDlg->m_cbDownloadPictures->SetValue(m_bDownloadPictures);
    m_pSettingsDlg->m_cbStartupCheck->SetValue(m_bCheckAtStartup);
    m_pSettingsDlg->m_stDays->Enable(m_bAutoUpdate);
    m_pSettingsDlg->m_stEvery->Enable(m_bAutoUpdate);
    m_pSettingsDlg->m_spStartupCheckPeriod->Enable(m_bAutoUpdate);
    m_pSettingsDlg->m_spStartupCheckPeriod->SetValue(m_iCheckAtStartupInterval);    
    m_pSettingsDlg->m_tPluginListUrl->SetValue(m_manifestListUrl);
    //TODO: Blacklist
    
    m_pSettingsDlg->Fit();
    if(m_pSettingsDlg->ShowModal() == wxID_OK)
    {
        m_bAutoUpdate = m_pSettingsDlg->m_cbAutoUpdate->GetValue();
        m_bDownloadPictures = m_pSettingsDlg->m_cbDownloadPictures->GetValue();
        m_bCheckAtStartup = m_pSettingsDlg->m_cbStartupCheck->GetValue();
        m_iCheckAtStartupInterval = m_pSettingsDlg->m_spStartupCheckPeriod->GetValue();
        m_manifestListUrl = m_pSettingsDlg->m_tPluginListUrl->GetValue();
        //TODO: Blacklist

        SaveConfig();
    }
}

void piman_pi::PurgeCachedData()
{
    wxString path(m_data_dir);
 	if ( path.Last() != wxFILE_SEP_PATH ) 
        path += wxFILE_SEP_PATH;
    wxDir d(path); 
    // delete all filles 
    wxString filename;
    bool cont = d.GetFirst(&filename, wxEmptyString, wxDIR_FILES | wxDIR_HIDDEN); 
    while ( cont ) 
    { 
        ::wxRemoveFile(path + filename); 
        cont = d.GetNext(&filename); 
    } 
}

wxString piman_pi::GetInstalledVersionString(wxString pi_name)
{
    ArrayOfPI_Plugins* pis =  GetInstalledPlugins();
    for (size_t i = 0; i < pis->GetCount(); i++)
    {
        PI_Plugin *p = pis->Item(i);
        if (p->Name == pi_name)
            return wxString::Format(_T("%i.%i"), p->VersionMajor, p->VersionMinor);
    }
    return _("None");
}

int piman_pi::GetInstalledVersionMajor(wxString pi_name)
{
    ArrayOfPI_Plugins* pis =  GetInstalledPlugins();
    for (size_t i = 0; i < pis->GetCount(); i++)
    {
        PI_Plugin *p = pis->Item(i);
        if (p->Name == pi_name)
            return p->VersionMajor;
    }
    return -1;
}

int piman_pi::GetInstalledVersionMinor(wxString pi_name)
{
    ArrayOfPI_Plugins* pis =  GetInstalledPlugins();
    for (size_t i = 0; i < pis->GetCount(); i++)
    {
        PI_Plugin *p = pis->Item(i);
        if (p->Name == pi_name)
            return p->VersionMinor;
    }
    return -1;
}
