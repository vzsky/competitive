#!/bin/bash

problem=messy

g++ -O2 -std=c++11 -o $problem grader.cpp $problem.cpp && ./$problem
