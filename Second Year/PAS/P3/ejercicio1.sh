#!/bin/bash

ficherosc=$(find $1 -name "*.c" | wc -l)
ficherosh=$(find $1 -name "*.h" | wc -l)
echo "Tenemos  $ficherosc ficheros con extensión .c y $ficherosh con extensión .h"
for x in $(find $1 -name "*.c" -o -name "*.h")
do
    echo "El fichero" $x "tiene" $(cat $x | wc -l) "lineas y" $(cat $x | wc -c) "caracteres"
done | sort -rn -k 8