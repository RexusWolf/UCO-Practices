#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"


int main(int argc, char const *argv[]) {

  Nodo *primerNodo = malloc(sizeof(Nodo));
  primerNodo -> dato = 5;

  Nodo *segundoNodo = malloc(sizeof(Nodo));
  segundoNodo -> dato = 7;

  Nodo *tercerNodo = malloc(sizeof(Nodo));
  tercerNodo -> dato = -4;

  agregar(primerNodo);
  agregar(segundoNodo);
  agregar(tercerNodo);



  int opcion;
  printf("1. Imprimir mayor.\n");
  printf("2. Imprimir menor.\n");
  scanf("%d", &opcion );

  if(opcion==1){ printf("Mayor: %d\n",mayornodo(primerNodo) );}

  else{
    if(opcion==2){printf("Menor: %d\n",menornodo(primerNodo) ) ;}
    else{
    printf("Opcion no valida.");
    }
  }
  printf("Hay %d negativos.\n ", contarnegativos(primerNodo) );
  printf("Hay %d positivos.\n", contarpositivos(primerNodo) );
  return 0;
}
