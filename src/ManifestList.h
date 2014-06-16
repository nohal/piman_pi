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
#ifndef _MANIFESTLIST_H_
#define _MANIFESTLIST_H_

#include "wx/wxprec.h"

#ifndef  WX_PRECOMP
#include "wx/wx.h"
#endif //precompiled headers

#include "pugixml.hpp"
#include <string>
#include <vector>

class Manifest
{
public:
    Manifest(pugi::xml_node* manifest);
    
    const wxString GetName() { return wxString::FromUTF8(name.c_str()); }
    const wxString GetUrl() { return wxString::FromUTF8(url.c_str()); }
    
private:
    std::string name;
    std::string url;
};

class ManifestList
{
public:
    std::vector<Manifest> Manifests;
    
    ManifestList() {}
    ManifestList(const char* XmlFile);
    
    void Load (const char* XmlFile);
    void Load(pugi::xml_document* doc);
    
    int GetVersion() { return version; }

private:
    int version;
};

#endif
