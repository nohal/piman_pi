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

#include "gui_impl.h"
#include "piman_pi.h"

PluginMgrDlgImpl::PluginMgrDlgImpl( piman_pi* pi, wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : PluginMgrDlg( parent, id, title, pos, size, style )
{
    p_plugin = pi;
    m_iUpdatesAvaliable = 0;
    m_iDownloadSize = 0;
    m_iToInstall = 0;
    UpdateDownloads();
}

void PluginMgrDlgImpl::UpdateDownloads()
{
    m_stToInstallVal->SetLabel(wxString::Format(_T("%i"), m_iToInstall));
    m_stToDownloadVal->SetLabel(wxString::Format(_T("%i kB"), m_iDownloadSize / 1024));
    if ( m_iToInstall > 0 )
        m_btnInstall->Enable();
    else
        m_btnInstall->Disable();
}

void PluginMgrDlgImpl::OnRefresh( wxCommandEvent& event )
{
    p_plugin->UpdateManifestsFromNet();
    event.Skip();
}

void PluginMgrDlgImpl::OnInstall( wxCommandEvent& event )
{
    
    p_plugin->DownloadManifestDataFiles(PluginManifest, url)
    event.Skip();
}

void PluginMgrDlgImpl::OnClose( wxCommandEvent& event )
{
    this->Close(); 
    event.Skip();
}

PluginMgrDlgImpl::~PluginMgrDlgImpl()
{
}

void PluginMgrDlgImpl::AddPlugin( PluginManifest* manifest )
{
    PluginPanelImpl* newpanel = new PluginPanelImpl(p_plugin, manifest, this, m_swPlugins);
	bSizerPlugins->Add( newpanel, 0, wxEXPAND | wxALL, 5 );
	
	wxStaticLine* staticline = new wxStaticLine( m_swPlugins, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizerPlugins->Add( staticline, 0, wxEXPAND | wxALL, 5 );
	
	bSizerPlugins->FitInside(m_swPlugins);
}

void PluginMgrDlgImpl::ClearDialog()
{
    bSizerPlugins->Clear(true);
    m_iUpdatesAvaliable = 0;
    m_iDownloadSize = 0;
    m_iToInstall = 0;
    UpdateDownloads();
}

PluginPanelImpl::PluginPanelImpl( piman_pi* pi, PluginManifest* manifest, PluginMgrDlgImpl* dlg, wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : PluginPanel( parent, id, pos, size, style )
{
    p_manifest = manifest;
    p_pi = pi;
    m_iTotalSize = 0;
    p_parent_dlg = dlg;
    
    if ( p_manifest->GetAuthor() != wxEmptyString )
        m_stAuthor->SetLabel(_("by ") + p_manifest->GetAuthor());
    else
        m_stAuthor->Hide();
    m_stDescription->SetLabel(p_manifest->GetPluginDescription());
    m_stPluginName->SetLabel(p_manifest->GetPluginVerboseName());
    m_stVerAvailable->SetLabel(p_manifest->GetVersionString());
    m_stVerInstalled->SetLabel(p_pi->GetInstalledVersionString(p_manifest->GetName()));
    if ( p_manifest->GetHomepageUrl() != wxEmptyString )
    {
        m_hlnkWebsite->SetURL(p_manifest->GetHomepageUrl());
        m_hlnkWebsite->SetLabel(_("Website"));
    }
    else
        m_hlnkWebsite->Hide();
    std::vector<Dependency> deps = p_manifest->GetDependencies();
    bool has_deps, has_recs = false;
    wxString depstxt, recstxt = wxEmptyString;
    for( std::vector<Dependency>::iterator it = deps.begin(); it != deps.end(); ++it )
    {
        if( (&*it)->GetDependencyType() == Required )
        {
            if (has_deps)
                depstxt.Append(_T("\n"));
            depstxt.Append( (&*it)->GetName() );
            has_deps = true;
        }
        else
        {
            if (has_recs)
                recstxt.Append(_T("\n"));
            recstxt.Append((&*it)->GetName());
            has_recs = true;
        }
    }
    if ( !has_deps )
    {
        m_stDepValue->Hide();
        m_stDepends->Hide();
    }
    else
        m_stDepValue->SetLabel(depstxt);
    if ( !has_recs )
    {
        m_stRecValue->Hide();
        m_stRecommends->Hide();
    }
    else
        m_stRecValue->SetLabel(recstxt);

    std::vector<CommonData> components = p_manifest->GetCommonData();
    for( std::vector<CommonData>::iterator it = components.begin(); it != components.end(); ++it )
    {
        DataCheckbox* cb = new DataCheckbox( &*it, this, wxID_ANY, wxString::Format(_T("%s (%i kB)"), (&*it)->GetDescription().c_str(), (&*it)->GetSize() / 1024) );
        cb->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( PluginPanelImpl::OnCheckInstallComponent ), NULL, this );
        if( (&*it)->GetDependencyType() == Required )
        {
            cb->SetValue(true);
            cb->Disable();
            m_iTotalSize += cb->GetDownloadSize();
        }
        bSizerComponents->Add( cb, 0, wxLEFT, 15 );
    }
    
    std::vector<PlatformData> components1 = p_manifest->GetPlatformData();
    for( std::vector<PlatformData>::iterator it = components1.begin(); it != components1.end(); ++it )
    {
        if ( (&*it)->GetPlatform() == PLATFORM_ID )
        {
            DataCheckbox* cb = new DataCheckbox( &*it, this, wxID_ANY, wxString::Format(_T("%s (%i kB)"), (&*it)->GetDescription().c_str(), (&*it)->GetSize() / 1024) );
            cb->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( PluginPanelImpl::OnCheckInstallComponent ), NULL, this );
            if( (&*it)->GetDependencyType() == Required )
            {
                cb->SetValue(true);
                cb->Disable();
                m_iTotalSize += cb->GetDownloadSize();
            }
            bSizerComponents->Add( cb, 0, wxLEFT, 15 );
        }
    }
    
    UpdateSizes();
    
    //Pictures
    wxImage* img = p_pi->GetPluginIcon(p_manifest);
    if ( img )
        m_bmpIcon->SetBitmap(wxBitmap(*img));
    else
        m_bmpIcon->Hide();
    
    img = p_pi->GetPluginScreenshot(p_manifest);
    if ( img )
        m_bmpScreenshot->SetBitmap(wxBitmap(*img));
    else
        m_bmpScreenshot->Hide();
    
    m_btnUninstall->Show(p_pi->GetInstalledVersionMajor(p_manifest->GetName()) >= 0);
    
    Layout();
}

void PluginPanelImpl::UpdateSizes()
{
    m_cbInstall->SetLabel(wxString::Format(_("Install (Download size: %i kB)"), m_iTotalSize / 1024));
}

void PluginPanelImpl::OnCheckInstall( wxCommandEvent& event )
{
    if (m_cbInstall->GetValue())
        p_parent_dlg->AddDownload(m_iTotalSize);
    else
        p_parent_dlg->RemoveDownload(m_iTotalSize);
        
    p_parent_dlg->UpdateDownloads();
}

void PluginPanelImpl::OnCheckInstallComponent( wxCommandEvent& event )
{
    if (m_cbInstall->GetValue())
        p_parent_dlg->RemoveDownload(m_iTotalSize);
    DataCheckbox* cb = (DataCheckbox*)event.GetEventObject();
    if ( cb->GetValue() )
        m_iTotalSize += cb->GetDownloadSize();
    else
        m_iTotalSize -= cb->GetDownloadSize();
    UpdateSizes();
    if (m_cbInstall->GetValue())
        p_parent_dlg->AddDownload(m_iTotalSize);
    p_parent_dlg->UpdateDownloads();
    event.Skip( false );
}

PluginPanelImpl::~PluginPanelImpl()
{
    wxWindowList kids = GetChildren();
    for( unsigned int i = 0; i < kids.GetCount(); i++ ) {
        wxWindowListNode *node = kids.Item( i );
        wxWindow *win = node->GetData();

        if( win->IsKindOf( CLASSINFO(DataCheckbox) ) ) {
            ( (DataCheckbox*) win )->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( PluginPanelImpl::OnCheckInstallComponent ) );

        }
    }
}

PimanSettingsDlgImpl::PimanSettingsDlgImpl( piman_pi* pi, wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : PimanSettingsDlg( parent, id, title, pos, size, style )
{
    p_pi = pi;
}

PimanSettingsDlgImpl::~PimanSettingsDlgImpl()
{
}

void PimanSettingsDlgImpl::OnCheckAtStartupCheck( wxCommandEvent& event )
{
    m_stEvery->Enable(m_cbStartupCheck->GetValue());
    m_stDays->Enable(m_cbStartupCheck->GetValue());
    m_spStartupCheckPeriod->Enable(m_cbStartupCheck->GetValue());
    event.Skip();
}

void PimanSettingsDlgImpl::OnPurgeData()
{
    p_pi->PurgeCachedData();
}

DataCheckbox::DataCheckbox( CommonData* data, wxWindow* parent, wxWindowID id, const wxString& label, const wxPoint& pos, const wxSize& size, long style, const wxValidator& validator, const wxString& name ) : wxCheckBox ( parent, id, label, pos, size, style, validator, name )
{
    m_iSize = data->GetSize();
    if ( data->GetDependencyType() == Required )
    {
        SetValue(true);
        Enable(false);
    }
    else
    {
        SetValue(false);
        Enable(true);
    }
}
