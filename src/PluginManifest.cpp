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

#include "PluginManifest.h"

CommonData::CommonData(pugi::xml_node* node)
{
    url = node->attribute("Url").as_string();
    size = node->attribute("Size").as_int();
    checksum = node->attribute("Checksum").as_string();
    description = node->attribute("Description").as_string();
    post_install_message = node->child("PostInstallMessage").text().as_string();
    type = Dependency::AttrValToDependencyType(node->attribute("Type").as_string());
}

Platform PlatformData::AttrValToPlatform(std::string val)
{
    if (val == "Linux32")
        return Linux32;
    else if (val == "Linux64")
        return Linux64;
    else if (val == "LinuxArmHf")
        return LinuxArmHf;
    else if (val == "Mac")
        return Mac;
    else if (val == "Windows")
        return Windows;
    else
        return InvalidPlatform;
}

PlatformData::PlatformData(pugi::xml_node* node) : CommonData(node)
{
    platform = PlatformData::AttrValToPlatform(node->attribute("Platform").as_string());
    for (pugi::xml_node pia = node->child("PostInstallAction"); pia; pia = pia.next_sibling("PostInstallAction"))
        post_install_actions.push_back(pia.text().as_string());
}

DependencyType Dependency::AttrValToDependencyType(std::string val)
{
    if (val == "Recommended")
        return Recommended;
    else if (val == "Required")
        return Required;
    else
        return InvalidDependencyType;
}

Dependency::Dependency(pugi::xml_node* node)
{
    dependency_name = node->attribute("Plugin").as_string();
    
    type = Dependency::AttrValToDependencyType(node->attribute("Type").as_string());

    minimal_version_major = node->attribute("MinimalVersionMajor").as_int();
    minimal_version_minor = node->attribute("MinimalVersionMinor").as_int();
}

PluginManifest::PluginManifest(const char* XmlFile)
{
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file(XmlFile);
    if (result)
        Load(&doc);
}
    
void PluginManifest::Load(pugi::xml_document* doc)
{
    pugi::xml_node manifest = doc->child("PluginManifest");
    
    version = manifest.attribute("Version").as_int();
    name = manifest.attribute("Name").as_string();
    icon_url = manifest.attribute("IconUrl").as_string();
    screenshot_url = manifest.attribute("ScreenshotUrl").as_string();
    homepage_url = manifest.attribute("HomepageUrl").as_string();
    author = manifest.attribute("Author").as_string();
    release_date = manifest.attribute("ReleaseDate").as_string();
    version_major = manifest.attribute("VersionMajor").as_int();
    version_minor = manifest.attribute("VersionMinor").as_int();
    api_level_major = manifest.attribute("APILevelMajor").as_int();
    api_level_minor = manifest.attribute("APILevelMinor").as_int();
    
    plugin_name = manifest.child("PluginName").text().as_string();
    plugin_description = manifest.child("Description").text().as_string();
    
    for (pugi::xml_node node = manifest.child("CommonData"); node; node = node.next_sibling("CommonData"))
    {
        common_data.push_back(CommonData(&node));
    }
    
    for (pugi::xml_node node = manifest.child("PlatformData"); node; node = node.next_sibling("PlatformData"))
    {
        platform_data.push_back(PlatformData(&node));
    }
    
    for (pugi::xml_node node = manifest.child("Dependency"); node; node = node.next_sibling("Dependency"))
    {
        dependencies.push_back(Dependency(&node));
    }
}

bool PluginManifest::IsAvailableForPlatform(Platform platform)
{
    for(std::vector<PlatformData>::iterator it = platform_data.begin(); it != platform_data.end(); ++it)
    {
        if(it->GetPlatform() == platform)
            return true;
    }
    return false;
}
