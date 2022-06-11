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
			   (string[i] == '�' || string[i] == '�' || string[i] == '�' ||
				string[i] == '�' || string[i] == '�' || string[i] == '�' ||
				string[i] == '�' || string[i] == '�' || string[i] == '�' ||
				string[i] == '�' || string[i] == '�'))
			{
				switch(string[i])
				{
				case '�':
					string[i] = '�';
				break;

				case '�':
					string[i] = '�';
				break;

				case '�':
					string[i] = '�';
				break;

				case '�':
					string[i] = '�';
				break;

				case '�':
					string[i] = '�';
				break;

				case '�':
					string[i] = '�';
				break;

				case '�':
					string[i] = '�';
				break;

				case '�':
					string[i] = '�';
				break;

				case '�':
					string[i] = '�';
				break;

				case '�':
					string[i] = '�';
				break;

				case '�':
					string[i] = '�';
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


