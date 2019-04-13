#!/bin/bash

for f in $(find /etc/rc?.d -name "S*")
do
	echo "Carpeta $(dirname $f) Fichero $(basename $f)"
done

for f in $(find /etc/rc?.d )
do
	if [[ "$(basename $f)" == S* ]] # Doble corchete para expreg
	then
		echo "Carpeta $(dirname $f) Fichero $(basename $f)"
	fi
done


