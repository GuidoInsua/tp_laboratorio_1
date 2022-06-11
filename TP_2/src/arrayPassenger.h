
#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

typedef struct
{
	int idClase;
	char tipoDeClase[20];
}sClase;

typedef struct
{
	int idEstado;
	char estadoVuelo[20];
}sEstadoVuelo;

typedef struct
{
	int idPasajero;
	char nombre[51];
	char apellido[51];
	float precioVuleo;
	char codigoVuelo[10];
	int idClase;
	int idEstado;
	int estaVacio;
}sPasajero;

int initPassengers(sPasajero* pasajeros, int sizePasajeros);

int addPassenger(sPasajero* pasajeros, int sizePasajeros, int idPasajero, char nombre[], char apellido[], float precioVuelo, char codigoVuelo[], int idClase, int idEstado, int index);

int findPassengerById(sPasajero* pasajeros, int sizePasajeros,int idPasajero);

int removePassenger(sPasajero* pasajeros, int sizePasajeros, int idPasajero);

int sortPassengers(sPasajero* pasajeros, int sizePasajeros, int orden);

int printPassenger(sPasajero pasajeros, sClase clases, sEstadoVuelo estadosVuelo);

int sortPassengersByCode(sPasajero* pasajeros, int sizePasajeros, int orden);


#endif /* ARRAYPASSENGER_H_ */
