#include "funciones.h"

//FUNCIÓN PARA ABRIR UN FICHERO DE TXT PARA LECTURA.
FILE* openread (char *namefile){
  FILE * f;
  if((f = fopen(namefile, "rb")) == NULL ){
    printf("Error en la apertura del archivo.");
  }
  return f;
}
//ESTA FUNCIÓN INTERCAMBIA EL /n por un /0.
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

//FUNCIÓN CREADORA DE UN NUEVO LIBRO, LLAMADA POR ADDBOOK.
Libro newBook(){
  Libro aux;

  printf("Title:\n");
  rline(aux.title, stdin);
  printf("Author:\n");
  rline(aux.author, stdin);
  printf("Cost:\n");
  scanf("%f", &(aux.cost));
  printf("Stock:\n");
  scanf("%d", &(aux.stock));
  getchar();
  return aux;
}

//FUNCIÓN QUE AÑADE UN LIBRO A LA LIBRERÍA.
void addBook(char *namefile){
  Libro aux = newBook();
  FILE *f;
  if((f = fopen(namefile, "ab")) == NULL ){
    printf("Error en la apertura del archivo.");
  }

  fwrite(&aux, sizeof(aux), 1, f);

  fclose(f);
}

int compare(char* name1, char* name2){
  if(strlen(name1)==strlen(name2)){
    for(int i = 0; i<strlen(name1); i++){
      if(name1[i]!=name2[i]) return 0;
    }
    return 1;
  }
  return 0;
}
//FUNCIÓN PARA COMPROBAR EXISTENCIA DE UN LIBRO POR SU TÍTULO
int checkBook (char *namefile, char* title){
  Libro aux;
  FILE * f = openread (namefile);
  while((fread(&aux,sizeof(Libro),1,f))>0){
    if(compare(aux.title, title)){
      fclose(f);
      return 1;
    }
  }
  return 0;
}

//FUNCIÓN PARA CONTAR LIBROS

int countBooks (char* namefile){
  int count=0;
  FILE *f = openread(namefile);
  fseek(f, 0L, SEEK_END);
  count = ftell(f)/sizeof(Libro);
  return count;
}


Libro* libraryArray(char* namefile, int size){
  Libro* aux = calloc(size,sizeof(Libro));
  if(aux==NULL){
    printf("Error de memoria\n");
    exit(-1);
  }
  FILE* f=openread(namefile);
    fread(aux, sizeof(Libro), size, f);
  
  fclose(f);
  return aux;
}

void listBooks(char* namefile){
  int size = countBooks(namefile);
  Libro* aux = libraryArray(namefile,size);
  for(int i=0; i<size;i++){
    printf("Titulo: %s\nAutor: %s\nPrecio: %f\nUnidades disponibles: %d\n\n",
    aux[i].title, aux[i].author, aux[i].cost, aux[i].stock);
  }
  free(aux);
}

//FUNCIÓN PARA VENDER LIBROS
void sellBook(char* namefile, char* title){
  int i, size=countBooks(namefile), found = 0;
  Libro* aux=libraryArray(namefile, size);
  FILE* f = fopen(namefile, "wb");
  for(i = 0; i<size; i++){
    if(compare(aux[i].title, title)){
      aux[i].stock --;
      found = 1;
    }
    fseek(f, -(int)sizeof(Libro), SEEK_CUR);
    fwrite(aux, sizeof(Libro), 1, f);
  }
  if(found) printf("Libro vendido. \n");
  else printf("Libro no existe.\n");
  free(aux);
}
//FUNCIÓN PARA BORRAR TODOS LOS LIBROS FUERA DE STOCK
void clear(char* namefile){
  int i, size = countBooks(namefile);
  Libro* aux = libraryArray(namefile, size);
  FILE* f=fopen(namefile, "wb");
  for(i=0; i<size;i++){
    if(aux[i].stock>0){
      fwrite(aux, sizeof(Libro), 1, f);
    }
  }
  fclose(f);
  free(aux);
}
