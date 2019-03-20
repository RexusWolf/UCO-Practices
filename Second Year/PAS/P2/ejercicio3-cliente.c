/*
Cliente que envia por una cola abierta para escritura una cadena de caracteres
recogida por teclado, mientras que el valor de esa cadena sea distinto a la palabra exit
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

//Prototipo de funcion
void funcionLog(char *);
// Apuntador al fichero de log. No se usa en este ejemplo, pero le servira en ejercicio resumen
FILE *fLog = NULL;

int main(int argc, char **argv)
{
	// Cola del servidor
	mqd_t mq_server;
	// Cola del cliente
	mqd_t mq_client;
	// Atributos de la cola
	struct mq_attr attr;
	// Buffer para intercambiar mensajes de Emparejamiento
	char bufferclient[MAX_SIZE + 1];
	// Buffer para intercambiar mensajes
	char buffer[MAX_SIZE];
	// flag que indica cuando hay que parar. Se escribe palabra exit
	int must_stop = 0;
	// Inicializar los atributos de la cola
	attr.mq_maxmsg = 10;        // Maximo número de mensajes
	attr.mq_msgsize = MAX_SIZE; // Maximo tamaño de un mensaje

	// Abrir la cola del servidor.
	// No es necesario crearla si se lanza primero el servidor, sino el programa no funciona.
	mq_server = mq_open(SERVER_QUEUE, O_WRONLY);
	if(mq_server == (mqd_t)-1 )
	{
      perror("Error al abrir la cola del servidor");
      exit(-1);
	}

	// Crear la cola de mensajes del cliente. La cola CLIENT_QUEUE le servira en ejercicio resumen
	mq_client = mq_open(CLIENT_QUEUE, O_CREAT | O_RDONLY, 0644, &attr);
	if(mq_client == (mqd_t)-1 )
	{
		perror("Error al abrir la cola del cliente");
			exit(-1);
	}

	printf("Mandando mensajes al servidor (escribir \"%s\" para parar):\n", MSG_STOP);
	do
	{
		printf("> ");

		/* Leer por teclado. Según la documentación, fgets lo hace de esta manera:
		It stops when either (n-1) characters are read, the newline character is read,
		or the end-of-file is reached, whichever comes first.
		Automáticamente fgets inserta el fin de cadena '\0'
		*/
		fgets(buffer, MAX_SIZE, stdin);

		// Enviar y comprobar si el mensaje se manda
		if(mq_send(mq_server, buffer, MAX_SIZE, 0) != 0)
		{
			perror("Error al enviar el mensaje");
			exit(-1);
		}
	// Iterar hasta escribir el código de salida
	}while (strncmp(buffer, MSG_STOP, strlen(MSG_STOP)));



	do
	{
		// Número de bytes leidos
		ssize_t bytes_read;

		// Recibir el mensaje
		bytes_read = mq_receive(mq_client, bufferclient, MAX_SIZE, NULL);
		// Comprobar que la recepción es correcta (bytes leidos no son negativos)
		if(bytes_read < 0)
		{
			perror("Error al recibir el mensaje");
			exit(-1);
		}

		// Cerrar la cadena
		//buffer[bytes_read] = '\0';

		// Comprobar el fin del bucle
		if (strncmp(bufferclient, MSG_STOP, strlen(MSG_STOP))==0)
			must_stop = 1;
		else
			printf("Recibido el mensaje: %s\n", bufferclient);
	}while(!must_stop);
		// Iterar hasta que llegue el código de salida, es decir, la palabra exit

		// Cerrar la cola del servidor
		if(mq_close(mq_server) == (mqd_t)-1)
		{
			perror("Error al cerrar la cola del servidor");
			exit(-1);
		}

		// Cerrar la cola del cliente
		if(mq_close(mq_client) == (mqd_t)-1)
		{
			perror("Error al cerrar la cola del cliente");
			exit(-1);
		}

		// Eliminar la cola del cliente
		if(mq_unlink(CLIENT_QUEUE) == (mqd_t)-1)
		{
			perror("Error al eliminar la cola del cliente");
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
	sprintf(nombreFichero,"log-cliente.txt");
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
