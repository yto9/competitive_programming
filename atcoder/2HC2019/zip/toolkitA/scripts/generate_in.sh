#!/bin/bash

for i in `seq 1000`
do
  ./generator in/1_$i.in 1 $i
done