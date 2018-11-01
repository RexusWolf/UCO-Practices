#include <stdlib.h>
#include <sys/wait.h>
#include <math.h>
#include <time.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

// Es una copia del ejercicio 2 añadiendo la función para rellenar el vector con números aleatorios..


#define CHILDREN 3

void functions(int id, int* memoria ){
  int indice,valor;
  switch (id) {
    case 0:
      for(int i = 0; i< 10; i++){
        printf("Introduce el indice\n");
        scanf("%d",&indice );
        printf("Introduce el valor\n");
        scanf("%d",&valor );
        memoria[indice]=valor;
      }
      break;
    case 1:
      srand(time(NULL));
      for (int j = 0; j<100;j++){
        indice  = rand()%100;
        valor  = rand()%999;
        memoria[indice] = valor;
        sleep(1);
      }
      break;
    case 2:
    for (int k = 0; k<5;k++){
      int aux = 0;
      for (int l = 0;l<100;l++){
        aux = aux + memoria[k];
      }
      printf("Valor: %d\n",aux );
      sleep(5);
    }
      break;
  }

}

int main(int argc, char const *argv[]) {

  key_t memoryKey;
  int memoryID,status;
  int* memorySpace;

  //Generamos la memoryKey
  memoryKey = ftok("/bin/ls",45);
  if (memoryKey == -1){
    printf("Fallo al obtener la clave de memoria\n");
    exit(-1);
  }
  // Creamos memoria compartida
  memoryID =shmget(memoryKey,sizeof(int)*100, 0777 | IPC_CREAT);
  if (memoryID == -1){
    printf("Fallo al obtener la clave de memoria\n" );
    exit(-1);
  }
  // Reservamos memoria compartida
  memorySpace =(int*)shmat (memoryID, (char *)0,0);
  if (memorySpace == NULL){
    printf("Fallo en la obtención de la memoria compartida\n");
    exit(-1);
  }
 // Rellenamos el vector con valores aleatorios.
  srand(time(NULL));
 for(int i = 0; i < 100; i++){
   memorySpace[i] = rand()%1000;
 }

  //Creamos los procesos hijos
  for (int i = 0; i<CHILDREN;i++){
    if (!fork()){
      functions(i,memorySpace);
      exit(0);
    }
  }
  //Esperamos a que los hijos terminen el proceso
  for (int j=0; j<CHILDREN;j++){
    pid_t pid = wait(&status);
    printf("Hijo: %d finalizado con el estado: %d\n",pid,WEXITSTATUS(status));
  }
  // Liberamos memoria compartida usada
  shmdt((char *)memorySpace);
  shmctl (memoryID,IPC_RMID,(struct shmid_ds *)NULL);
  return 0;
}
