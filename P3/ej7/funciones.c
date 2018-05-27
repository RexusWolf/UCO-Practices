#include "funciones.h"

void addFile (char *namefile){
  FILE * file;
  int numelem=0;
  if ((file = fopen (namefile,"w"))==NULL){
    printf("Error en la creación del archivo.");
  }
  else
    printf("Introduce numero de elementos a escribir: ");
    scanf("%d",&numelem);
    writeOnFile (numelem,file);
}

void writeOnFile (int numelem, FILE * f){
  int N, M;
  int anum;
  printf("Introduce extremo inferior del intervalo: ");
  scanf("%d",&M);
  printf("Introduce extremo superior del intervalo: ");
  scanf("%d",&N);
  printf("El numero aleatorio esta comprendido entre %d y %d.\n", M, N);
  srand (time(NULL));
  for (int i = 0; i< numelem; i++){
    anum = rand() % (N-M+1) + M;
    printf("El numero aleatorio es %i\n", anum);
      fprintf(f, "%d\n", anum );
    }
      fclose(f);
}
