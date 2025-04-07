#!/bin/bash

cd ..
rm -r build/*
clear
cmake -B build/
cd build/
make