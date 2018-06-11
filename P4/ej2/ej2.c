#include "funciones.h"
//Credits to @Pablorg99
int main(int argc, char const *argv[]) {

  if (argc != 3) {
    printf("Uso: ./a.out <nombreBinario> <ascendente/descendente>\n");
    exit(-1);
  }

  ficha *vector;
  int nFichas = 0;
  char file[30];
  strcpy(file, argv[1]);  //Copiamos el argv[1] a la cadena file.
  char orden[30];
  strcpy(orden, argv[2]); //strcpy() Copiamos el argv[2] a la cadena orden.

  //char file_path[30] = "./FicherosMoodle";
  //sprintf (file_path, "%s%s", file_path, file);

  vector = getArrayFromFile (file, &nFichas);
  printf("------------VECTOR SIN ORDENAR------------\n");
  printArray(vector, nFichas);

  if (strcmp(orden, "ascendente") == 0) burbuja (vector, 0, nFichas - 1, &esMayor);
  if (strcmp(orden, "descendente") == 0) burbuja (vector, 0, nFichas - 1, &esMenor);

  printf("\n------------VECTOR ORDENADO------------\n");
  printArray(vector, nFichas);
  free (vector);
  return 0;
}
