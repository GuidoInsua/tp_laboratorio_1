#include <stdio.h>
#include <stdlib.h>

#include "funcionesDeIngreso.h"

char IngresarEntero(int* direccion, int minimo, int maximo, char mensaje[], char mensajeError[], int reintentos)
{
	int buffer;
	char retorno;

	retorno = 'n';

	if(direccion != NULL && minimo <= maximo && mensaje != NULL && mensajeError != NULL && reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);
			scanf("%d",&buffer);
			if(buffer >= minimo && buffer <= maximo)
			{
				*direccion = buffer;
				retorno = 's';
				break;
			}

			reintentos--;
			if(reintentos < 0)
			{
				printf("ERROR, No le quedan mas intentos (El programa se cerro)");
				exit(-1);
			}
			printf("%s (Le quedan %d reintentos)\n",mensajeError,reintentos+1);

		}while(reintentos>=0);
	}

	return retorno;
}

//----------------------------------------------------------------------------

char IngresarFlotante(float* direccion, int minimo, int maximo, char mensaje[], char mensajeError[], int reintentos)
{
	float buffer;
	char retorno;

	retorno = 'n';

	if(direccion != NULL && minimo <= maximo && mensaje != NULL && mensajeError != NULL && reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);
			scanf("%f",&buffer);
			if(buffer >= minimo && buffer <= maximo)
			{
				*direccion = buffer;
				retorno = 's';
				break;
			}

			reintentos--;
			if(reintentos < 0)
			{
				printf("\nERROR, No le quedan mas intentos (Volviendo al Menu)\n");
				break;
			}
			printf("%s (Le quedan %d reintentos)\n",mensajeError,reintentos+1);

		}while(reintentos>=0);
	}

	return retorno;
}


