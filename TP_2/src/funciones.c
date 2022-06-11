
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "funcionesDeIngreso.h"
#include "funcionesCadenas.h"
#include "arrayPassenger.h"

int IngresarPasajero(sPasajero pasajeros[], int sizePasajeros, sClase clases[], int sizeClases, sEstadoVuelo estadosVuelo[], int sizeEstados)
{
	sPasajero unPasajero;
	int retorno;
	int index;
	int retornoNombre;
	int retornoApellido;
	int retornoPrecio;
	int retornoCodigo;
	int retornoClase;
	int retornoEstado;

	retorno = -1;

	if(pasajeros != NULL && sizePasajeros > 0 && clases != NULL && sizeClases > 0 && estadosVuelo != NULL && sizeEstados > 0)
	{
		retorno = 1;

		index = BuscarVacio(pasajeros, sizePasajeros);

		if(index != -1)
		{
			unPasajero.idPasajero = index + 1;

			retornoApellido = ObtenerStringAlfabetico(unPasajero.apellido, 51, "Ingrese el apellido del pasajero: ", "ERROR, Ingrese el apellido del pasajero: ", 5, 's');
			ConvertirUprLwrExtendido(unPasajero.apellido, 51, 's');

			retornoNombre = ObtenerStringAlfabetico(unPasajero.nombre, 51, "Ingrese el nombre del pasajero: ", "ERROR, Ingrese el nombre del pasajero: ", 5, 's');
			ConvertirUprLwrExtendido(unPasajero.nombre, 51, 's');

			retornoPrecio = ObtenerFloat(&unPasajero.precioVuleo,1,9999999, "Ingrese el precio del vuelo: ", "ERROR, Ingrese el precio del vuelo: ", 5);

			retornoCodigo = IngresarCodigo(unPasajero.codigoVuelo);

			retornoClase = IngresarClase(clases, sizeClases, &unPasajero.idClase);
			printf("\n");

			retornoEstado = IngresarEstado(estadosVuelo, sizeEstados, &unPasajero.idEstado);
			printf("\n");

			if(retornoNombre == 0 && retornoApellido == 0 && retornoPrecio == 0 && retornoPrecio == 0 && retornoCodigo == 0 && retornoClase == 0 && retornoEstado == 0)
			{
				retorno = 0;
				addPassenger(pasajeros, sizePasajeros, unPasajero.idPasajero, unPasajero.nombre, unPasajero.apellido, unPasajero.precioVuleo, unPasajero.codigoVuelo, unPasajero.idClase, unPasajero.idEstado, index);
			}
		}
	}

	return retorno;
}

//--------------------------------------------------------------------------

int BuscarVacio(sPasajero pasajeros[], int sizePasajeros)
{
	int index;

	index = -1;

	if(pasajeros != NULL && sizePasajeros > 0)
	{
		for(int i=0;i<sizePasajeros;i++)
		{
			if(pasajeros[i].estaVacio == 1)
			{
				index = i;
				break;
			}
		}
	}

	return index;
}

//--------------------------------------------------------------------------

static void ListarClases(sClase[],int);
static void ListarClases(sClase clases[], int sizeClases)
{

	if(clases != NULL && sizeClases > 0)
	{
		printf("\n  id \tClase");
		printf("\n-----------------------------------------");
		for(int i=0; i<sizeClases; i++)
		{
			printf("\n  %-3d \t%-20s ",clases[i].idClase,clases[i].tipoDeClase);
		}
		printf("\n");
	}
}

//--------------------------------------------------------------------------

static void ListarEstados(sEstadoVuelo[],int);
static void ListarEstados(sEstadoVuelo estadosVuelo[], int sizeEstados)
{
	if(estadosVuelo != NULL && sizeEstados > 0)
	{
		printf("\n  id \tEstados de vuelo");
		printf("\n-----------------------------------------");
		for(int i=0; i<sizeEstados; i++)
		{
			printf("\n  %-3d \t%-20s ",estadosVuelo[i].idEstado,estadosVuelo[i].estadoVuelo);
		}
		printf("\n");
	}
}

//--------------------------------------------------------------------------

int IngresarClase(sClase clases[], int sizeClases, int* bufferIdClase)
{
	int bufferId;
	int retorno;

	retorno = -1;

	if(clases != NULL && sizeClases > 0 && bufferIdClase != NULL)
	{
		ListarClases(clases, sizeClases);

		while(retorno != 0)
		{
			retorno = ObtenerInt(&bufferId, 0, 999, "Ingrese el id del tipo de pasajero: ", "ERROR, Ingrese el id del tipo de pasajero: ", 5);

			if(retorno == -1)
			{
				break;
			}

			retorno = 1;

			for(int i=0; i<sizeClases; i++)
			{
				if(bufferId == clases[i].idClase)
				{
					*bufferIdClase = clases[i].idClase;
					retorno = 0;
				}
			}

			if(retorno == 1)
			{
				printf("ERROR, La clase seleccionada no existe\n");
			}
		}
	}

	return retorno;
}

