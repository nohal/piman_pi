#!/bin/bash

if [ $# -ne 1 ]; then
    echo "Validates the supplied manifest agains the XML Schema."
    echo "Usage: #@ <Manifest XML file>"
    exit 1
fi

xmllint --noout --schema OpenCPNPluginManager.PluginManifest.xsd $1
