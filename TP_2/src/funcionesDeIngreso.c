#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionesDeIngreso.h"

static int MiFgets(char*,int);
static int MiFgets(char* string, int size)
{
	int retorno = -1;
	char bufferString[4000]; //char* bufferString = malloc(sizeof(char)*size); strnlen(bufferString,sizeof(bufferString)) > size

	if(string != NULL && size > 0)
	{
		fflush(stdin);
		if( fgets(bufferString,sizeof(bufferString),stdin) != NULL &&
		    strnlen(bufferString,sizeof(bufferString)) <= size)
		{
			if(bufferString[strnlen(bufferString,sizeof(bufferString))-1] == '\n')
			{
				bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
			}

			if(strnlen(bufferString,sizeof(bufferString)) <= size)
			{
				strncpy(string,bufferString,size);
				retorno = 0;
			}
		}
	}

	return retorno;
}

//----------------------------------------------

static int EsInt(char*,int);
static int EsInt(char* string, int size)
{
	int retorno;

	retorno = -1;

	if(string != NULL && size > 0)
	{
		for(int i=0;i<size && string[i] != '\0';i++)
		{
			if(i==0 && (string[i] == '+' || string[i] == '-'))
			{
				continue;
			}

			if(string[i] > '9' || string[i] < '0')
			{
				retorno = 0;
				break;
			}

			retorno = 1;
		}
	}

	return retorno;
}

//----------------------------------------------

static int EsFloat(char*,int);
static int EsFloat(char* string, int size)
{
	int retorno;
	char seIngresoComa;

	retorno = -1;

	seIngresoComa = 'n';

	if(string != NULL && size > 0)
	{
		for(int i=0;i<size && string[i] != '\0';i++)
		{
			if(i == 0 && (string[i] == '+' || string[i] == '-'))
			{
				continue;
			}

			if(i != 0 && (string[i-1] <= '9' && string[i-1] >= '0') && string[i] == '.' && seIngresoComa == 'n')
			{
				seIngresoComa = 's';
				continue;
			}

			if(string[i] > '9' || string[i] < '0')
			{
				retorno = 0;
				break;
			}

			retorno = 1;
		}
	}

	return retorno;
}

//----------------------------------------------

static int EsAlfabetico(char*,int,char);
static int EsAlfabetico(char* string, int size, char extendido)
{
	int retorno;

	retorno = -1;

	if(string != NULL && size > 0)
	{
		for(int i=0;i<size && string[i] != '\0';i++)
		{
			if( extendido == 's' &&
			   (string[i] == 'ü' || string[i] == 'é' || string[i] == 'ä' ||
				string[i] == 'ë' || string[i] == 'ï' || string[i] == 'Ä' ||
				string[i] == 'É' || string[i] == 'ö' || string[i] == 'Ö' ||
				string[i] == 'Ü' || string[i] == 'á' || string[i] == 'í' ||
				string[i] == 'ó' || string[i] == 'ú' || string[i] == 'ñ' ||
				string[i] == 'Ñ' || string[i] == 'Á' || string[i] == 'Ë' ||
				string[i] == 'Í' || string[i] == 'Ï' || string[i] == 'Ó' ||
				string[i] == 'Ú'))
			{
				continue;
			}

			if(i != 0 && string[i] == ' ')
			{
				continue;
			}

			if(string[i] < 'A' || (string[i] > 'Z' && string[i] < 'a') || string[i] > 'z')
			{
				retorno = 0;
				break;
			}

			retorno = 1;
		}
	}

	return retorno;
}

//----------------------------------------------

