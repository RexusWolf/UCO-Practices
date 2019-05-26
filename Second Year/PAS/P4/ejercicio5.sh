if [[ $# -ne 0 ]]; then
    echo "ERROR: El programa no necesita argumentos"
    exit 1
fi

cat /proc/cpuinfo | sed -r -n '1,/^[ \t]*$/p' | sed -r -n 's/model name[ \t]+: +(.+)/Modelo: \1/p;
	s/cpu MHz[ \t]+: ([0-9\.]+)/Megahercios: \1/p;
	s/cpu cores[ \t]+: ([0-9]+)/Numero de hilos máximo de ejecución: \1/p;
	s/cache size[ \t]+: ([0-9]+)/Tamaño de caché: \1/p;
	s/vendor_id[ \t]+: (.+)/ID Vendedor: \1/p;
'
# Realizaremos los dos siguientes sed por separado para mantener el orden del ejemplo del pdf
cat /proc/cpuinfo | sed -nr "1,/cache size[ \t]+:/s/cache size[ \t]+: ([0-9]+)/Tamaño de caché: \1/p"
cat /proc/cpuinfo | sed -nr "1,/^[ \t]*/s/vendor_id[ \t]+: (.+)/ID vendedor: \1/p"

echo "Puntos de montaje:"
cat /proc/mounts | sed -nr "s/^([^ ]+) ([^ ]+) ([^ ]+) .+/-> Punto de montaje: \2, Dispositivo: \1, Tipo de dispositivo: \3/p" | sort -k 5 -r -t " "

echo "Particiones:"
cat /proc/partitions | sed -nr "s/^ +[^ ]+ +[^ ]+ +([^ ]+) +([^ ]+)/-> Particion: \2, Numero de bloques: \1/p"
