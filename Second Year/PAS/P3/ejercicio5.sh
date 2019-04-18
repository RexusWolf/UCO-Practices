#!/bin/bash

# Comprobamos si la carpeta Copia existe
if [ ! -d "$HOME/Copia" ]; then
	echo "La carpeta no existe. Creando..."
	mkdir ~/Copia
fi

for file in $(find ~/Copia -type f)
do
	fechaCreado=$(stat $file -c %X)
	# Para obtener los segundos desde su creación, hay que realizar lo siguiente
	let segundos=$(date +%s)-$fechaCreado
	if [ $segundos -gt 200 ]; then
		echo "Borrando $file de $segundos segundos..."
		rm -f $file
	fi
done

if [ $# -gt 0 ] && [ -d "$1" ]; then
		tar -czf ~Copia/copia-$(whoami)-$(date +%s).tar.gz $*
		echo "La copia de seguridad se ha creado correctamente."
else
		echo "No se ha creado copia de seguridad."
fi
