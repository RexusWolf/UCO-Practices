// Autor: Francisco Javier Molina Prieto

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>
#include <pwd.h>
#include <grp.h>

int main (int argc, char **argv)
{
	int c;

  /* Estructura a utilizar por getoptlong */
  static struct option long_options[] =
  {
    /* Opciones que no van a actuar sobre un flag */
    /* "opcion", recibe o no un argumento, 0,
       identificador de la opción */
    {"username",	 required_argument,	   0, 'u'},
    {"useruid",  required_argument,	   0, 'i'},
    {"groupname",  required_argument, 0, 'g'},
    {"groupuid",  required_argument, 0, 'd'},
    {"allgroups",	no_argument, 0, 's'},
    {"allinfo",	no_argument, 0, 'a'},
    {"bactive",	no_argument, 0, 'b'},
    {"help",	no_argument, 0, 'h'},
    /* Necesario para indicar el final de las opciones */
    {0, 0, 0, 0}
  };

	/* Estas variables servirán para almacenar el resultado de procesar la línea de comandos */
	int aflag = 0;
	int bflag = 0;
	char *cvalue = NULL;
	char *dvalue = NULL;
	char *fvalue = NULL;
  // Variables de entorno
  char *lang = "LANG";
  char *home = "HOME";
  char *value;
  // Declaracion de las estructuras que almacenaran la informarcion de un usuario y de un grupo
  struct passwd *pw;
  struct group *gr;
  char *lgn;
  int uid;
  int guid;
  FILE * file;

	/* getopt_long guardará el índice de la opción en esta variable. */
	int option_index = 0;

	/* Deshabilitar la impresión de errores por defecto */
	/* opterr=0; */
	while ((c = getopt_long (argc, argv, "u:i:g:d:sa:bh", long_options, &option_index))!=-1)
	{
		/* El usuario ha terminado de introducir opciones */
		if (c == -1)
			break;
		switch (c)
		{
      case 'u':
						if(argc == 3){
		          lgn = argv[2];

		          if ((pw = getpwnam(lgn)) == NULL) //DEVUELVE LA ESTRUCTURA TRAS RECIBIR lgn COMO PARÁMETRO
		          {
		              fprintf(stderr, "Get of user information failed.\n");
		              exit(1);
		          }
		          //Aqui ya se dispone de la estructura que contiene informacion del usuario
		          printf("Nombre: %s\n", pw->pw_gecos); //No es lo mismo el nombre de usuario asociado a un login que el propio login
		          printf("Login: %s\n", pw->pw_name);
		          printf("Password: %s\n", pw->pw_passwd);
		          printf("UID: %d\n", pw->pw_uid);
		          printf("Home: %s\n", pw->pw_dir);
		          printf("Número de grupo principal: %d\n", pw->pw_gid);
					}
					else{
						printf("Número de argumentos incorrecto.\n");
					}

          break;
      case 'i':
						if(argc == 3){
		          uid = atoi(argv[2]);

		          if ((pw = getpwuid(uid)) == NULL) //DEVUELVE LA ESTRUCTURA TRAS RECIBIR lgn COMO PARÁMETRO
		          {
		              fprintf(stderr, "Get of user information failed.\n");
		              exit(1);
		          }
		          //Aqui ya se dispone de la estructura que contiene informacion del usuario
		          printf("Nombre: %s\n", pw->pw_gecos); //No es lo mismo el nombre de usuario asociado a un login que el propio login
		          printf("Login: %s\n", pw->pw_name);
		          printf("Password: %s\n", pw->pw_passwd);
		          printf("UID: %d\n", pw->pw_uid);
		          printf("Home: %s\n", pw->pw_dir);
		          printf("Número de grupo principal: %d\n", pw->pw_gid);
					}
					else{
						printf("Número de argumentos incorrecto.\n");
					}
          break;
      case 'g':
					if(argc==3){
	          lgn = argv[2];
	          if ((pw = getpwnam(lgn)) == NULL) //DEVUELVE LA ESTRUCTURA TRAS RECIBIR lgn COMO PARÁMETRO
	          {
	              fprintf(stderr, "Get of group information failed.\n");
	              exit(1);
	          }

	          // Obtenemos la estructura de información del grupo a través del número de grupo al que pertenece el usuario
	          gr = getgrgid(pw->pw_gid);
	          //Se imprime el campo de la estructura que nos interesa
	          printf("Número de grupo principal: %d\n", pw->pw_gid);
	          printf("Nombre del grupo principal: %s\n", gr->gr_name);
					}
					else{
						printf("Número de argumentos incorrecto.\n");
					}
          break;
      case 'd':
					if(argc==3){
					  guid = atoi(argv[2]);
	          if ((gr = getgrgid(guid)) == NULL) //DEVUELVE LA ESTRUCTURA TRAS RECIBIR lgn COMO PARÁMETRO
	          {
	              fprintf(stderr, "Get of group information failed.\n");
	              exit(1);
	          }

	          //Se imprime el campo de la estructura que nos interesa
	          printf("Nombre del grupo principal: %s\n", gr->gr_name);
					}
					else{
						printf("Número de argumentos incorrecto.\n");
					}
          break;
      case 's':
          if((file = fopen("/etc/group", "r")) == NULL){
            printf("Error en la apertura del archivo");
          }
          else printf("Fichero abierto correctamente.\n");
          char aux[50];

          char* i = fgets(aux, 50, file);

          while(i!=NULL){
						int j = 0;
						char groupname[25] = {};
            i = fgets(aux, 50, file);
						while(aux[j] != ':'){
							groupname[j] = aux[j];
							j++;
						}
						printf("%s\n", groupname );

						if ((pw = getpwnam(groupname)) == NULL) //DEVUELVE LA ESTRUCTURA TRAS RECIBIR lgn COMO PARÁMETRO
	          {
	              fprintf(stderr, "Get of group information failed.\n");
	              exit(1);
	          }

	          // Obtenemos la estructura de información del grupo a través del número de grupo al que pertenece el usuario
	          gr = getgrgid(pw->pw_gid);
	          //Se imprime el campo de la estructura que nos interesa
	          printf("Nombre del grupo principal: %s\n", gr->gr_name);
						printf("Número de grupo principal: %d\n", pw->pw_gid);
						printf("\n");

          }


          fclose(file);
          break;
      case 'a':
					if(argc==3){
						lgn = argv[2];

						if ((pw = getpwnam(lgn)) == NULL) //DEVUELVE LA ESTRUCTURA TRAS RECIBIR lgn COMO PARÁMETRO
						{
								fprintf(stderr, "Get of user information failed.\n");
								exit(1);
						}
						//Aqui ya se dispone de la estructura que contiene informacion del usuario
						printf("Nombre: %s\n", pw->pw_gecos); //No es lo mismo el nombre de usuario asociado a un login que el propio login
						printf("Login: %s\n", pw->pw_name);
						printf("Password: %s\n", pw->pw_passwd);
						printf("UID: %d\n", pw->pw_uid);
						printf("Home: %s\n", pw->pw_dir);
						gr = getgrgid(pw->pw_gid);
						printf("Nombre del grupo principal: %s\n", gr->gr_name);
						printf("Número de grupo principal: %d\n", pw->pw_gid);
					}
					else{
						printf("Numero de argumentos incorrecto.\n");
					}
          break;
      case 'b':
          lgn = getenv("USER");
          if ((pw = getpwnam(lgn)) == NULL) //DEVUELVE LA ESTRUCTURA TRAS RECIBIR lgn COMO PARÁMETRO
          {
              fprintf(stderr, "Get of user information failed.\n");
              exit(1);
          }

          // Obtenemos la estructura de información del grupo a través del número de grupo al que pertenece el usuario
          gr = getgrgid(pw->pw_gid);
          //Se imprime el campo de la estructura que nos interesa
          printf("Número de grupo principal: %d\n", pw->pw_gid);
          printf("Nombre del grupo principal: %s\n", gr->gr_name);
          break;
      case 'h':
         printf("-h, --help  Imprimir esta ayuda\n");
         printf("-u, --username  Imprimir esta ayuda\n");
         printf("-i, --useruid  Imprimir esta ayuda\n");
         printf("-g, --groupname  Imprimir esta ayuda\n");
         printf("-d, --groupuid  Imprimir esta ayuda\n");
         printf("-s, --allgroups  Imprimir esta ayuda\n");
         printf("-a, --allinfo  Imprimir esta ayuda\n");
         printf("-b, --bactive  Imprimir esta ayuda\n");
          break;

			default:
				abort ();
		}
	}

	/* Imprimir el resto de argumentos de la línea de comandos que no son opciones con "-"
	if (optind < argc)
	{
		printf("Argumentos ARGV que no son opciones: ");
		while (optind < argc)
			printf("%s ", argv[optind++]);
		putchar ('\n');
	}

*/

  if(argc == 1)
      value = getenv(lang);

      if (strstr(value,"EN"))
      {
          printf("\nUser's home folder is: %s\n", getenv(home));
      }
      else
      {
        printf("\nLa carpeta del usuario/a es: %s\n", getenv(home));
      }

	exit (0);
}
