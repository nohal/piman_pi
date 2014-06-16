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

#include "ManifestList.h"

Manifest::Manifest(pugi::xml_node* manifest)
{
    name = manifest->attribute("Name").as_string();
    url = manifest->attribute("Url").as_string();
}

ManifestList::ManifestList(const char* XmlFile)
{
    Load(XmlFile);
}

void ManifestList::Load(const char* XmlFile)
{
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file(XmlFile);
    if (result)
        Load(&doc);
}

void ManifestList::Load(pugi::xml_document* doc)
{
    pugi::xml_node plugin_list = doc->child("ManifestList");
    version = plugin_list.attribute("Version").as_int();
    for (pugi::xml_node plugin = plugin_list.child("Manifest"); plugin; plugin = plugin.next_sibling("Manifest"))
    {
        Manifests.push_back(Manifest(&plugin));
    }
}
