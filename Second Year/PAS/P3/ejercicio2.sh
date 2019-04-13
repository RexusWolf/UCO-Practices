#!/bin/bash

$bytes=0
$bytes=$2
for x in $(find $1 -name "*.c" -o -name "*.h")
do
    echo "El fichero" $x "tiene" $(cat $x | wc -l) "lineas y" $(cat $x | wc -c) "caracteres"
done | sort -rn -k 8