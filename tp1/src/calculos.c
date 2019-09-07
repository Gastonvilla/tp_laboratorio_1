/*
 * calculos.c
 *
 *  Created on: 1 sep. 2019
 *      Author: GASTON
 */

#include <stdio.h>
#include <stdlib.h>
#include "calculos.h"

/*
 *\brief Solicita un número al usuario y devuelve el resultado
 *\ mmensaje Es el mensaje a ser mostrado
 *\return El número  ingresado por el usuario */

void calculadora(void) {
	float numeroA = 0;
	float numeroB = 0;
	int consulta;
	do {

		printf("Ingrese 1 para ingresar el primer numero %f\n", numeroA);
		printf("Ingrese 2 para ingresar el segundo numero %f\n", numeroB);
		printf("Ingrese 3 para calcular operaciones \n");
		printf("Ingrese 4 para informar resultados de las operaciones\n");
		printf("Ingrese 5 para salir del menu \n");
		getInt(&consulta, "ingrese numero de 1 a 5\n", "numero erroneo\n", 1, 5,
				3);
		int consultaMenu;

		switch (consulta) {
		case 1:
			getFloat(&numeroA, "ingrese numero 1\n", "numero erroneo\n", -32768,
					32767, 3);
			break;
		case 2:
			getFloat(&numeroB, "ingrese numero 2\n", "numero erroneo\n", -32768,
					32767, 3);
			break;
		case 3:
			printf("Si quiere sumar ingrese 1\n");
			printf("si quiere restar ingrese 2\n");
			printf("si quiere dividir ingrese 3\n");
			printf("si quiere multiplicar ingrese 4\n");
			printf("si quiere factoriar ingrese 5\n");
			getInt(&consultaMenu, "ingrese numero\n", "numero erroneo\n", 1, 5,
					3);
			break;
		case 4:
			operaciones(consultaMenu, numeroA, numeroB);
			break;
		case 5:
			break;
		}
	} while (consulta != 5);
}

/* Muestra el resultado de la operacion seleccionada por el usuario*/

void operaciones(int consultaMenu, float numeroA, float numeroB) {
	switch (consultaMenu) {
	case 1:
		printf("La suma es: %f\n", suma(numeroA, numeroB));
		break;
	case 2:
		printf("La resta es: %f\n", resta(numeroA, numeroB));
		break;
	case 3:
		printf("La division es: %f\n", division(numeroA, numeroB));
		break;
	case 4:
		printf("La multiplicacion es: %f\n", multiplicacion(numeroA, numeroB));
		break;
	case 5:
		printf("El factorial es : %f\n", factorial(numeroA));
		printf("El factorial es : %f\n", factorial(numeroB));
		break;
	}
}

float suma(float numeroA, float numeroB) {
	return numeroA + numeroB;
}
float resta(float numeroA, float numeroB) {
	return numeroA - numeroB;
}
float division(float numeroA, float numeroB) {
	if (numeroB == 0) {
		printf("No es divisible por 0");
	}
	return numeroA / numeroB;
}
float multiplicacion(float numeroA, float numeroB) {
	return numeroA * numeroB;
}
float factorial(float num) {
	if(num <= 1){
		return 1;
	}else{
		return num * factorial(num - 1);
	}
}

/* brief solicita un numero al usuario y lo valida
 * param resultado Se carga el numero ingresado
 * param mensaje Es el mensaje a ser mostrado
 * param mensaje de error Es el mensaje a ser mostrado en caso de error
 * param minimo Limite inferior a validar
 * param maximo Limite mayor a validar
 * return Si obtuvo el numero [0] si no [-1]
 *  */

int getInt(int *resultado, char *mensaje, char *mensajeError, int minimo,
		int maximo, int reintentos) {
	int retorno = EXIT_ERROR;
	int buffer;
	if (resultado != NULL && mensaje != NULL && mensajeError != NULL
			&& minimo < maximo && reintentos >= 0) {
		do {
			printf("%s", mensaje);
			//__fpurge(stdin); //
			fflush(stdin);
			if (scanf("%d", &buffer) == 1) {
				if (buffer >= minimo && buffer <= maximo) {
					retorno = EXIT_SUCCESS;
					*resultado = buffer;
					break;
				}
			}
			printf("%s", mensajeError);
			reintentos--;
		} while (reintentos >= 0);
	}
	return retorno;
}

/* brief solicita un numero al usuario y lo valida
 * param resultado Se carga el numero ingresado
 * param mensaje Es el mensaje a ser mostrado
 * param mensaje de error Es el mensaje a ser mostrado en caso de error
 * param minimo Limite inferior a validar
 * param maximo Limite mayor a validar
 * return Si obtuvo el numero [0] si no [-1]
 *  */

int getFloat(float *resultado, char *mensaje, char *mensajeError, float minimo,
		float maximo, int reintentos) {
	int retorno = EXIT_ERROR;
	float buffer;
	if (resultado != NULL && mensaje != NULL && mensajeError != NULL
			&& minimo < maximo && reintentos >= 0) {
		do {
			printf("%s", mensaje);
			//__fpurge(stdin);
			fflush(stdin);
			if (scanf("%f", &buffer) == 1) {
				if (buffer >= minimo && buffer <= maximo) {
					retorno = EXIT_SUCCESS;
					*resultado = buffer;
					break;
				}
			}
			printf("%s", mensajeError);
			reintentos--;
		} while (reintentos >= 0);
	}
	return retorno;
}

/* brief solicita un caracter al usuario y lo valida
 * param resultado Se carga el caracter ingresado
 * param mensaje Es el mensaje a ser mostrado
 * param mensaje de error Es el mensaje a ser mostrado en caso de error
 * param minimo Limite inferior a validar
 * param maximo Limite mayor a validar
 * return Si obtuvo el numero [0] si no [-1]
 *  */
int getChar(char *resultado, char *mensaje, char *mensajeError, char minimo,
		char maximo, int reintentos) {
	int retorno = EXIT_ERROR;
	char buffer;
	if (resultado != NULL && mensaje != NULL && mensajeError != NULL
			&& minimo < maximo && reintentos >= 0) {
		do {
			printf("%s", mensaje);
			//__fpurge(stdin); //
			fflush(stdin);
			if (scanf("%c", &buffer) == 1) {
				if (buffer >= minimo && buffer <= maximo) {
					retorno = EXIT_SUCCESS;
					*resultado = buffer;
					break;
				}
			}
			printf("%s", mensajeError);
			reintentos--;
		} while (reintentos >= 0);
	}
	return retorno;
}

