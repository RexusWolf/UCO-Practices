#include "funciones.h"

int main(int argc, char const *argv[])
{
		char namefile[50] = "Libros.txt";


		char titulo[50];
		char titulo2[50];
		printf("Introduce libro a buscar:");
		fgets(titulo, 50, stdin);
		strcpy(titulo,cambiabarra(titulo));
		printf("%d\n", stockLibro(namefile, titulo) );

		printf("Introduce libro a buscar:");
		fgets(titulo2, 50, stdin);
		strcpy(titulo2,cambiabarra(titulo2));
		printf("%d\n", stockLibro(namefile, titulo2) );

		return 0;
}
