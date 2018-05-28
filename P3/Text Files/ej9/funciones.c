#include "funciones.h"

int contarLibros(FILE * f){
  char nombre[50];
  int conteo = 0;
	while(fgets(nombre, 50, f)!= NULL){
		conteo = conteo + 1;
	}
  conteo = conteo/4;
	return conteo;
}
