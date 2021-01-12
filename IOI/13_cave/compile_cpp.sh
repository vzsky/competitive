#!/bin/bash

NAME=cave

/usr/bin/g++ -o $NAME grader.c $NAME.cpp && ./$NAME
