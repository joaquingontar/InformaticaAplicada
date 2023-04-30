/*
 * ej5.c
 *
 *  Created on: 11 mar. 2023
 *      Author: joaqu
 */
#include <stdio.h>
#include <stdlib.h>
#define N 60
int main(){
	setbuf(stdout,0);
	char frase[N];
printf("ingresa una frase de no mas de 59 caracteres\n");
gets(frase);

// DIFERENTES FORMAS DE IMPRIMIR UNA CADENA DE CARACTERES
printf("la frase ingresada es:\n");
puts(frase);
printf("la frase ingresada es: %s\n", frase);
printf("la frase ingresada es: %c\n", frase[2]);
return 0;
}