//--------------------------------------------------------------------------

int IngresarEstado(sEstadoVuelo estadosVuelo[], int sizeEstados, int* bufferIdEstado)
{
	int bufferId;
	int retorno;

	retorno = -1;

	if(estadosVuelo != NULL && sizeEstados > 0 && bufferIdEstado != NULL)
	{
		ListarEstados(estadosVuelo, sizeEstados);

		while(retorno != 0)
		{
			retorno = ObtenerInt(&bufferId, 0, 999, "Ingrese el id del tipo de estado de vuelo: ", "ERROR, Ingrese el id del tipo de estado de vuelo: ", 5);

			if(retorno == -1)
			{
				break;
			}

			retorno = 1;

			for(int i=0; i<sizeEstados; i++)
			{
				if(bufferId == estadosVuelo[i].idEstado)
				{
					*bufferIdEstado = estadosVuelo[i].idEstado;
					retorno = 0;
				}
			}

			if(retorno == 1)
			{
				printf("ERROR, El estado de vuelo seleccionado no existe\n");
			}
		}
	}

	return retorno;
}

//-------------------------------------------------------------

int IngresarCodigo(char buffer[])
{
	int retorno;

	retorno = -1;

	if(buffer != NULL)
	{
		do
		{
			retorno = ObtenerStringAlfaNumerico(buffer, 11, "Ingrese el codigo de vuelo: ", "ERROR, Ingrese el codigo de vuelo (entre 6 y 10 caracteres):  ", 5, 'n');

			if(strlen(buffer) < 6)
			{
				retorno = 1;
				printf("\nERROR, El codigo de vuelo debe tener mas de 5 caracteres.\n");
			}
		}while(retorno != 0);
	}

	return retorno;
}

//-------------------------------------------------------------

int MostrarConsultas(sPasajero pasajeros[], int sizePasajeros, sClase clases[], int sizeClases, sEstadoVuelo estadosVuelo[], int sizeEstados)
{
	int retorno;
	sPasajero bufferEstructura[sizePasajeros];

	/*for(int i=0; i<sizePasajeros; i++)
	{
		bufferEstructura[i].idPasajero = buff;
	}*/

	retorno = -1;

	if(pasajeros != NULL && sizePasajeros > 0 && clases != NULL && sizeClases > 0 && estadosVuelo != NULL && sizeEstados > 0)
	{
		retorno = 1;

		sortPassengers(bufferEstructura, sizePasajeros, 1);

		printf("\n id \t Clase \t\t Apellido \t\tNombre \t\t\t Precio \t Codigo \t Estado\n");
		printf("--------------------------------------------------------------------------------------------------------------------");

		for(int i=0; i<sizePasajeros; i++)
		{
			for(int j=0; j<sizeClases; j++)
			{
				for(int k=0; k<sizeEstados; k++)
				{
					if(bufferEstructura[i].estaVacio == 0 && (bufferEstructura[i].idClase == clases[j].idClase) && (bufferEstructura[i].idEstado == estadosVuelo[k].idEstado))
					{
							printPassenger(bufferEstructura[i], clases[j], estadosVuelo[k]);
							retorno = 0;
					}
				}
			}
		}
	}

	return retorno;
}

//-------------------------------------------------------------

int ModificarPasajero(sPasajero pasajeros[], int sizePasajeros, sClase clases[], int sizeClases, sEstadoVuelo estadosVuelo[], int sizeEstados)
{
	int retorno;
	int seleccion;
	char confirmacion;

	retorno = -1;

	if(pasajeros != NULL && sizePasajeros > 0)
	{
		do
		{
			ObtenerInt(&seleccion, 1, sizePasajeros, "Ingrese el id de la consulta que desea modificar: ", "ERROR, Ingrese el id de la consulta que desea modificar: ", 4);

			if(pasajeros[seleccion-1].estaVacio == 0)
			{
				confirmacion = 's';
				retorno = OpcionesModificacion(pasajeros, sizePasajeros, clases, sizeClases, estadosVuelo, sizeEstados, seleccion);
			}
			else
			{
				printf("ERROR, Ingrese el id de la consulta que desea modificar\n");
			}
		}while(confirmacion != 's');
	}
	return retorno;
}

//-------------------------------------------------------------

