#include "funciones.h"

FILE* openread(char *namefile){
  FILE * f;
  if( (f = fopen(namefile, "r"))==NULL    ){
    printf("Error en la lectura del archivo.\n");
  }
return f;
}

void changeChar(char *namechar){
  for(int i=0; i<strlen(namechar); i++){
    if(namechar[i]=='\n') namechar[i]='\0';
  }
}


char* rline(char* dst, FILE* stream){
  char* aux =fgets(dst, 50, stream);
  if(aux!=NULL){
    changeChar(aux);
  }
  return aux;
}



int compare(char* title, char* aux){
  if(strlen(title)==strlen(aux)){
    for(int i=0; i<strlen(title);i++){
      if(title[i]!=aux[i]) return 0;
    }
  }
  return 1;
}

int checkBook (char* namefile, char* title){
  char aux[50];
  float auxp;
  int auxs;
  FILE *f;
  f = openread(namefile);
  char* i = fgets(aux, 50, f );
  while(i!=NULL){
    changeChar(aux);
    if(compare(title, aux)){
      fclose(f);
      return 1;
    }
    fscanf(f, "%f\n %d\n", &auxp,&auxs );
    i = fgets(aux, 50, f);
  }
  fclose(f);
  return 0;
}

int countBooks(char* namefile){
  int count=0;
  FILE *f = openread(namefile);
  char aux[50];
  float auxc;
  int auxs;
  char* i=fgets(aux, 50 ,f );
    while(i!=NULL){
      fgets(aux, 50 , f );
      fscanf(f, "%f %d\n", &auxc,&auxs );
      i=fgets(aux, 50 ,f );
      count++;
    }
  return count;
}

Libro newBook(){
  Libro aux;
  char title[50];
  char author[50];

  printf("Title:\n");
  rline(aux.title,stdin);
  printf("Author:\n");
  rline(aux.author,stdin);
  printf("Cost:\n");
  scanf("%f", &aux.cost);
  printf("Stock:\n");
  scanf("%d", &aux.stock);

  return aux;
}

void addBook(char *namefile){
  Libro aux = newBook();
  FILE * f;
  if ( (f=fopen(namefile, "a")  )==NULL ) {
    printf("Fallo en la apertura del archivo (modo escritura)\n");
  }
  fprintf(f, "%s\n %s\n %f\t %f\n", aux.title, aux.author, aux.cost, aux.stock );
  fclose(f);
}

Libro* fileToArray(char* namefile, int size){
  Libro* aux;
  if( (aux = malloc(size*sizeof(Libro)))==NULL){
    printf("Error en la reserva de memoria.\n");
  }
  FILE *f;
  char title[50];
  char author[50];
  f = openread(namefile);
  for(int i=0; i<size; i++){
    rline(aux[i].title, f);
    rline(aux[i].author, f);
    fscanf(f, "%f %d\n", &(aux[i].cost), &(aux[i].stock));
  }
  fclose(f);
  return aux;
}

void listBooks(char* namefile){
  int size = countBooks(namefile);
  Libro* aux = fileToArray(namefile, size);
    for(int i = 0; i< size; i++){
      printf("%s\n%s\n%f\t%d\n", aux[i].title, aux[i].author, aux[i].cost, aux[i].stock );
    }
  free(aux);
}

void sellBook(char* namefile, char* title){

  int conteo = countBooks(namefile);
  Libro* aux = fileToArray(namefile, conteo);

  for(int i = 0; i<conteo; i++){
    if(compare(aux[i].title, title)) aux[i].stock--;
  }

  FILE* f = fopen(namefile, "w");
    for(int i = 0; i<conteo; i++){
    fprintf(f, "%s\n%s\n%f\t%d\n", aux[i].title, aux[i].author, aux[i].cost, aux[i].stock );
    }
  free(aux);
  fclose(f);
}


void clearBooks (char *namefile){
  FILE *f;
  if( ((f = fopen(namefile, "w"))==NULL) ){
    printf("Error en la apertura del fichero (modo escritura)\n");
  }
  int conteo = countBooks(namefile);
  Libro* aux = fileToArray(namefile, conteo);

    for(int i = 0; i<conteo; i++){
      if(aux[i].stock != 0){
      fprintf(f, "%s\n%s\n%f\t%d\n", aux[i].title, aux[i].author, aux[i].cost, aux[i].stock );
      }
    }
  free(aux);
  fclose(f);
}
