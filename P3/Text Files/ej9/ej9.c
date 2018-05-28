#include "funciones.h"

int main(int argc, char const *argv[])
{
	FILE* libros;
	if ((libros=fopen("Libros.txt", "r"))==NULL){
		printf("Error al abrir el archivo de libros\n");
		exit(-1);
	}
  	printf("Hay %i libros diferentes\n", contarLibros(libros));
	fclose(libros);
	return 0;
}
