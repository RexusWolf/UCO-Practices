/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "prueba.h"
#include <time.h> // Library for clock() and CLOCKS_PER_SEC


void
calculadora_prog_1(char *host, char *operation, int operandoA, int operandoB)
{
	CLIENT *clnt;
	int  *result_1, operationParsedToInt;
	operandos suma_1_arg;
	operandos multiplicacion_1_arg;
	operandos division_1_arg;
	clock_t startTime, endTime;
#ifndef	DEBUG
	clnt = clnt_create (host, CALCULADORA_PROG, CALCULADORA_VERS, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */
	
	if(strcmp ("SUMA", operation) == 0){
		operationParsedToInt = 1;
	}
	else if(strcmp ("MULTIPLICACION", operation) == 0){
		operationParsedToInt = 0;
	}
	else if(strcmp ("DIVISION", operation) == 0){
		operationParsedToInt = 2;
	}
	else{
		printf("Las operaciones permitidas son SUMA, MULTIPLICACIÓN y DIVISION");
		exit(0);
	}

	
	switch (operationParsedToInt)
	{
	case 0:
		suma_1_arg.a = operandoA;
		suma_1_arg.b = operandoB;
		result_1 = suma_1(&suma_1_arg, clnt);
		break;

	case 1:
		multiplicacion_1_arg.a = operandoA;
		multiplicacion_1_arg.b = operandoB;
		result_1 = multiplicacion_1(&multiplicacion_1_arg, clnt);
		break;

	case 2:
		if(operandoB == 0){
			printf("No puedes dividir entre 0");
			exit(0);
		}
		division_1_arg.a = operandoA;
		division_1_arg.b = operandoB;
		result_1 = division_1(&division_1_arg, clnt);
		break;
	
	default:
		break;
	}

	if (result_1 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	}

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
