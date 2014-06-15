#Plug-in Manager for OpenCPN
This plug-in provides management capabilities to keep other plug-ins up to date.
It is strongly recommended that you clean the manually installed plug-ins in /usr/[local]/lib/opencpn or C:\Program Files\opencpn\plugins before starting to use the manager to avoid unexpected behaviour.

##The data model
The piman_pi.vpp file is a UML model created using Visual Paradigm (http://www.visual-paradigm.com/)

##The GUI prototype
The piman_pi.fbp file used to generate gui.h and gui.cpp is created in wxFormBuilder (http://sourceforge.net/projects/wxformbuilder/)

##Building
This assumes you have already seen the building instructions at http://opencpn.org/ocpn/compiling_source_linux or http://opencpn.org/ocpn/compiling_source_windows and can build OpenCPN from source.

###Linux:
```
sudo apt-get install libcurl4-dev liblzma-dev

cd YOUROPENCPNSOURCETREE/plugins
git clone git clone https://github.com/nohal/piman_pi.git
cd ../build
cmake ..
make
```
###Windows:
The build is sure broken because of the missing dependencies not handled at all by the configuration process. Porting is the main point on the TODO after the complete functionality is in place.
```
cd C:\YOUROPENCPNSOURCETREE\plugins
git clone git clone https://github.com/nohal/piman_pi.git
cd ..\build
cmake ..
cmake --build . --config release
```
###Mac OS X
The build has never been tried. Porting is the main point on the TODO after the complete functionality is in place.

Icon made by Freepik from Flaticon.com

##Implementation notes
To check the validity of the manifest: xmllint --schema OpenCPNPluginManager.PluginManifest.xsd manifest.xml

The one and only supported package format is tar.xz
The plug-in files are isolated under ${OPENCPN_DATA}/plugins/${plugin_pi} folder, no paths in the archive are honored.

The one and only supported image format for icons and screenshots is PNG

The manifest is stored when a plug-in is installed/updated. TODO: When a new version arrives, the checksums of the files with same URL are compared and in case of a match the file is not downloaded/installed to save bandwidth (typically good for data files).

TODO: If a dependency is not met, it is not possible to install/update the plug-in. The reason for that is that the PostInstall actions could depend on tools installed with other plug-in.
