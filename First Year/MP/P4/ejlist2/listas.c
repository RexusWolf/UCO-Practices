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

void imprimeNodo(){
  Nodo *a = primero;
  while(a!=NULL){
    printf("%d\n", a->dato );
    a = a->sgte;
  }
}
/*
//Esta forma de realizar la liberación de memoria es errónea.
void liberaNodo(){
  Nodo *b = primero;
  while(b!=NULL){
    b = b->sgte;
    free(b);
    }
    printf("Memoria liberada.\n");
  }
*/

  void liberaNodo(){
    eliminarlista(primero);
  }

  void eliminarlista(Nodo *primero){
   if (primero != NULL){
      eliminarlista( primero->sgte );
      free( primero );
      printf("Memoria liberada\n");
   }
 }
