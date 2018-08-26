#ifndef LISTAS_H
#define LISTAS_H

  #include <stdlib.h>
 typedef struct lista{

   int dato;
   struct Nodo *sgte;


 }Nodo;

     Nodo * reservaNodo();
     void nuevoNodo (Nodo *nodo);
     void liberaNodo (Nodo *nodo);

#endif
