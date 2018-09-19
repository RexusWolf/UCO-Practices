#ifndef LISTAS_H
#define LISTAS_H

  #include <stdlib.h>
 typedef struct Nodo{

   int dato;
   struct Nodo *sgte;


 }Nodo;

     Nodo * reservaNodo();
     void nuevoNodo (Nodo *nodo);
     void liberaNodo ();
     void imprimeNodo();

#endif
