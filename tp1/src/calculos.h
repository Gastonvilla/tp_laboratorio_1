/*
 * calculo.h
 *
 *  Created on: 1 sep. 2019
 *      Author: GASTON
 */

void calculadora (void);

#define EXIT_ERROR -1

int getInt(	int *resultado,
			char *mensaje,
			char *mensajeError,
			int minimo,
			int maximo,
			int reintentos);

int getFloat(float *resultado,
			 char *mensaje,
			 char *mensajeError,
			 float minimo,
			 float maximo,
			 int reintentos);

int getChar( char *resultado,
			 char *mensaje,
			 char *mensajeError,
			 char minimo,
			 char maximo,
			 int reintentos);

void operaciones(int, float,float);

float suma(float numeroA,float numeroB);
float resta(float numeroA, float numeroB);
float multiplicacion(float numeroA, float numeroB);
float division(float numeroA, float numeroB);
float factorial(float num);
