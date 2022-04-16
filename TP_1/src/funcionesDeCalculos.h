

#ifndef FUNCIONESDECALCULOS_H_
#define FUNCIONESDECALCULOS_H_

/// \brief Le descuenta al valor dado el porcentaje dado
/// \param float El valor al que se le hace el descuento
/// \param float Porcentaje que se desea descontar
/// \return Retorna el precio final con el descuento
float CalcularDescuento(float,float);

/// \brief Le agrega al valor dado el porcentaje dado
/// \param float El valor al que se le hace el aumento
/// \param float Porcentaje que se desea aumentar
/// \return Retorna el precio final con el aumento
float CalcularInteres(float,float);

/// \brief Pasa el precio de una moneda a la otra
/// \param float La cantidad de la primer moneda
/// \param float Lo que vale una unidad de la segunda moneda en base a la primera
/// \return Retorna la convercion de una moneda a la otra
float ConvertirMoneda(float,float);

/// \brief Divide el precio dado por la cantidad dada
/// \param float El precio
/// \param float La cantidad
/// \return Retorna el precio de cada unidad
float CalcularPrecioUnitario(float,float);

/// \brief Calcula la diferencia de dos numeros restandole al mayor el menor
/// \param float Primer numero
/// \param float Segundo numero
/// \return Retorna la diferencia de los numeros
float CalcularDiferencia(float,float);

#endif /* FUNCIONESDECALCULOS_H_ */
