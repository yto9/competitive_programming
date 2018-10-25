#!/bin/bash
# usage ./atcoder.sh ABC 001 A
cd `dirname $0`
mkdir -p atcoder/$1$2
cp temp.cpp atcoder/$1$2/$3.cpp