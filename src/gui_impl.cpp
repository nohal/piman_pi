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

PluginMgrDlgImpl::PluginMgrDlgImpl( piman_pi* pi, wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : PluginMgrDlg( parent, id, title, pos, size, style )
{
    p_plugin = pi;
}

PluginMgrDlgImpl::~PluginMgrDlgImpl()
{
}

PluginPanelImpl::PluginPanelImpl( PluginManifest* manifest, wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : PluginPanel( parent, id, pos, size, style )
{
    p_manifest = manifest;
}

PluginPanelImpl::~PluginPanelImpl()
{
}
