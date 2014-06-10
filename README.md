#Plug-in Manager for OpenCPN
This plug-in provides management capabilities to keep other plug-ins up to date.
It is strongly recommended that you clean the manually installed plug-ins in /usr/[local]/lib/opencpn or C:\Program Files\opencpn\plugins before starting to use the manager to avoid unexpected behaviour.

##Building
This assumes you have already seen the building instructions at http://opencpn.org/ocpn/compiling_source_linux or http://opencpn.org/ocpn/compiling_source_windows and can build OpenCPN from source.

###Linux:
```
cd YOUROPENCPNSOURCETREE/plugins
git clone git clone https://github.com/nohal/piman_pi.git
cd ../build
cmake ..
make
```
###Windows:
```
cd C:\YOUROPENCPNSOURCETREE\plugins
git clone git clone https://github.com/nohal/piman_pi.git
cd ..\build
cmake ..
cmake --build . --config release
```

Icon made by Freepik from Flaticon.com