static int EsAlfaNumerico(char*,int,char);
static int EsAlfaNumerico(char* string, int size, char extendido)
{
	int retorno;

	retorno = -1;

	if(string != NULL && size > 0)
	{
		for(int i=0;i<size && string[i] != '\0';i++)
		{
			if( extendido == 's' &&
			   (string[i] == 'ü' || string[i] == 'é' || string[i] == 'ä' ||
				string[i] == 'ë' || string[i] == 'ï' || string[i] == 'Ä' ||
				string[i] == 'É' || string[i] == 'ö' || string[i] == 'Ö' ||
				string[i] == 'Ü' || string[i] == 'á' || string[i] == 'í' ||
				string[i] == 'ó' || string[i] == 'ú' || string[i] == 'ñ' ||
				string[i] == 'Ñ' || string[i] == 'Á' || string[i] == 'Ë' ||
				string[i] == 'Í' || string[i] == 'Ï' || string[i] == 'Ó' ||
				string[i] == 'Ú'))
			{
				continue;
			}

			if(i != 0 && string[i] == ' ')
			{
				continue;
			}

			if( string[i] < '0' || (string[i] > '9' && string[i] < 'A') ||
			   (string[i] > 'Z' && string[i] < 'a') || string[i] > 'z')
			{
				printf("Entro");
				retorno = 0;
				break;
			}

			retorno = 1;
		}
	}

	return retorno;
}

//----------------------------------------------

static int ObtenerStringInt(int*);
static int ObtenerStringInt(int* direccionBuffer)
{
	int retorno = -1;
	char bufferString[50];

	if( direccionBuffer != NULL &&
		MiFgets(bufferString,sizeof(bufferString)) == 0 &&
		EsInt(bufferString,sizeof(bufferString)) == 1)
	{
		retorno = 0;
		*direccionBuffer = atoi(bufferString);
	}

	return retorno;
}

//----------------------------------------------

static int ObtenerStringFloat(float*);
static int ObtenerStringFloat(float* direccionBuffer)
{
	int retorno = -1;
	char bufferString[50];

	if( direccionBuffer != NULL &&
		MiFgets(bufferString,sizeof(bufferString)) == 0 &&
		EsFloat(bufferString,sizeof(bufferString)) == 1)
	{
		retorno = 0;
		*direccionBuffer = atof(bufferString);
	}

	return retorno;
}

//----------------------------------------------

static int ObtenerCharAlfabetico(char*,int,char);
static int ObtenerCharAlfabetico(char* buffer, int size, char extendido)
{
	int retorno = -1;
	char bufferString[size]; //100

	if( buffer != NULL &&
		MiFgets(bufferString,sizeof(bufferString)) == 0 &&
		EsAlfabetico(bufferString,sizeof(bufferString),extendido) == 1)
	{
		retorno = 0;
		snprintf(buffer,size,"%s",bufferString);
	}

	return retorno;
}

//----------------------------------------------

static int ObtenerCharAlfaNumerico(char*,int,char);
static int ObtenerCharAlfaNumerico(char* buffer, int size, char extendido)
{
	int retorno = -1;
	char bufferString[size]; //100

	if( buffer != NULL &&
		MiFgets(bufferString,sizeof(bufferString)) == 0 &&
		EsAlfaNumerico(bufferString,sizeof(bufferString),extendido) == 1)
	{
		retorno = 0;
		snprintf(buffer,size,"%s",bufferString);
	}

	return retorno;
}

//----------------------------------------------

int ObtenerInt(int* direccion, int minimo, int maximo, char mensaje[], char mensajeError[], int reintentos)
{
	int retorno = -1;
	int buffer;

	if(direccion != NULL && minimo <= maximo && mensaje != NULL && mensajeError != NULL && reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);
			if( ObtenerStringInt(&buffer) == 0 &&
				buffer >= minimo &&
				buffer <= maximo)
			{
				retorno = 0;
				*direccion = buffer;
				break;
			}

			reintentos--;
			if(reintentos < 0)
			{
				printf("ERROR, No le quedan mas intentos (Saliendo...)\n");
				break; //exit(-1);
			}
			printf("%s (Le quedan %d reintentos)\n",mensajeError,reintentos+1);

		}while(reintentos>=0);
	}

	return retorno;
}

//----------------------------------------------

int ObtenerFloat(float* direccion, float minimo, float maximo, char mensaje[], char mensajeError[], int reintentos)
{
	int retorno = -1;
	float buffer;

	if(direccion != NULL && minimo <= maximo && mensaje != NULL && mensajeError != NULL && reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);
			if( ObtenerStringFloat(&buffer) == 0 &&
				buffer >= minimo &&
				buffer <= maximo)
			{
				retorno = 0;
				*direccion = buffer;
				break;
			}

			reintentos--;
			if(reintentos < 0)
			{
				printf("ERROR, No le quedan mas intentos (Saliendo...)\n");
				break; //exit(-1);
			}
			printf("%s (Le quedan %d reintentos)\n",mensajeError,reintentos+1);

		}while(reintentos>=0);
	}

	return retorno;
}

