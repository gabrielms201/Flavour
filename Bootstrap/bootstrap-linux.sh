#!/bin/bash
if ! [ -e ../buildx ] ; then
    mkdir ../buildx
fi
cd ../buildx
cmake -G "Ninja Multi-Config" -DCMAKE_CONFIGURATION_TYPES="Release;Debug" ..
