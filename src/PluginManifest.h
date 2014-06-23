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

#ifndef _PLUGINMANIFEST_H_
#define _PLUGINMANIFEST_H_

#include "wx/wxprec.h"

#ifndef  WX_PRECOMP
#include "wx/wx.h"
#endif //precompiled headers

#include "pugixml.hpp"
#include <string>
#include <vector>
 
enum DependencyType
{
    Recommended,
    Required,
    InvalidDependencyType = -1
};

enum Platform
{
    Windows,
    Linux32,
    Linux64,
    Mac,
    LinuxArmHf,
    InvalidPlatform = -1
};

class Dependency
{
public:
    Dependency(pugi::xml_node* node);
    static DependencyType AttrValToDependencyType(std::string val);
    const DependencyType GetDependencyType() { return type; }
    const wxString GetName() { return wxString::FromUTF8(dependency_name.c_str()); }

private:
    std::string dependency_name;
    
    DependencyType type;

    /**
     * Minimal required major version of the dependency
     */
    int minimal_version_major;
    /**
     * Minimal required minor version of the dependency
     */
    int minimal_version_minor;
};

class CommonData
{
public:
    CommonData(pugi::xml_node* node);
    
    const wxString GetUrl() { return wxString::FromUTF8(url.c_str()); }
    const int GetSize() { return size; }
    const wxString GetChecksum() { return wxString::FromUTF8(checksum.c_str()); }
    const wxString GetDescription();
    const wxString GetPostInstallMsg() { return wxString::FromUTF8(post_install_message.c_str()); }
    const DependencyType GetDependencyType() { return type; }

private:
    std::string url;
    int size;
    std::string checksum;
    std::string description;
    std::string post_install_message;
    DependencyType type;
};

class PlatformData : public CommonData
{
public:
    PlatformData(pugi::xml_node* node);
    static Platform AttrValToPlatform(std::string val);
    
    const Platform GetPlatform() { return platform; }
    const std::vector<std::string> GetPostInstActions() { return post_install_actions; }
    
private:
    Platform platform;
    
    std::vector<std::string> post_install_actions;
};

class PluginManifest
{
public:
    PluginManifest(const char* XmlFile);
    void Load(pugi::xml_document* doc);
    
    int GetVersion() { return version; }
    const wxString GetName() { return wxString::FromUTF8(name.c_str()); }
    const wxString GetIconUrl() { return wxString::FromUTF8(icon_url.c_str()); }
    const wxString GetScreenshotUrl() { return wxString::FromUTF8(screenshot_url.c_str()); }
    const wxString GetHomepageUrl() { return wxString::FromUTF8(homepage_url.c_str()); }
    const wxString GetAuthor() { return wxString::FromUTF8(author.c_str()); }
    const wxString GetReleaseDate() { return wxString::FromUTF8(release_date.c_str()); }
    const wxString GetPluginVerboseName() { return wxString::FromUTF8(plugin_name.c_str()); }
    const wxString GetPluginDescription() { return wxString::FromUTF8(plugin_description.c_str()); }
    const int GetVersionMajor() { return version_major; }
    const int GetVersionMinor() { return version_minor; }
    const wxString GetVersionString() { return wxString::Format(_T("%i.%i"), version_major, version_minor); }
    const int GetAPIMajor() { return api_level_major; }
    const int GetAPIMinor() { return api_level_minor; }
    std::vector<CommonData> GetCommonData() { return common_data; }
    std::vector<PlatformData> GetPlatformData() { return platform_data; }
    std::vector<Dependency> GetDependencies() { return dependencies; }
    
    bool IsAvailableForPlatform(Platform platform);

private:
    int version;
    
    std::string name;
    std::string icon_url;
    std::string screenshot_url;
    std::string homepage_url;
    std::string author;
    std::string release_date;
    int version_major;
    int version_minor;
    int api_level_major;
    int api_level_minor;
    
    std::string plugin_name;
    std::string plugin_description;
    
    std::vector<CommonData> common_data;
    std::vector<PlatformData> platform_data;
    
    std::vector<Dependency> dependencies;
};

#endif
