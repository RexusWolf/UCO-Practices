#include "funciones.h"

// I will use my writeOnFile function which I already created in ej7.c from P3.

int* RandomArray(int numelem){
  int* array;
  array = calloc(numelem,sizeof(int));
  if(array == NULL){
    printf("Fallo al reservar memoria\n" );
    exit(-1);
  }
  return array;
}

void addFile (char *namefile, int* array, int numelem){
  FILE * f;
  if ((f= fopen(namefile, "wb"))==NULL){
    printf("ERROR en la creacion del archivo.");
  }
  else{
    FILE * f2;
    if ((f2= fopen("namefile.txt", "w"))==NULL){
    printf("ERROR en la creacion del archivo.");
    }
    fwrite (array, sizeof(int),numelem, f );

    for(int i = 0; i < numelem; i++){
       fprintf(f2, "%d\n", *(array+i) );
   }
    fclose(f);
    fclose(f2);
  }

}


int* writeOnArray (int* array, int numelem, int N, int M){
  printf("El numero aleatorio esta comprendido entre %d y %d.\n", M, N);
  srand (time(NULL));
  for (int i = 0; i< numelem; i++){
    *(array+i) = rand() % (N-M+1) + M;

  }
}

int* copyArray (int* array, int* array2, int numelem){
  for (int i = 0; i < numelem; i++){
    *(array2+i) = *(array+i);
  }
}

float evenNumbers (int* array, int numelem){
  float media = 0;
  float suma = 0;
  for (int i = 0; i < numelem; i++){
    suma+=*(array+i);
  }
  media = suma / numelem;
  return media;
}
