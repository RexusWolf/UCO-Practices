#!/bin/bash

if [ $# -lt 1 ] || [ $# -gt 2 ]; then
	echo "Uso del programa: ./ejercicio1.sh <directorio>"
	exit 1
fi

directorio=$1

nficherosc=$(find $directorio -name "*.c" | wc -l)
nficherosh=$(find $directorio -name "*.h" | wc -l)
echo "Tenemos  $nficherosc ficheros con extensión .c y $nficherosh con extensión .h"
for file in $(find $directorio -name "*.c" -o -name "*.h")
do
    echo "El fichero" $file "tiene" $(cat $file | wc -l) "lineas y" $(cat $file | wc -c) "caracteres"
done | sort -rn -k 8