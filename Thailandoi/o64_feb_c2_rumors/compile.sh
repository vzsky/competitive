#!/bin/bash

problem=rumors

g++ -std=gnu++14 -O2 -o "${problem}" "grader.cpp" "${problem}.cpp" && "./${problem}"
