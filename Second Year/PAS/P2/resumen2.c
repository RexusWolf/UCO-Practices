#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
  int status;
  const int BSIZE = 100;
  char buf[BSIZE];
  ssize_t nbytes;
  int num1, num2;
  char cad1[8];
  char cad2[8];
  char cad[20];
  char *ptr;
  int fildes[2];
  /*
  On success, the PID of the child process is returned in the parent,
  and 0 is returned in the child. On failure, -1 is returned in the parent,
  no child process is created, and errno is set appropriatel
  */
  printf("Introduce el primer número entero:\n");
  scanf("%d", &num1 );
  printf("Introduce el segundo número entero:\n");
  scanf("%d", &num2 );
  sprintf(cad1, "%d", num1);
  strcat(cad1, ";");
  sprintf(cad2, "%d", num2);
  strcat(cad1, cad2);
  printf("%s\n", cad1 );
  strcpy(buf, cad1);

  status = pipe(fildes);
  if (status == -1){
    printf("Error al crear tubería.\n");
    exit(0);
  }

  switch(fork()){
    case -1: // Error al hacer fork()
      break;
    case 0:
      nbytes = read(fildes[0], buf, sizeof(buf));

      printf("Leido %s en la tuberia 1.\n", &buf );
      close(fildes[0]);
      printf("Tuberia 1 cerrada.\n");
      ptr = strtok(cad, ";");
      printf("%s\n", ptr);
      //cad2 = cad;
      printf("He escrito en la tuberia 2\n");
      close(fildes[1]);
      printf("Tuberia 2 cerrada.\n");
      exit(EXIT_SUCCESS);

    default:
      close(fildes[0]);
      printf("Tubería 1 cerrada.\n");
      write(fildes[1], cad, 20);
      printf("He escrito los dos números en la tuberia 2.\n");
      close(fildes[1]);
      printf("Tuberia 2 cerrada.\n");
      exit(EXIT_SUCCESS);
  }




  return 0;
}
