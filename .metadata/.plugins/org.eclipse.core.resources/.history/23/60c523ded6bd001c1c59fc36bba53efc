/*
TP 1 Guido
*/

#include <stdio.h>
#include <stdlib.h>

#include "funcionesDeIngreso.h"
#include "funcionesDeCalculos.h"

int main(void)
{
	setbuf(stdout,NULL);

	float kilometrosIngresados;
	float precioVueloAerolinasIngresado;
	float precioVueloLatamIngresado;
	float precioDebitoConAerolineas;
	float precioCreditoConAerolineas;
	float precioEnBitcoinConAerolineas;
	float precioUnitarioConAerolineas;
	float precioDebitoConLatam;
	float precioCreditoConLatam;
	float precioEnBitcoinConLatam;
	float precioUnitarioConLatam;
	float diferenciaDePrecio;
	int opcion;
	char seIngresaronKilometros;
	char seIngresaronPrecios;
	char seCalcularonLosCostos;

	kilometrosIngresados = 0;
	precioVueloAerolinasIngresado = 0;
	precioVueloLatamIngresado = 0;
	seIngresaronKilometros = 'n';
	seIngresaronPrecios = 'n';
	seCalcularonLosCostos = 'n';

	do
	{
		printf("\n		MENU\n");
		printf("  1. Ingresar kilometros (Km = %.3f)\n",kilometrosIngresados);
		printf("  2. Ingresar precio de vuelos (Aerolineas = $%.3f ; Latam = $%.3f)\n",precioVueloAerolinasIngresado,precioVueloLatamIngresado);
		printf("  3. Calcular costos\n");
		printf("  4. Informar resultados\n");
		printf("  5. Carga forzada de datos\n");
		printf("  6. Salir\n");

		IngresarEntero(&opcion, 1, 6, "	-Ingrese una opcion: ", "ERROR, Eliga una opcion valida", 3);

		switch(opcion)
		{
			case 1:

				seIngresaronKilometros = IngresarFlotante(&kilometrosIngresados,1,20000,"\nIngrese la distancia en kilometros: ","ERROR, Ingrese una cantidad de kilometros validos",3);

			break;

			case 2:

				seIngresaronPrecios = IngresarFlotante(&precioVueloAerolinasIngresado,1, 1000000, "\nIngrese el precio para el vuelo de Aerolineas: ", "ERROR, Ingrese un precio para el vuelo de Aerolineas valido",3);

				if(seIngresaronPrecios == 's')
				{
					seIngresaronPrecios = IngresarFlotante(&precioVueloLatamIngresado,1, 1000000, "\nIngrese el precio para el vuelo de Latam: ", "ERROR, Ingrese un precio para el vuelo de Latam valido",3);
				}
			break;

			case 3:

				if(seIngresaronKilometros == 'n' || seIngresaronPrecios == 'n')
				{
					printf("\n	(ERROR, Falta ingresar datos)\n");
				}
				else
				{
				seCalcularonLosCostos = 's';

				precioDebitoConAerolineas = CalcularDescuento(precioVueloAerolinasIngresado, 0.1);
				precioCreditoConAerolineas = CalcularInteres(precioVueloAerolinasIngresado, 0.25);
				precioEnBitcoinConAerolineas = ConvertirMoneda(precioVueloAerolinasIngresado, 4606954.55);
				precioUnitarioConAerolineas = CalcularPrecioUnitario(precioVueloAerolinasIngresado, kilometrosIngresados);

				precioDebitoConLatam = CalcularDescuento(precioVueloLatamIngresado, 0.1);
				precioCreditoConLatam = CalcularInteres(precioVueloLatamIngresado, 0.25);
				precioEnBitcoinConLatam = ConvertirMoneda(precioVueloLatamIngresado, 4606954.55);
				precioUnitarioConLatam = CalcularPrecioUnitario(precioVueloLatamIngresado, kilometrosIngresados);

				diferenciaDePrecio = CalcularDiferencia(precioVueloAerolinasIngresado, precioVueloLatamIngresado);

				printf("\n 	(Costos Calculados con exito)\n");
				}
			break;

			case 4:

				if(seCalcularonLosCostos == 'n')
				{
					printf("\n	(ERROR, No se calcularon los costos)\n");
				}
				else
				{
				printf("\nKMs Ingresados: %.3f KM\n",kilometrosIngresados);

				printf("\nPrecio Aerolineas: $%.3f",precioVueloAerolinasIngresado);
				printf("\na) Precio con tarjeta de debito: $%.3f",precioDebitoConAerolineas);
				printf("\na) Precio con tarjeta de credito: $%.3f",precioCreditoConAerolineas);
				printf("\na) Precio pagando con bitcoin: %f BTC",precioEnBitcoinConAerolineas);
				printf("\na) Precio unitario: $%.3f\n",precioUnitarioConAerolineas);

				printf("\nPrecio Latam: $%.3f",precioVueloLatamIngresado);
				printf("\na) Precio con tarjeta de debito: $%.3f",precioDebitoConLatam);
				printf("\na) Precio con tarjeta de credito: $%.3f",precioCreditoConLatam);
				printf("\na) Precio pagando con bitcoin: %f BTC",precioEnBitcoinConLatam);
				printf("\na) Precio unitario: $%.3f\n",precioUnitarioConLatam);

				printf("\nLa diferencia de precio es: $%.3f\n",diferenciaDePrecio);
				}
			break;

			case 5:

				precioDebitoConAerolineas = CalcularDescuento(162965, 0.1);
				precioCreditoConAerolineas = CalcularInteres(162965, 0.25);
				precioEnBitcoinConAerolineas = ConvertirMoneda(162965, 4606954.55);
				precioUnitarioConAerolineas = CalcularPrecioUnitario(162965, 7090);

				precioDebitoConLatam = CalcularDescuento(159339, 0.1);
				precioCreditoConLatam = CalcularInteres(159339, 0.25);
				precioEnBitcoinConLatam = ConvertirMoneda(159339, 4606954.55);
				precioUnitarioConLatam = CalcularPrecioUnitario(159339, 7090);

				diferenciaDePrecio = CalcularDiferencia(162965, 159339);

				printf("\nKMs Ingresados: 7090 KM\n");

				printf("\nPrecio Aerolineas: $162965");
				printf("\na) Precio con tarjeta de debito: $%.3f",precioDebitoConAerolineas);
				printf("\na) Precio con tarjeta de credito: $%.3f",precioCreditoConAerolineas);
				printf("\na) Precio pagando con bitcoin: %f BTC",precioEnBitcoinConAerolineas);
				printf("\na) Precio unitario: $%.3f\n",precioUnitarioConAerolineas);

				printf("\nPrecio Latam: $159339");
				printf("\na) Precio con tarjeta de debito: $%.3f",precioDebitoConLatam);
				printf("\na) Precio con tarjeta de credito: $%.3f",precioCreditoConLatam);
				printf("\na) Precio pagando con bitcoin: %f BTC",precioEnBitcoinConLatam);
				printf("\na) Precio unitario: $%.3f\n",precioUnitarioConLatam);

				printf("\nLa diferencia de precio es: $%.3f\n",diferenciaDePrecio);
			break;
		}
	}while(opcion != 6);

	printf("\n  Salio");

	return EXIT_SUCCESS;
}
