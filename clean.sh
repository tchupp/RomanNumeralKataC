#!/usr/bin/env bash

rm -fr `find ./build/ -name CMakeFiles`
rm -f `find ./build/ -name CMakeCache.txt`
rm -f `find ./build/ -name Makefile`
rm -f `find ./build/ -name cmake_install.cmake`
rm -f `find ./build/ -name "*.a"`
rm -fr build

