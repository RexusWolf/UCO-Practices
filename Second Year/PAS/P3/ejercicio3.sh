#!/bin/bash

# Comprueba el número de argumentos
if [ $# -lt 1 ] || [ $# -gt 3 ]; then
	echo "Uso del programa: ./ejercicio3.sh <directorio> <umbral1> <umbral2>"
	exit 1
fi

umbral1=10000
umbral2=100000

if [ $# -ge 2 ]; then
	umbral1=$2
fi

if [ $# -eq 3 ]; then
	umbral2=$3
fi

if [ -d "pequenos" ]; then
  rm -rf pequenos
fi
if [ -d "medianos" ]; then
  rm -rf medianos
fi
if [ -d "grandes" ]; then
  rm -rf grandes
fi

mkdir pequenos
mkdir medianos
mkdir grandes

for file in $(find $1 -size -"$umbral1"c -type f -or -size "$umbral1"c -type f)
do
	cp $file pequenos
done

for file in $(find $1 -size +"$umbral1"c -type f -and -size -"$umbral2"c -type f)
do
	cp $file medianos
done

for file in $(find $1 -size +"$umbral2"c -type f -or -size "$umbral2"c -type f)
do
	cp $file grandes
done