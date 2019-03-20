/*
Servidor que lee de una cola abierta para lectura una cadena de caracteres y la
imprime por pantalla.

Lo hace mientras que el valor de esa cadena sea distinto a la palabra exit.
*/


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <mqueue.h>
#include <time.h>
#include <errno.h>
#include "common.h"
#include <regex.h> // Libreria regex

//Prototipo de funcionn
void funcionLog(char *);
// Apuntador al fichero de log.  No se usa en este ejemplo, pero le servira en ejercicio resumen
FILE *fLog = NULL;

int main(int argc, char **argv)
{
	// Cola del servidor
	mqd_t mq_server;
	// Cola del cliente
	mqd_t mq_client;
	// Atributos de la cola
	struct mq_attr attr;
	// Buffer para intercambiar mensajes
	char buffer[MAX_SIZE + 1];
	char bufferclient[MAX_SIZE];
	// flag que indica cuando hay que parar. Se escribe palabra exit
	int must_stop = 0;
	// Inicializar los atributos de la cola
	attr.mq_maxmsg = 10;        // Maximo número de mensajes
	attr.mq_msgsize = MAX_SIZE; // Maximo tamaño de un mensaje

	regex_t regex;
	int reti;
	char msgbuf[100];

	/* Compile regular expression */
  reti = regcomp(&regex, "ola", 0);
  if( reti ){ fprintf(stderr, "Could not compile regex\n"); exit(1); }

	// Crear la cola de mensajes del servidor. La cola CLIENT_QUEUE le servira en ejercicio resumen
	mq_server = mq_open(SERVER_QUEUE, O_CREAT | O_RDONLY, 0644, &attr);
	if(mq_server == (mqd_t)-1 )
	{
   	perror("Error al abrir la cola del servidor");
      exit(-1);
	}

	// Abrir la cola del cliente. La cola CLIENT_QUEUE le servira en ejercicio resumen.
	// No es necesario crearla si se lanza primero el cliente, sino el programa no funciona.
	mq_client = mq_open(CLIENT_QUEUE, O_WRONLY);
	if(mq_client == (mqd_t)-1 )
	{
			perror("Error al abrir la cola del cliente");
			exit(-1);
	}

	do
	{
		// Número de bytes leidos
		ssize_t bytes_read;

		// Recibir el mensaje
		bytes_read = mq_receive(mq_server, buffer, MAX_SIZE, NULL);
		// Comprobar que la recepción es correcta (bytes leidos no son negativos)
		if(bytes_read < 0)
		{
			perror("Error al recibir el mensaje");
			exit(-1);
		}

		// Cerrar la cadena
		//buffer[bytes_read] = '\0';

		// Comprobar el fin del bucle
		if (strncmp(buffer, MSG_STOP, strlen(MSG_STOP))==0)
			must_stop = 1;
		else{
			printf("Recibido el mensaje: %s", buffer);

			/* Execute regular expression */
      reti = regexec(&regex, buffer , 0, NULL, 0);
      if( !reti ){
              puts("Match\n");
							char cad[20] = "Empareja";
							strcpy(bufferclient, cad);
      }
      else if( reti == REG_NOMATCH ){
              puts("No match");
							char cad[20] = "No empareja";
							strcpy(bufferclient, cad);
      }
      else{
              regerror(reti, &regex, msgbuf, sizeof(msgbuf));
              fprintf(stderr, "Regex match failed: %s\n", msgbuf);
              exit(1);
      }

			// Enviar y comprobar si el mensaje se manda
			if(mq_send(mq_client, bufferclient, MAX_SIZE, 0) != 0)
			{
				perror("Error al enviar el mensaje");
				exit(-1);
			}
		}
	} while (!must_stop); 	// Iterar hasta que llegue el código de salida, es decir, la palabra exit


	/* Free compiled regular expression if you want to use the regex_t again */
	regfree(&regex);

	// Cerrar la cola del servidor
	if(mq_close(mq_server) == (mqd_t)-1)
	{
		perror("Error al cerrar la cola del servidor");
		exit(-1);
	}

	// Cerrar la cola del servidor
	if(mq_close(mq_client) == (mqd_t)-1)
	{
		perror("Error al cerrar la cola del cliente");
		exit(-1);
	}

	// Eliminar la cola del servidor
	if(mq_unlink(SERVER_QUEUE) == (mqd_t)-1)
	{
		perror("Error al eliminar la cola del servidor");
		exit(-1);
	}

	return 0;
}


/* Función auxiliar, escritura de un log.
No se usa en este ejemplo, pero le puede servir para algun
ejercicio resumen */
void funcionLog(char *mensaje)
{
	int resultado;
	char nombreFichero[100];
	char mensajeAEscribir[300];
	time_t t;

	// Abrir el fichero
	sprintf(nombreFichero,"log-servidor.txt");
	if(fLog==NULL)
	{
		fLog = fopen(nombreFichero,"at");
		if(fLog==NULL)
		{
			perror("Error abriendo el fichero de log");
			exit(1);
		}
	}

	// Obtener la hora actual
	t = time(NULL);
	struct tm * p = localtime(&t);
	strftime(mensajeAEscribir, 1000, "[%Y-%m-%d, %H:%M:%S]", p);

	// Vamos a incluir la hora y el mensaje que nos pasan
	sprintf(mensajeAEscribir, "%s ==> %s\n", mensajeAEscribir, mensaje);

	// Escribir finalmente en el fichero
	resultado = fputs(mensajeAEscribir,fLog);
	if (resultado < 0)
		perror("Error escribiendo en el fichero de log");

	fclose(fLog);
	fLog=NULL;
}
