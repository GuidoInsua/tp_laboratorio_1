#include "arrayPassenger.h"

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

int IngresarPasajero (sPasajero pasajeros[], int sizePasajeros, sClase clases[], int sizeClases, sEstadoVuelo estadosVuelo[], int sizeEstados);

int IngresarClase(sClase[],int,int*);

int BuscarVacio(sPasajero pasajeros[], int sizePasajeros);

int IngresarEstado(sEstadoVuelo estadosVuelo[], int sizeEstados, int* bufferIdEstado);

int IngresarCodigo(char buffer[]);

int MostrarConsultas(sPasajero pasajeros[], int sizePasajeros, sClase clases[], int sizeClases, sEstadoVuelo estadosVuelo[], int sizeEstados);

int ModificarPasajero(sPasajero pasajeros[], int sizePasajeros, sClase clases[], int sizeClases, sEstadoVuelo estadosVuelo[], int sizeEstados);

int OpcionesModificacion(sPasajero pasajeros[], int sizePasajeros, sClase clases[], int sizeClases, sEstadoVuelo estadosVuelo[], int sizeEstados, int idPasajero);

int EliminarPasajero (sPasajero pasajeros[], int sizePasajeros);

#endif /* FUNCIONES_H_ */
