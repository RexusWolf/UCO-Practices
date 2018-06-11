#include "funciones.h"
#define MAX_LINE 40
typedef struct Libro{
  char title[MAX_LINE];
  char author[MAX_LINE];
  float cost;
  int stock;
}Libro;

char* cambiabarra (char* nombre){
  for (int i = 0; i < strlen(nombre) + 1; i++) {
      if (nombre[i] == '\n') nombre[i] = '\0';
  }
return nombre;
}

FILE * openread(char * namefile){
    FILE* libros;
    if ((libros=fopen(namefile, "r"))==NULL){
      printf("Error al abrir el archivo de libros\n");
      exit(-1);
    }
  return libros;
}

int stockLibro(char* namefile, char *titulo){
  FILE *f = openread(namefile);
  char aux0[MAX_LINE];
  float aux1;
  int aux2;

  fgets(aux0, MAX_LINE, f);


	while(aux0!=NULL){
    cambiabarra(aux0);
		if(strcmp(titulo,aux0)==0){
      fclose(f);
      return 0;
    }
    fgets(aux0, MAX_LINE, f);
    fscanf(f, "%f %d\n", &aux1, &aux2);
    fgets(aux0, MAX_LINE, f);
	}
  fclose(f);
  return 1;
}