//----------------------------------------------

int ObtenerStringAlfabetico(char* vector, int size, char mensaje[], char mensajeError[], int reintentos, char extendido)
{
	int retorno = -1;
	char buffer[size];

	if(vector != NULL && mensaje != NULL && mensajeError != NULL && reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);
			if(ObtenerCharAlfabetico(buffer,size,extendido) == 0)
			{
				retorno = 0;
				strncpy(vector,buffer,size);
				break;
			}

			reintentos--;
			if(reintentos < 0)
			{
				printf("ERROR, No le quedan mas intentos (Saliendo...)\n");
				break; //exit(-1);
			}
			printf("%s (Le quedan %d reintentos)\n",mensajeError,reintentos+1);

		}while(reintentos>=0);
	}

	return retorno;
}

//----------------------------------------------

int ObtenerStringAlfaNumerico(char* vector, int size, char mensaje[], char mensajeError[], int reintentos, char extendido)
{
	int retorno = -1;
	char buffer[size];

	if(vector != NULL && mensaje != NULL && mensajeError != NULL && reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);
			if(ObtenerCharAlfaNumerico(buffer,size,extendido) == 0)
			{
				retorno = 0;
				strncpy(vector,buffer,size);
				break;
			}

			reintentos--;
			if(reintentos < 0)
			{
				printf("ERROR, No le quedan mas intentos (Saliendo...)\n");
				break; //exit(-1);
			}
			printf("%s (Le quedan %d reintentos)\n",mensajeError,reintentos+1);

		}while(reintentos>=0);
	}

	return retorno;
}

//----------------------------------------------

int ObtenerCharDosOpciones(char* direccion, char opcionUno, char opcionDos, char mensaje[], char mensajeError[], int reintentos)
{
	int retorno = -1;
	char buffer;

	if(direccion != NULL && mensaje != NULL && mensajeError != NULL && reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);
			fflush(stdin);
			scanf("%c",&buffer);
			if(buffer == opcionUno || buffer == opcionDos)
			{
				retorno = 0;
				*direccion = buffer;
				break;
			}

			reintentos--;
			if(reintentos < 0)
			{
				printf("ERROR, No le quedan mas intentos (Saliendo...)\n");
				break; //exit(-1);
			}
			printf("%s (Le quedan %d reintentos)\n",mensajeError,reintentos+1);

		}while(reintentos>=0);
	}

	return retorno;
}

//----------------------------------------------

int ObtenerFecha(int* dia, int* mes, int* anio, int anioMinimo, int anioMaximo)
{
	int bufferMes;
	int bufferDia;
	int bufferAnio;
	int retorno;

	retorno = -1;
	bufferMes = -1;
	bufferDia = -1;
	bufferAnio = -1;

	ObtenerInt(&bufferMes, 1, 12, "Ingrese el mes:", "ERROR, Ingrese el mes: ", 4);

	switch(bufferMes)
	{
		case 2:
			ObtenerInt(&bufferDia, 1, 28, "Ingrese el dia: ", "ERROR, El mes solo tiene 28 dias. Ingrese el dia: ", 4);
		break;

		case 4:
		case 7:
		case 9:
		case 11:
			ObtenerInt(&bufferDia, 1, 30, "Ingrese el dia: ", "ERROR, El mes solo tiene 30 dias. Ingrese el dia: ", 4);
		break;

		default:
			ObtenerInt(&bufferDia, 1, 31, "Ingrese el dia: ", "ERROR, El mes solo tiene 31 dias. Ingrese el dia: ", 4);
		break;
	}

	ObtenerInt(&bufferAnio, anioMinimo, anioMaximo, "Ingrese el año: ", "ERROR, Ingrese el año: ", 4);

	if(bufferMes > 0 && bufferDia > 0 && bufferAnio > 0)
	{
		*mes = bufferMes;
		*dia = bufferDia;
		*anio = bufferAnio;
		retorno = 0;
	}

	return retorno;
}
