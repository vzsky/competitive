#!/bin/bash

problem=emergency

g++ -std=gnu++14 -O2 -o "${problem}" "grader.cpp" "${problem}.cpp" && "./${problem}"
