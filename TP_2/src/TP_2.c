#include <stdio.h>
#include <stdlib.h>
#include "arrayPassenger.h"
#include "funciones.h"
#include "funcionesDeIngreso.h"

#define TAMCLASE 3
#define TAMPASAJEROS 2000
#define TAMESTADOS 4

int main(void)
{
	setbuf(stdout,NULL);

	int opcion;
	int opcionLista;
	int retorno;

	sClase clases[TAMCLASE] = {{4, "Primera"}, {20, "Ejecutiva"}, {2, "Economica"}};
	sEstadoVuelo estadosVuelo[TAMESTADOS] = {{10, "A tiempo"}, {12, "Demorado"}, {23, "Cancelado"}, {4, "Embarcando"}};
	sPasajero pasajeros[TAMPASAJEROS];

	initPassengers(pasajeros, TAMPASAJEROS);

	do
		{
			printf("\n\n");
			printf("   --MENU--\n");
			printf(" 1. Cargar vuelo\n");
			printf(" 2. Modificar vuelo\n");
			printf(" 3. Eliminar vuelo\n");
			printf(" 4. Informar\n");
			printf(" 5. SALIR\n");
			ObtenerInt(&opcion, 1, 5, "Ingrese una opcion: ", "ERROR, Ingrese una opcion valida: ", 4);
			switch(opcion)
			{
				case 1:

					retorno = IngresarPasajero(pasajeros, TAMPASAJEROS, clases, TAMCLASE, estadosVuelo, TAMESTADOS);

					if(retorno != 0)
					{
						printf("------------------------------------------------------------"
							   "\n ERROR, No se puedo ingresar el pasajero."
							   "\n------------------------------------------------------------");
					}
					else
					{
						printf("------------------------------------------------------------"
							   "\n Pasajero ingresado con exito."
							   "\n------------------------------------------------------------");
					}

					break;
				case 2:

					MostrarConsultas(pasajeros, TAMPASAJEROS, clases, TAMCLASE, estadosVuelo, TAMESTADOS);
					printf("\n");

					retorno = -2;

					retorno = ModificarPasajero(pasajeros, TAMPASAJEROS, clases, TAMCLASE, estadosVuelo, TAMESTADOS);
					switch(retorno)
					{
						case 0:
							printf("\n------------------------------------------------------------"
								   "\n Se modifico exitosamente."
								   "\n------------------------------------------------------------");
						break;

						default:
							printf("\n------------------------------------------------------------"
								   "\n No se modifico el pasajero."
								   "\n------------------------------------------------------------");
						break;
					}

					break;
				case 3:

					MostrarConsultas(pasajeros, TAMPASAJEROS, clases, TAMCLASE, estadosVuelo, TAMESTADOS);
					printf("\n");

					retorno = -2;

					retorno = EliminarPasajero(pasajeros, TAMPASAJEROS);
					switch(retorno)
					{
						case 0:
							printf("\n------------------------------------------------------------"
								   "\n Se elimino exitosamente."
								   "\n------------------------------------------------------------");
						break;

						default:
							printf("\n------------------------------------------------------------"
								   "\n No se elimino el pasajero."
								   "\n------------------------------------------------------------");
						break;
					}

					break;
				case 4:

					printf("\n\n");
					printf("   --MENU LISTAS--\n");
					printf(" 1. Listado.\n");
					printf(" 2. Totoal y promedio.\n");
					printf(" 3. Listado por codigo.\n");
					printf(" 4. Extra.\n");
					printf(" 5. Salir.\n");
					ObtenerInt(&opcionLista, 1, 5, "Ingrese una opcion: ", "ERROR, Ingrese una opcion valida: ", 4);

					switch(opcionLista)
							{
								case 1:

									MostrarConsultas(pasajeros, TAMPASAJEROS, clases, TAMCLASE, estadosVuelo, TAMESTADOS);

									break;
								case 2:

									printf("cancelar");
									break;
								case 3:

									printf("cancelar");
									break;
								case 4:

									printf("diagnosticar");
									break;

								default:

									printf("Saliendo");
									break;
							}
					break;
				default:

					printf("\nsalio");
					break;
				}
			}while(opcion!=5);

	return EXIT_SUCCESS;
}
