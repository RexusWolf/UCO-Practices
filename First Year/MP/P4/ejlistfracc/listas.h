#ifndef LISTAS_H
#define LISTAS_H

  #include <stdlib.h>

 typedef struct Fraccion{
   int numerador;
   int denominador;
 }Fraccion;

 typedef struct Nodo{

   struct Fraccion dato;
   struct Nodo *sgte;


 }Nodo;

     Nodo * reservaNodo();
     void nuevoNodo (Nodo *nodo);
     void liberaNodo ();
     void imprimeNodo();
     void eliminarlista(Nodo *primero);
     int esmayor(struct Fraccion a, struct Fraccion b);
     int esmenor(struct Fraccion a, struct Fraccion b);
     Fraccion mayornodo (Nodo *nodo);
     Fraccion menornodo (Nodo *nodo);
#endif
