#!/usr/bin/env bash

gcc --coverage 02_simple_marco.c -o 02_simple_marco
./02_simple_marco
lcov -t "02_simple_marco" -o 02_simple_marco.info -c -d .
genhtml -o report 02_simple_marco.info 
