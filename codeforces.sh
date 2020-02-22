#!/bin/bash
# usage ./codeforces.sh div* 500 A
cd `dirname $0`
mkdir -p codeforces/$1_$2
cp temp.cpp codeforces/$1_$2/$3.cpp