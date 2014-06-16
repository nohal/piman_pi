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

#include "piman_pi.h"
#include "gui.h"

class PluginMgrDlgImpl : public PluginMgrDlg 
{
private:
    piman_pi *p_plugin;

protected:

public:
    
    PluginMgrDlgImpl( piman_pi* pi, wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Plugin Manager"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 641,490 ), long style = wxDEFAULT_DIALOG_STYLE ); 
    ~PluginMgrDlgImpl();
};

class PluginPanelImpl : public PluginPanel
{
private:
    PluginManifest *p_manifest;

protected:

public:
    PluginPanelImpl( PluginManifest* manifest, wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 558,394 ), long style = wxTAB_TRAVERSAL ); 
    ~PluginPanelImpl();
};

#endif
