#!/bin/bash

cd ejemploCarpeta
# La option maxdepth nos permite realizara el find solo en el directorio actual.
echo "El número de archivos de la carpeta actual es $(find . -maxdepth 1 -type f | wc -l)"

# awk hace print de los argumentos pasados (output del who) e imprime la 1ª columna.
echo $(who | awk '{print $1}' | sort | uniq)

read -n 1 -t5 -p "¿Qué caracter quieres contar? " caracter
# Hay que comprobar si se ha introducido algo.
if [ "$caracter" == "" ]; then
	caracter="a"
fi

# La salida del bucle la trataremos con grep y wc.
for file in $(find .)
do
	echo "$(basename $file)"
done | grep "$caracter" -o | wc -l > matchfile # -o printea solo las coincidencias

echo -e "\nEl carácter $caracter aparece $(cat matchfile) veces en nombres de ficheros o carpetas contenidos en la carpeta actual"
rm -f matchfile