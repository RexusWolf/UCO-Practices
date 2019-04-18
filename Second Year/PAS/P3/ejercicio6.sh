#!/bin/bash

# Comprueba los argumentos
if [ $# != 1 ] || [ ! -d $1 ]; then
	echo "Uso del programa: ./ejercicio6.sh <directorio>"
	exit 1
fi

html="$1.html"

if [ -f $html ]; then
	echo "Borrando fichero html anticuado..."
	rm -f $html
fi

function listDirectory(){
	echo "<ul>" >> "$html"
	for file in $(find "$1" -maxdepth 1)
	do
		if [ -d "$file" ] && [ $file != $1 ]; then
			echo "<li><strong>$file</strong></li>" >> $html
			listDirectory $file
		elif [ $file != $1 ]; then
			echo "<li>$file</li>" >> $html
		fi
	done
	echo "</ul>" >> $html
}

echo "Generando el listado de la carpeta $(dirname $html) sobre el fichero $html"
echo "</head>" >> "$html"
echo "<title>Listado directorios de $1/</title>" >> "$html"
echo "</head>" >> "$html"
echo "<body>" >> "$html"
echo "<h1>Listado directorios de $1/</h1>" >> "$html"
listDirectory $1
echo "</body>" >> "$html"
echo "</html>" >> "$html"
echo "Terminado!"