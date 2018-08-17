#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

Nodo *primer = NULL;
Nodo *ultimo = NULL;

void agregar (Nodo *nodo){

  nodo -> sgte = NULL;

  if(primer == NULL){ //La lista está vacía.
    primer = nodo;
    ultimo = nodo;
  }
  else{
    ultimo -> sgte = nodo;
    ultimo = nodo;
  }
}

int mayornodo (Nodo *nodo){
  Nodo *i = nodo;
  int mayor = i->dato;
  while(i != NULL){
    if (i->dato > mayor){
      mayor = i->dato;
    }
    i = i -> sgte;
  }
  return mayor;
}

int menornodo (Nodo *nodo){
  Nodo *i = nodo;
  int menor = i->dato;
  while(i != NULL){
    if (i->dato < menor){
      menor = i->dato;
    }
    i = i -> sgte;
  }
  return menor;
}

void liberaNodo (Nodo *nodo){
 Nodo *i = nodo;
  while(i != NULL){
    free(i);
    i = i -> sgte;
  }
}

int contarnegativos(Nodo *nodo){
  Nodo *i = nodo;
  int contador = 0;

  while (i != NULL){
    if(i->dato<0) contador++;
    i = i -> sgte;
  }

  return contador;

}

int contarpositivos(Nodo *nodo){
  Nodo *i = nodo;
  int contador = 0;

  while (i != NULL){
    if(i->dato>0) contador++;
    i = i -> sgte;
  }

  return contador;

}