int OpcionesModificacion(sPasajero pasajeros[], int sizePasajeros, sClase clases[], int sizeClases, sEstadoVuelo estadosVuelo[], int sizeEstados, int idPasajero)
{
	int retorno;
	char confirmacion;
	int opcion;
	char bufferString[51];
	float bufferFloat;
	int bufferInt;
	int retornoFuncion;

	retorno = 1;

	for(int i=0; i<sizePasajeros; i++)
	{
		if(pasajeros[i].idPasajero == idPasajero && pasajeros[i].estaVacio == 0)
		{
			do
			{
				printf("\n 1. Modificar nombre\n");
				printf(" 2. Modificar apellido\n");
				printf(" 3. Modificar precio\n");
				printf(" 4. Modificar codigo\n");
				printf(" 5. Modificar clase\n");
				printf(" 6. Modificar estado\n");
				printf(" 7. SALIR\n");
				ObtenerInt(&opcion, 1, 7, "Ingrese una opcion: ", "ERROR, Ingrese una opcion valida: ", 5);

				switch(opcion)
				{
					case 1:

						retornoFuncion = ObtenerStringAlfabetico(bufferString, 51, "Ingrese el nombre del pasajero: ", "ERROR, Ingrese el nombre del pasajero: ", 5, 's');
						ConvertirUprLwrExtendido(bufferString, 51, 's');

						ObtenerCharDosOpciones(&confirmacion, 's', 'n', "Esta seguro que desa modificar el pasajero? (s/n): ", "ERROR, Esta seguro que desa modificar el pasajero? (s/n): ", 5);
						if(confirmacion == 's' && retornoFuncion == 0)
						{
							snprintf(pasajeros[i].nombre,51,"%s",bufferString);
							confirmacion = 'n';
							retorno = 0;
						}
					break;

					case 2:

						retornoFuncion = ObtenerStringAlfabetico(bufferString, 51, "Ingrese el apellido del pasajero: ", "ERROR, Ingrese el apellido del pasajero: ", 5, 's');
						ConvertirUprLwrExtendido(bufferString, 51, 's');

						ObtenerCharDosOpciones(&confirmacion, 's', 'n', "Esta seguro que desa modificar el pasajero? (s/n): ", "ERROR, Esta seguro que desa modificar el pasajero? (s/n): ", 5);
						if(confirmacion == 's' && retornoFuncion == 0)
						{
							snprintf(pasajeros[i].apellido,51,"%s",bufferString);
							confirmacion = 'n';
							retorno = 0;
						}
					break;

					case 3:

						retornoFuncion = ObtenerFloat(&bufferFloat, 1, 9999999, "Ingrese el precio del vuelo: ", "ERROR, Ingrese el precio del vuelo: ", 5);

						ObtenerCharDosOpciones(&confirmacion, 's', 'n', "Esta seguro que desa modificar el precio? (s/n): ", "ERROR, Esta seguro que desa modificar el precio? (s/n): ", 5);
						if(confirmacion == 's' && retornoFuncion == 0)
						{
							pasajeros[i].precioVuleo = bufferFloat;
							confirmacion = 'n';
							retorno = 0;
						}
					break;

					case 4:

						retornoFuncion = IngresarCodigo(bufferString);

						ObtenerCharDosOpciones(&confirmacion, 's', 'n', "Esta seguro que desa modificar el codigo? (s/n): ", "ERROR, Esta seguro que desa modificar el codigo? (s/n): ", 5);
						if(confirmacion == 's' && retornoFuncion == 0)
						{
							snprintf(pasajeros[i].codigoVuelo,11,"%s",bufferString);
							confirmacion = 'n';
							retorno = 0;
						}
					break;

					case 5:

						retornoFuncion = IngresarClase(clases, sizeClases, &bufferInt);
						printf("\n");

						ObtenerCharDosOpciones(&confirmacion, 's', 'n', "Esta seguro que desa modificar la clase? (s/n): ", "ERROR, Esta seguro que desa modificar la clase? (s/n): ", 5);
						if(confirmacion == 's' && retornoFuncion == 0)
						{
							pasajeros[i].idClase = bufferInt;
							confirmacion = 'n';
							retorno = 0;
						}
					break;

					case 6:

						retornoFuncion = IngresarEstado(estadosVuelo, sizeEstados, &bufferInt);
						printf("\n");

						ObtenerCharDosOpciones(&confirmacion, 's', 'n', "Esta seguro que desa modificar el estado? (s/n): ", "ERROR, Esta seguro que desa modificar el estado? (s/n): ", 5);
						if(confirmacion == 's' && retornoFuncion == 0)
						{
							pasajeros[i].idEstado = bufferInt;
							confirmacion = 'n';
							retorno = 0;
						}
					break;

					default:
						printf("\nSaliendo...\n");
					break;
				}
			}while(opcion != 7);
		}
	}

	return retorno;
}

//----------------------------------------------------------

int EliminarPasajero (sPasajero pasajeros[], int sizePasajeros)
{
	int retorno;
	int seleccion;
	char confirmacion;

	retorno = -1;

	if(pasajeros != NULL && sizePasajeros > 0)
	{
		do
		{
			ObtenerInt(&seleccion, 1, sizePasajeros, "Ingrese el id de la consulta que desea eliminar: ", "ERROR, Ingrese el id de la consulta que desea eliminar: ", 4);

			if(pasajeros[seleccion-1].estaVacio == 0)
			{
				confirmacion = 's';
				retorno = removePassenger(pasajeros, sizePasajeros, seleccion);
			}
			else
			{
				printf("ERROR, Ingrese el id de la consulta que desea eliminar\n");
			}
		}while(confirmacion != 's');
	}
	return retorno;
}
