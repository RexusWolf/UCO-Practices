/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "prueba.h"

int *
suma_1_svc(operandos *argp, struct svc_req *rqstp)
{
	static int result;

	result = argp->a + argp->b;

	return &result;
}

int *
multiplicacion_1_svc(operandos *argp, struct svc_req *rqstp)
{
	static int  result;

	result = argp->a * argp->b;

	return &result;
}

int *
division_1_svc(operandos *argp, struct svc_req *rqstp)
{
	static int result;
	
	result = argp->a / argp->b;

	return &result;
}