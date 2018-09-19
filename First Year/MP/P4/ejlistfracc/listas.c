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
    printf("%d / %d\n", a->dato.numerador, a->dato.denominador );
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

  void eliminarlista(Nodo *primero){
   if (primero != NULL){
      eliminarlista( primero->sgte );
      free( primero );
      printf("Memoria liberada\n");
   }
 }

 void liberaNodo(){
   eliminarlista(primero);
 }

 Fraccion mayornodo (Nodo *nodo){
   Nodo *i = nodo;
   i = primero;
   Fraccion mayor = i->dato;
   while(i != NULL){
     if (esmayor(i->dato, mayor)){
       mayor = i->dato;
     }
     i = i -> sgte;
   }
   return mayor;
 }

 Fraccion menornodo (Nodo *nodo){
   Nodo *i = nodo;
   i = primero;
   Fraccion menor = i->dato;
   while(i != NULL){
     if ( esmenor(i->dato,menor) ){
       menor = i->dato;
     }
     i = i -> sgte;
   }
   return menor;
 }

 int esmayor(struct Fraccion a, struct Fraccion b){
   float valora;
   float valorb;
   valora = a.numerador / a.denominador;
   valorb = b.numerador / b.denominador;
   if (valora>valorb) return 1;
   return 0;
 }

 int esmenor(struct Fraccion a, struct Fraccion b){
   float valora;
   float valorb;
   valora = a.numerador / a.denominador;
   valorb = b.numerador / b.denominador;
   if (valora<valorb) return 1;
   return 0;
 }
