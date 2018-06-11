#ifndef FUNCIONES_H
#define FUNCIONES_H

        #include <stdio.h>
        #include <stdlib.h>
        #include <string.h>

        struct pila * nuevoElemento(int n);
        
        void verCima(struct pila *cabeza, char* nombre);
        void liberarMemoria (struct pila*);
#endif
