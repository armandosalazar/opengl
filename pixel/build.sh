#!/bin/bash

mkdir build
cd build && cmake .. && make && ./open_gl && cd ..