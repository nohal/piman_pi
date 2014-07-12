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
 
#ifndef __GUI_IMPL_H__
#define __GUI_IMPL_H__

#include "gui.h"
#include <wx/statline.h>
#include "PluginManifest.h"
#include <algorithm>

class piman_pi;

class PluginMgrDlgImpl : public PluginMgrDlg 
{
private:
    piman_pi *p_plugin;
    size_t m_iUpdatesAvaliable;
    size_t m_iDownloadSize;
    size_t m_iToInstall;
    std::vector<wxString> m_plugins_to_install;
    std::vector<std::string> m_urls_to_install;

protected:
    virtual void OnRefresh( wxCommandEvent& event );
    virtual void OnInstall( wxCommandEvent& event );
    virtual void OnClose( wxCommandEvent& event );

public:
    PluginMgrDlgImpl( piman_pi* pi, wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Plug-in Manager"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 620,450 ), long style = wxDEFAULT_DIALOG_STYLE ); 
    ~PluginMgrDlgImpl();
    void AddPlugin( PluginManifest* manifest );
    void ClearDialog();
    void SetLastUpdate( time_t last_update ) { m_stLastUpdateVal->SetLabel(wxDateTime(last_update).FormatDate()); }
    void SetNrUpdatesAvailable( size_t updates ) { m_stUpdatesAvailableVal->SetLabel(wxString::Format(_T("%i"), updates)); }
    void SetNrToInstall( size_t updates ) { m_stToDownloadVal->SetLabel(wxString::Format(_T("%i"), updates)); }
    void SetSizeToDownload( size_t size_bytes ) { m_stToDownloadVal->SetLabel(wxString::Format(_T("%i kB"), size_bytes / 1024)); }
    void AddDownload( int size, const wxString plugin_name, const wxString url = wxEmptyString );
    void RemoveDownload( int size, const wxString plugin_name, const wxString url = wxEmptyString );
    void UpdateDownloads();
};

class PluginPanelImpl : public PluginPanel
{
private:
    PluginManifest *p_manifest;
    piman_pi* p_pi;
    size_t m_iTotalSize;
    PluginMgrDlgImpl* p_parent_dlg;
    wxString m_pluginName;
    
    void UpdateSizes();

protected:
    virtual void OnCheckInstall( wxCommandEvent& event );
    virtual void OnCheckInstallComponent( wxCommandEvent& event );
    virtual void OnUninstall( wxCommandEvent& event );

public:
    PluginPanelImpl( piman_pi* pi, PluginManifest* manifest, PluginMgrDlgImpl* dlg, wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 558,394 ), long style = wxTAB_TRAVERSAL ); 
    ~PluginPanelImpl();
    PluginManifest *GetManifest() { return p_manifest; }
};

class PimanSettingsDlgImpl : public PimanSettingsDlg
{
friend class piman_pi;

private:
    piman_pi* p_pi;

protected:
    virtual void OnCheckAtStartupCheck( wxCommandEvent& event );
    virtual void OnPurgeData();
    
public:
    PimanSettingsDlgImpl( piman_pi* pi, wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Plug-in Manager"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 620,450 ), long style = wxDEFAULT_DIALOG_STYLE ); 
    ~PimanSettingsDlgImpl();
};

class DataCheckbox : public wxCheckBox
{
    public:
        DataCheckbox( CommonData* data, wxWindow* parent, wxWindowID id, const wxString& label, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = 0, const wxValidator& validator = wxDefaultValidator, const wxString& name = wxCheckBoxNameStr );
        ~DataCheckbox() {;}
        int GetDownloadSize() { return m_iSize; }
    private:
        int m_iSize;
};

#endif
