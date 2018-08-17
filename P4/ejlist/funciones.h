#ifndef FUNCIONES_H
#define FUNCIONES_H

typedef struct{
  int dato;
  struct Nodo *sgte;
}Nodo;

void agregar (Nodo *nodo);
int menornodo (Nodo *nodo);
int mayornodo (Nodo *nodo);
void liberaNodo (Nodo *nodo);
int contarnegativos(Nodo *nodo);
int contarpositivos(Nodo *nodo);
#endif
