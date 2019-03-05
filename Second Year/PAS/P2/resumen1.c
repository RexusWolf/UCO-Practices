/*
Ejemplo extraído del estándar POSIX y glibc.
Enlace a la página de documentación de la implemencación de getopt de glibc:
http://pubs.opengroup.org/onlinepubs/9699919799/functions/getopt.html
http://www.gnu.org/software/libc/manual/html_node/Getopt.html
http://www.gnu.org/software/libc/manual/html_node/Example-of-Getopt.html
*/

#include <unistd.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char **argv)
{
    int aflag = 0;
    int bflag = 0;
    char *cvalue = NULL;
    int index;
    int c;
    char *lang = "LANG";
    char *home = "HOME";
    char *value;

    /* IMPORTANTE:
     Las variables optind, optarg, opterr y optopt son variables externas incluidas en <unistd.h> */

    /*
     If getopt() does not recognize an option character, it prints an error message to stderr,
     stores the character in optopt, and returns '?'. The calling program may prevent the error
     message by setting opterr to 0 */
    //Prueba a ejecutar el programa comentando esta linea, podrás observar como se obtiene un
    // error por defecto por la salida estandar, en este caso el terminal.
    opterr = 0;

    // "abc:" -> busca como opciones a y b sin argumentos y c con un argumento OBLIGATORIO.
    // ':' indica que la opcion debe llevar un argumento obligario

    // getopt va iterando, y devuelve -1 si ya hemos consultado toda la linea de argumentos.
    // Sino, devuelve el caracter de opción encontrado para caracteres validos
    // o devuelve ? si el caracter no es valido segun la cadena especificada.
    while ((c = getopt (argc, argv, "uigdsabh")) != -1)
    {
        // Podemos observar qué pasa con las variables externas que va gestionando
        //   getopt() durante las sucesivas llamadas.
        //   - optind: Indice del siguiente elemento a procesar del vector argv[]
        //   - optarg: recoge el valor del argumento obligario de una opcion.
        //   - optopt: recoge el valor de la opcion cuando es desconocida (?) o INCOMPLETA respecto a las opciones indicadas.

        // Modificar para que indique opciones reconocidas/ordene opciones por existencia.
        switch (c)
        {
		     case 'u':
		         break;
         case 'i':
    		     break;
         case 'g':
             break;
         case 'd':
             break;
         case 's':
             break;
         case 'a':
             break;
		     case 'b':
		         break;
		     case 'h':
		         break;
		     case '?': //Opcion no reconocida o INCOMPLETA (sin argumento). Probar tambien la diferencia entre ejecutar %$>./a.out m   ó   %$>./a.out -m
		         if (isprint (optopt)) //Se mira si el caracter es imprimible
		             fprintf (stderr, "Opción desconocida \"-%c\". Valor de opterr = %d\n", optopt, opterr);
		         else //Caracter no imprimible o especial
		             fprintf (stderr, "Caracter `\\x%x'. Valor de opterr = %d\n", optopt, opterr);
		         return 1;  //Finaliza el programa
		     default:
             abort();
        }
        printf("optind: %d, optarg: %s, optopt: %c, opterr: %d\n\n", optind, optarg, optopt, opterr);
    }

    //Este último bucle controla opciones introducidas por el usuario que no hayan sido procesadas
    //por ser no reconocidas al no llevar un guion "-" delante.
    //Compara el número de argumentos recibidos con el número de opciones reconocidas mediante "-".
    //Como getopt() internamente reordena los valores de argv, las primeras posiciones de argv
    //corresponden a opciones conocidas y las últimas, a partir de optind, a opciones no reconocidas.

    for (index = optind; index < argc; index++)
        printf ("Argumento \"%s\" de la línea de comandos que NO ES UNA OPCIÓN.\n\n", argv[index]);

    // El siguiente condicional permitiría dar un valor por defecto a la opción c.
    // Comprueba y razona si se llegaría a ejecutar y en qué circunstancias
    if(cvalue==NULL)
        value = getenv(lang);

        if (strstr(value,"ES"))
        {
            printf("\nLa carpeta del usuario/a es: %s\n", getenv(home));
        }
        else
        {
            printf("\nUser's home folder is: %s\n", getenv(home));
        }
    return 0;
}
