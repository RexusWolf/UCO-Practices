#!/bin/bash

# Comprueba el número de argumentos
if [ $# -lt 1 ] || [ $# -gt 2 ] || [ ! -d "$1" ]; then
	echo "Uso del programa: ./ejercicio2.sh <directorio> <bytes>"
	exit 1
fi

if [ $# -eq 2 ]; then
	n_bytes=$2
else 
	n_bytes=0
fi

for file in $(find $1 -size +"$n_bytes"c -type f -or -size "$n_bytes"c -type f)
do
    # Cuenta los caracteres del usuario del fichero
	CaracteresUser=$(stat -c %U $file | wc -c)

    # Comprueba si el fichero es ejecutable
	if [ -x "$file" ]
	then
		Exec=1
	else
		Exec=0
	fi

	echo "$(basename $file);$CaracteresUser;$(stat -c '%w;%X;%s;%b;%A' $file);$Exec)"
done | sort -k 5 -n -t ";"