#!/bin/bash

mkdir -p build
cd build && cmake .. && make && ./open_gl_pixel && cd .. && rm -rf build