#ifndef FUNCIONES_H
#define FUNCIONES_H

typedef struct Fraccion{
  int numerador;
  int denominador;
}Fraccion;


  #include <stdio.h>
  #include <stdlib.h>
  Fraccion * reservavector(Fraccion *vector, int size);
  void escribevector(Fraccion *vector, int size);
  void imprimevector(Fraccion *vector, int size);
  //void ordenavector(Fraccion *vector, int size, int (*comparacion)());
  int esmayor(struct Fraccion a, struct Fraccion b);
  int esmenor(struct Fraccion a, struct Fraccion b);
  void ordenavector(Fraccion *vector, int izda, int dcha, int(*comparacion)(Fraccion, Fraccion)  );
#endif
