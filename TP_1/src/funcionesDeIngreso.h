/*
 * funcionIngresoDeDatos.h
 *
 *  Created on: 14 abr. 2022
 *      Author: insua
 */

#ifndef FUNCIONESDEINGRESO_H_
#define FUNCIONESDEINGRESO_H_


/// \brief Pide un numero entero, lo valida y lo manda a la direccion dada
/// \param int Direccion donde se va a mandar el numero
/// \param int El valor mas chico que se puede ingresar
/// \param int El valor mas grande que se puede ingresar
/// \param char El mensaje para pedir el numero
/// \param char El mensaje para informar que hubo un error
/// \param int La cantidad que intentos que tiene el usuario
/// \return	Retorna 'n' si no se pudo ingresar un numero, o 's' si fue exitoso
char IngresarEntero(int*,int,int,char[],char[],int);

/// \brief Pide un numero flotante, lo valida y lo manda a la direccion dada
/// \param float Direccion donde se va a mandar el numero
/// \param float El valor mas chico que se puede ingresar
/// \param float El valor mas grande que se puede ingresar
/// \param char El mensaje para pedir el numero
/// \param char El mensaje para informar que hubo un error
/// \param int La cantidad que intentos que tiene el usuario
/// \return Retorna 'n' si no se pudo ingresar un numero, o 's' si fue exitoso
char IngresarFlotante(float*,int,int,char[],char[],int);

#endif /* FUNCIONESDEINGRESO_H_ */
