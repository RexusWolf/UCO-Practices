/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "prueba.h"
#include <time.h> // Library for clock() and CLOCKS_PER_SEC


void
calculadora_prog_1(char *host, char *operacion, int operandoA, int operandoB)
{
	CLIENT *clnt;
	int  *result_1;
	operandos  suma_1_arg;
	int  *result_2;
	operandos  multiplicacion_1_arg;
	clock_t startTime, endTime;  

#ifndef	DEBUG
	clnt = clnt_create (host, CALCULADORA_PROG, CALCULADORA_VERS, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */


	startTime = clock();
%d
	for (int i = 0; i < 100000; i++) {
		if(strcmp ("MULTIPLICACION", operacion) == 0){
		multiplicacion_1_arg.a = operandoA;
		multiplicacion_1_arg.b = operandoB;
		result_1 = multiplicacion_1(&multiplicacion_1_arg, clnt);
		}
		else if(strcmp ("SUMA", operacion) == 0){
			suma_1_arg.a = operandoA;
			suma_1_arg.b = operandoB;
			result_1 = suma_1(&suma_1_arg, clnt);
		}
		else{
			printf("Las operaciones permitidas son SUMA y MULTIPLICACIÓN");
			exit(0);
		}
		if (result_1 == (int *) NULL) {
			clnt_perror (clnt, "call failed");
		}
	}
	
	endTime = clock();
	float totalTime = ((float)(endTime - startTime) / CLOCKS_PER_SEC);   
	printf("El programa ha tardado %f milisegundos en ejecutarse. resultado = %d", totalTime, *result_1);

#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}


int
main (int argc, char *argv[])
{
	char *host;

	if (argc < 2) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}
	host = argv[1];
	calculadora_prog_1 (host, argv[2] ,atoi(argv[3]), atoi(argv[4]) );
exit (0);
}
