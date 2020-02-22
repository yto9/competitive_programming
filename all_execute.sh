#!/bin/bash

rm ./atcoder/2HC2019/zip/toolkitA/scripts/out/*
for i in `ls ./atcoder/2HC2019/zip/toolkitA/scripts/in`
do
  ./a.out < ./atcoder/2HC2019/zip/toolkitA/scripts/in/$i > ./atcoder/2HC2019/zip/toolkitA/scripts/out/$i.out
  echo $i
  ./atcoder/2HC2019/zip/toolkitA/scripts/output_checker ./atcoder/2HC2019/zip/toolkitA/scripts/in/$i ./atcoder/2HC2019/zip/toolkitA/scripts/out/$i.out
done
