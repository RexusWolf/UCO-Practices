#include "ej6.h"

void copyFile (char *file){
char c;
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

  while ((c = fgetc (f1) != EOF)){
    fputc (toupper(c), f2);
  }
  fclose(f1);
  fclose(f2);

}
