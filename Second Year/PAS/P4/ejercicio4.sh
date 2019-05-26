#!/bin/bash

if [[ $# -ne 2 || ! -f $1 || $2 -lt 1 ]]; then
    echo "ERROR: Argumentos incorrectos. ejercicio4.sh <IPs.txt> (<segundosmuerto> > 0)"
    exit 1
fi

for ip in $(cat $1); do
    if ret=$(ping -c 1 -W $2 $ip); then
        time=$(ping $ip -c 1 | grep -Eo 'time=.+ms' | grep -Eo '[^time=].+[^ ms]')
        echo "La IP $ip respondió en $time milisegundos"
    else 
        echo "La IP $ip no respondió tras $2 segundos"
    fi
done | sort -k6d 
