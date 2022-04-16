
#include "funcionesDeCalculos.h"

float CalcularDescuento(float precio, float porcentaje)
{
	float descuento;
	float precioFinal;

	descuento = precio * porcentaje;
	precioFinal = precio - descuento;

	return precioFinal;
}

float CalcularInteres(float precio, float porcentaje)
{
	float interes;
	float precioFinal;

	interes = precio * porcentaje;
	precioFinal = precio + interes;

	return precioFinal;
}

float ConvertirMoneda(float cantidad, float precioDeLaMoneda)
{
	// 1 moneda ---> precioDeLaMoneda
	// x moneda ---> cantidad

	float resultado;

	resultado = (cantidad * 1) / precioDeLaMoneda;

	return resultado;
}

float CalcularPrecioUnitario(float precio, float cantidad)
{
	float resultado;

	resultado = precio / cantidad;

	return resultado;
}

float CalcularDiferencia(float primero, float segundo)
{
	float diferencia;

	if(primero > segundo)
	{
		diferencia = primero - segundo;
	}
	else
	{
		diferencia = segundo - primero;
	}

	return diferencia;
}
