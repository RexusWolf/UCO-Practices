#!/bin/bash

if [[ $# -gt 1 ]]; then
    echo "ERROR: Argumentos incorrectos. ejercicio3.sh [fichero.txt]"
    exit 1
fi

echo "==========================================="
echo "Listado de archivos ocultos del directorio $HOME"
ls -a $HOME | grep -E "^\..*$"
echo "==========================================="
if [[ "$#" -ne "0" && -f $1 ]]; then
	echo "El fichero a procesar es $1"
	grep -v -E "^$" $1 > "$1.sinLineasVacias"
	echo "El fichero sin lineas vacias se ha guardado en $1.sinLineasVacias"
else
	echo "$1 no es un fichero válido"
fi
echo "==========================================="
echo "Listado de procesos ejectuados por el usuario $USER"
ps -xu | sed -r -n 's/[^ ]+ +([^ ]+) +([^ ]+ +){6}([0-9:]+) +[^ ]+ (.+)/PID: "\1" Hora: "\3" Ejecutable: "\4"/p'

