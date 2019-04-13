#!/bin/bash
elArray=("pelo" "pico" "pata")
for x in ${elArray[*]}
do
   echo "--> $x"
done

echo ${elArray[2]}
