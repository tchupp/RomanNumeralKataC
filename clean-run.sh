#!/usr/bin/env bash

bash clean.sh

mkdir build

cd build
cmake ..
make
ctest --output-on-failure .