//sizeof(string) tamanio de la cadena
//strncpy(destino,fuente,sizeof(destino)) copia en destino la fuente
//strnlen(string,sizeof(string)) que tan lleno eso
//strncat(destino," mensaje",sizeof(destino)) concatena el "mensaje" con destino (tiene que entrar)
//snprintf(destino,sizeof(destino),"Mensaje %d lo que quieras,Numero) pone en destino lo que quieras
//strlwr(string) pasa todo a minuscula
//strupr(string) pasa todo a mayusculas

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funcionesCadenas.h"

int ConvertirUprLwr(char* string, int size)
{
	int retorno = -1;

	if(string != NULL && size > 1)
	{
		retorno = 0;
		strlwr(string);

		for(int i=0;i<size-1;i++)
		{
			if(i==0 && string[0] != ' ')
			{
				string[0] = toupper(string[0]);
			}

			if(string[i] == ' ')
			{
				string[i+1] = toupper(string[i+1]);
			}
		}
	}

	return retorno;
}

//----------------------------------------------------

int MiStrlwrExtendido(char* string, int size, char extendido)
{
	int retorno = -1;

	if(string != NULL && size > 1)
	{
		retorno = 0;
		strlwr(string);

		for(int i=0;i<size-1;i++)
		{
			if( extendido == 's' &&
			   (string[i] == 'Ä' || string[i] == 'Ï' || string[i] == 'Ó' ||
				string[i] == 'É' || string[i] == 'Ö' || string[i] == 'Ü' ||
				string[i] == 'Ñ' || string[i] == 'Á' || string[i] == 'Ë' ||
				string[i] == 'Í' || string[i] == 'Ú'))
			{
				switch(string[i])
				{
				case 'Ü':
					string[i] = 'ü';
				break;

				case 'É':
					string[i] = 'é';
				break;

				case 'Ä':
					string[i] = 'ä';
				break;

				case 'Ë':
					string[i] = 'ë';
				break;

				case 'Ï':
					string[i] = 'ï';
				break;

				case 'Ö':
					string[i] = 'ö';
				break;

				case 'Á':
					string[i] = 'á';
				break;

				case 'Í':
					string[i] = 'í';
				break;

				case 'Ó':
					string[i] = 'ó';
				break;

				case 'Ú':
					string[i] = 'ú';
				break;

				case 'Ñ':
					string[i] = 'ñ';
				break;
				}
			}
		}
	}

	return retorno;
}

//----------------------------------------------------

int ConvertirUprLwrExtendido(char* string, int size, char extendido)
{
	int retorno = -1;

	if(string != NULL && size > 1)
	{
		retorno = 0;

		MiStrlwrExtendido(string,size,extendido);

		for(int i=0;i<size-1;i++)
		{
			if(i==0 && string[i] != ' ')
			{
				string[i] = string[i]-32;
			}

			if(string[i] == ' ')
			{
				string[i+1] = string[i+1]-32;
			}
		}
	}

	return retorno;
}

//----------------------------------------------------


