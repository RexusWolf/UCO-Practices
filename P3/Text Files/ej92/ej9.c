#include "funciones.h"

int main(int argc, char const *argv[]) {

  char* namefile = argv[1];
  char title[50];
  int option;
  printf("Introduce opción:\n");
  printf("1. Add Book.\n");
  printf("2. Check Book.\n");
  printf("3. Count Books.\n");
  printf("4. List Books.\n");
  printf("5. Sell Book.\n");
  printf("6. Clear stock.\n");
  printf("0. Exit.\n");
  scanf("%d", &option );
  fgetc(stdin);
  switch (option) {
    case 1: addBook(namefile);
    break;

    case 2:
     printf("Introduce titulo:\n");
     fgets(title, 50, stdin);
     changeChar(title);
       if(checkBook(namefile, title)) printf("Libro encontrado.\n");
       else printf("Libro no encontrado.\n");
    break;

    case 3: printf("Hay %d libros.\n", countBooks(namefile));
    break;

    case 4: listBooks(namefile);
    break;
    case 5:
      printf("Introduce titulo:\n");
      fgets(title, 50, stdin);
      changeChar(title);
      sellBook(namefile, title);
    break;

    case 6: clearBooks(namefile);
    break;

    case 0: exit(-1);
    break;
  }

    return 0;
}
