#!/bin/bash
if ! [ -e ../buildx ] ; then
    mkdir ../buildx
fi
cd ../buildx
cmake -G "CodeLite - Ninja" -DCMAKE_BUILD_TYPE="Debug" ..
