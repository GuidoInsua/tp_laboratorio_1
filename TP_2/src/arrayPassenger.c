
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayPassenger.h"
#include "funcionesDeIngreso.h"


int initPassengers(sPasajero* pasajeros, int sizePasajeros)
{
	int retorno;

	retorno = -1;

	if(pasajeros != NULL && sizePasajeros > 0)
	{
		for(int i=0;i<sizePasajeros;i++)
		{
			pasajeros[i].estaVacio = 1;
		}

		retorno = 0;
	}

	return retorno;
}

//---------------------------------------------------------------

int addPassenger(sPasajero* pasajeros, int sizePasajeros, int idPasajero, char nombre[], char apellido[], float precioVuelo, char codigoVuelo[], int idClase, int idEstado, int index)
{
	int retorno;

	retorno = -1;

	if(pasajeros != NULL && sizePasajeros > 0 && idPasajero > -1 && nombre != NULL && apellido != NULL && precioVuelo > 0 && codigoVuelo != NULL && idClase > -1 && idEstado > -1 && index >= 0)
	{
		pasajeros[index].idPasajero = idPasajero;
		strncpy(pasajeros[index].nombre,nombre,51);
		strncpy(pasajeros[index].apellido,apellido,51);
		pasajeros[index].precioVuleo = precioVuelo;
		strncpy(pasajeros[index].codigoVuelo,codigoVuelo,10);
		pasajeros[index].idClase = idClase;
		pasajeros[index].idEstado = idEstado;

		pasajeros[index].estaVacio = 0;
		retorno = 0;
	}

	return retorno;
}

//---------------------------------------------------------------

int findPassengerById(sPasajero* pasajeros, int sizePasajeros,int idPasajero)
{



	return 0;
}

//---------------------------------------------------------------

int removePassenger(sPasajero* pasajeros, int sizePasajeros, int idPasajero)
{

	char confirmacion;
	int retorno;

	retorno = 1;

	for(int i=0; i<sizePasajeros; i++)
	{
		if(pasajeros[i].idPasajero == idPasajero && pasajeros[i].estaVacio == 0)
		{
			printf("\n Selecion--- id:%d ----\n",pasajeros[i].idPasajero);
			ObtenerCharDosOpciones(&confirmacion, 's', 'n', "Esta seguro que desa eliminar la consulta? (s/n): ", "ERROR, Esta seguro que desa eliminar la consulta? (s/n): ", 4);

			if(confirmacion == 's')
			{
				pasajeros[i].estaVacio = 1;
				retorno = 0;
			}
		}
	}

	return retorno;
}

//---------------------------------------------------------------

int sortPassengers(sPasajero* pasajeros, int sizePasajeros, int orden)
{
	   char auxiliar[51];

	   for(int i=1;i<sizePasajeros+1;i++)
	   {
		  for(int j=0;j<sizePasajeros-i;j++)
		  {
			 if(strcmp(pasajeros[j].apellido,pasajeros[j+1].apellido) > 0)
			 {
				strncpy(auxiliar,pasajeros[j].apellido,51);
				strncpy(pasajeros[j].apellido,pasajeros[j+1].apellido,51);
				strncpy(pasajeros[j+1].apellido,auxiliar,51);
			 }
		  }
	   }
	return 0;
}

//---------------------------------------------------------------

int printPassenger(sPasajero pasajeros, sClase clases, sEstadoVuelo estadosVuelo)
{

	printf("\n %-4d \t %-9s \t %-20s \t%-20s \t %-9.2f \t %-10s \t %-10s\n",pasajeros.idPasajero,clases.tipoDeClase,pasajeros.apellido,
																	   pasajeros.nombre,pasajeros.precioVuleo,
																	   pasajeros.codigoVuelo,
																	   estadosVuelo.estadoVuelo);

	return 0;
}

//---------------------------------------------------------------

int sortPassengersByCode(sPasajero* pasajeros, int sizePasajeros, int orden)
{



	return 0;
}

//---------------------------------------------------------------
