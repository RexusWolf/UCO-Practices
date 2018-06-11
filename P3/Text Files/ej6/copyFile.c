#include "ej6.h"

void copyFile (char *file){
int c;
FILE * f1;
FILE * f2;
  if((f1 = fopen(file,"r"))==NULL){
    printf("Error en la apertura del archivo.");
  }
  else printf("El fichero %s ha sido abierto correctamente.\n", file);

  if((f2 = fopen ("mayusculas-nombreFicheroDeEntrada.txt","w")) == NULL){
    printf("Error en la apertura del archivo de texto.");
  }
  else printf("El fichero f2 ha sido creado correctamente.\n");
  c = fgetc (f1);
  while (c  != EOF){
    fputc(toupper(c),f2);
    c = fgetc (f1);
  }
  fclose(f1);
  fclose(f2);

}
