#!/bin/bash

problem=guess

g++ -std=gnu++14 -O2 -o "${problem}" "grader.cpp" "${problem}.cpp" && "./${problem}"
