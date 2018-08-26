#include "listas.h"
#include <stdlib.h>
#include <stdio.h>

Nodo *primero = NULL;
Nodo *ultimo = NULL;

void nuevoNodo (Nodo *nodo){
nodo -> sgte = NULL;
  if(primero==NULL){
    primero = nodo;
    ultimo = nodo;

  }
  else{
    ultimo -> sgte = nodo;
    ultimo = nodo;
  }

}

Nodo * reservaNodo(){
  Nodo *nodo = malloc(sizeof(Nodo));
  return nodo;
}
void liberaNodo (Nodo *nodo){

  free(nodo);
  printf("Memoria liberada.\n");

}
