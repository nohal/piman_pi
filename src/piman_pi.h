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

#ifndef _PIMANPI_H_
#define _PIMANPI_H_

#include "wx/wxprec.h"

#ifndef  WX_PRECOMP
#include "wx/wx.h"
#endif //precompiled headers

#include <map>
#include <queue>
#include <wx/fileconf.h>
//#include <wx/thread.h>
//#include <wx/event.h>

#include "wx/curl/http.h"
#include "xz.h"
#include "md5.h"
#include "ManifestList.h"
#include "PluginManifest.h"
#include "gui.h"
#include "gui_impl.h"

#include <vector>
#include <string>
#include <algorithm>
#include <auto_ptr.h>

#ifdef __WXGTK__
#ifdef ARMHF
#define PLATFORM_ID LinuxArmHf
#else
#include <limits.h>
#if ( __WORDSIZE == 64 )
#define PLATFORM_ID Linux64
#else
#define PLATFORM_ID Linux32
#endif
#endif
#else
#ifdef __WXMSW__
#define PLATFORM_ID Windows
#else
#ifdef __WXMAC__
#define PLATFORM_ID Mac
#endif
#endif
#endif

#define     PLUGIN_VERSION_MAJOR    0
#define     PLUGIN_VERSION_MINOR    1

#define     MY_API_VERSION_MAJOR    1
#define     MY_API_VERSION_MINOR    11

#include "../../../include/ocpn_plugin.h"

//----------------------------------------------------------------------------------------------------------
//    The PlugIn Class Definition
//----------------------------------------------------------------------------------------------------------

#define PIMAN_TOOL_POSITION    -1          // Request default positioning of toolbar tool
#define DEFAULT_WIDTH 600
#define DEFAULT_HEIGHT 550
#define DEFAULT_MANIFESTLISTURL _T("http://localhost/manifest_list.xml")

class piman_pi : public opencpn_plugin_111
{
public:
    piman_pi ( void *ppimgr );
    ~piman_pi ( void );

//    The required PlugIn Methods
    int Init ( void );
    bool DeInit ( void );

    int GetAPIVersionMajor();
    int GetAPIVersionMinor();
    int GetPlugInVersionMajor();
    int GetPlugInVersionMinor();
    wxBitmap *GetPlugInBitmap();
    wxString GetCommonName();
    wxString GetShortDescription();
    wxString GetLongDescription();
    wxImage* GetPluginIcon(PluginManifest* manifest);
    wxImage* GetPluginScreenshot(PluginManifest* manifest);
    void UpdateManifestsFromNet();

//    The override PlugIn Methods
    int GetToolbarToolCount ( void );
    void OnToolbarToolCallback ( int id );
    void ShowPreferencesDialog( wxWindow* parent );

// Other public methods
    void SetColorScheme ( PI_ColorScheme cs );
    
    wxString GetLastUpdateDate() { return wxDateTime(m_iLastUpdate).FormatDate(); }
    
private:
    bool LoadConfig ( void );
    bool SaveConfig ( void );
    void ApplyConfig( void );
    
    int GetTransferStyle();
    
    void DownloadManifestList();
    void LoadManifestsFromDisk();
    void DownloadManifests();
    bool DownloadFile(const wxString url, const wxString local_file);
    void DownloadManifestBitmaps(PluginManifest* manifest);
    bool DownloadWithDialog(const wxString url, const wxString local_file);
    void DownloadManifestDataFiles(PluginManifest* manifest, std::vector<std::string> selected_urls);
    bool DecompressFile(const wxString tarxz_name, wxString target_path);

    wxFileConfig *m_pconfig;
    wxWindow *m_parent_window;

    int m_display_width, m_display_height;
    int m_leftclick_tool_id;
    
    int m_iWindowWidth;
    int m_iWindowHeight;
    
    long m_iLastUpdate;
    wxString m_manifestListUrl;
    bool m_bCheckAtStartup;
    int m_iCheckAtStartupInterval;
    bool m_bDownloadPictures;
    bool m_bAutoUpdate;
    wxString m_autoUpdateBlacklist;
    
    ManifestList m_manifest_list;
    std::vector<PluginManifest> m_plugin_manifests;
    
    //Paths to cached data
    wxString m_data_dir;
    wxString m_plugins_dir;
    wxString m_cached_manifest_list;
    
    PluginMgrDlgImpl *m_pPimanDlg;
    PimanSettingsDlgImpl *m_pSettingsDlg;
};

#endif
