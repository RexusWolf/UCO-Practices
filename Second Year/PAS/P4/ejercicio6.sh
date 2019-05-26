if [[ $# -gt 1 ]]; then
    echo "ERROR: Argumentos incorrectos. ejercicio6.sh [cadenatexto]"
    exit 1
fi

egrep "$1" /etc/passwd | sed -nr "s/([^:]+):[^:]+:([^:]+):([^:]+):([^:]+):([^:]+):([^:]+)/Logname:\1\n->UID:\2\n->GID:\3\n->gecos:\4\n->Home:\5\n->Shell:\6\n===============/p"	
	
