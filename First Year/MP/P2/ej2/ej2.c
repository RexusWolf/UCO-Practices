#include <stdlib.h>
#include <stdio.h>


void leerVector(int *vector){
  for(int i=0; i<10; i++){
    printf("Introduce elemento número %i:\n",i );
    scanf("%d", &vector[i]);
  }

}

void escribeVector (int *vector){
  for(int i=0; i<5; i++){
    printf("%d\n", vector[i] );
  }


}
void vectores (int *v, int longitud, int num){
int j=0;
int z=0;

int *mayor = (int*) malloc (5*sizeof(int));
int *menor = (int*) malloc (5*sizeof(int));

for(int i=0;i<4; i++){
  mayor[i]=0;
  menor[i]=0;
}
  for (int i=0; i<longitud; i++){
    if(v[i]>=num){
      mayor[j]=v[i];
      j++;
    }
    else{
      menor[z]=v[i];
      z++;
    }
  }
printf("--------------------\n");
  escribeVector(mayor);
  escribeVector(menor);
printf("--------------------" );
}



 int main(int argc, char const *argv[]) {
   int longitud = 10;
  int* v = (int *) malloc (10*sizeof(int));

  int num = 5;
  leerVector(v);
  vectores(v, longitud, num);
  return 0;
}
