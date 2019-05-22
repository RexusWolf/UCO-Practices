#!/bin/bash
#ARG 1 peliculas.txt

echo "1) Líneas con la duración de las películas"
grep --color=always -E '[0-9].. [0-9]+min\>' $1

echo $'\n'
echo "2) Líneas con el país de las películas"
grep -E '\-.*\-' $1

echo $'\n'
echo "3) Solo el país de las películas"
grep -E -o '\-(.*)\-' $1

echo $'\n'
echo "4) Mostrar cantidad de películas de 2016 y de 2017"
echo "Hay $(grep -E -c '2016' $1) películas de 2016 y $(grep -E -c '2017' $1) películas de 2017"

echo $'\n'
echo "5) Eliminar líneas vacías:"
grep -E -v '^$' $1

echo $'\n'
echo "6) Líneas por E:"
grep -E '^ *E' $1

echo $'\n'
echo "7) Líneas que contienen d, l o t, una vocal y la misma letra:"
grep --color=always -E 't[aeiou]t|l[aeiou]l|d[aeiou]d' $1

echo $'\n'
echo "8) Líneas que contienen 8 aes o más:"
grep -E '(.*[a].*){8,}' $1

echo $'\n'
echo "9) Líneas que terminan con tres puntos y no empiezan por espacio:"
grep -E '^[^ ].*\.\.\.$' $1

echo $'\n'
echo "10) Utilizando sed, entrecomillar las vocales con tilde:"
cat $1 | sed 's/á/"á"/' | sed 's/é/"é"/' | sed 's/í/"í"/' | sed 's/ó/"ó"/' | sed 's/ú/"ú"/'