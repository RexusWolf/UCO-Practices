#include "funciones.h"

FILE * openread (char* namefile){
  FILE * f;
  if ( (f = fopen(namefile, "rb") )== NULL){
    printf("Error en la lectura del fichero.\n");
  }
 return f;
}

void changeChar(char * namechar){
  for(int i=0; i<strlen(namechar); i++){
    if(namechar[i]=='\n')namechar[i]='\0';
  }
}

Libro newbook(){
  Libro aux;
  fgets(aux.title, 50, stdin);
  changeChar(aux.title);
  fgets(aux.author, 50, stdin);
  changeChar(aux.author);
  scanf("%f", &aux.price);
  scanf("%d", &aux.stock);

return aux;
}

void addBook(char *namefile){
 Libro aux = newbook();
 FILE * f;
 f = fopen(namefile, "ab");
 fwrite(&aux, sizeof(Libro), 1, f);
 fclose(f);
}

int countBooks(char *namefile){
  FILE *f;
  int count;
  f = openread(namefile);
  fseek(f, 0L, SEEK_END);
  count = ftell(f)/sizeof(Libro);
  return count;
}

int checkBook (char *namefile, char *title){
 Libro aux;
 int size = countBooks(namefile);
 FILE *f;
 f = openread(namefile);
      for (int i=0; i<size; i++){ //while(fread...)>0)
       fread(&aux, sizeof(Libro), 1, f);
         if(strcmp(aux.title,title)==0){
            fclose(f);
            return 1;
         }
      }
    fclose(f);
    return 0;
}

Libro * filetoArray(char *namefile){
  FILE * f;
  f = openread(namefile);
  int size = countBooks(namefile);
  Libro* aux;
  if( (aux = (Libro*)malloc(  size*sizeof(Libro)  ) )==NULL  ){
    printf("Error en la reserva de memoria.\n");
  }
  fread(aux, sizeof(Libro), size, f);
  fclose(f);
  return aux;
}

void listBooks (char *namefile){
  Libro *aux = filetoArray(namefile);
  int size = countBooks(namefile);
  for(int i = 0; i<size; i++){
    printf("%s\n%s\n%f\t%d\n", aux[i].title, aux[i].author, aux[i].price, aux[i].stock );
  }
  free(aux);
}

void sellBook (char *namefile, char *title){
  Libro aux;
  int size = countBooks(namefile);
  FILE *f;
  f = fopen(namefile, "r+b");

      while((fread(&aux, sizeof(Libro), 1, f))>0){
          if(strcmp(aux.title,title)==0){
              aux.stock--;
              printf("Libro vendido.\n");

          fseek(f, -(int)sizeof(Libro), SEEK_CUR);
            fwrite(&aux, sizeof(Libro), 1, f);
          fflush(f);
          }
       }

     fclose(f);
}

void clearBooks (char *namefile){

  int i, size = countBooks(namefile);
  Libro* aux = filetoArray(namefile);
  FILE* f=fopen(namefile, "wb");
  for(i=0; i<size;i++){
    if(aux[i].stock>0){
      fwrite(aux, sizeof(Libro), 1, f);
    }
  }
  fclose(f);
  free(aux);
}
