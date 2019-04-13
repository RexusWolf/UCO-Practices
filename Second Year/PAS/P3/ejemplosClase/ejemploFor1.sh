#!/bin/bash
let sum=0
for num in 1 2 3 4 5
do
  let "sum = $sum + $num"
  echo "La variable 'sum' en la iteración $num es $sum"
done
