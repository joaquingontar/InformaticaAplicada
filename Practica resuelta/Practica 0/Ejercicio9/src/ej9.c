/*
 * ej9.c
 *
 *  Created on: 21 mar. 2023
 *      Author: joaqu
 */
#include <stdio.h>
#include <stdlib.h>

//pone a 1 el bit b del número a
#define BitSet(a,b) ( (a) |= ( 1<<(b) ) )
//pone a 0 el bit b del número a
#define BitClear(a,b) ( (a) &= ~( 1<<(b) ) )
//verifica si el bit b del número a es un 0 o un 1
#define BitCheck(a,b) ( (a) & ( 1<<(b) ) )
//cambia el bit b del número a por su valor complementario
//si el bit es 0 lo pone a 1 y si es 1 lo pone a 0
#define BitToggle(a,b) ( (a) ^= ( 1<<(b) ) )
//En una función main dar ejemplos de utilización de cada una de ellas utilizando 2 números de tipo unsigned int.
//Utilizar la siguiente función para visualizar en pantalla un entero number en formato binario:
void print_binary(int number)
{
if (number) {
	print_binary(number >> 1);
	putc((number & 1) ? '1' : '0', stdout);
}
}
int main(){
	char buffer[33]; /* 32 caracteres (1 por bit) + 1 de fin de cadena*/

	//SETEO UN PIN DE SALIDA
	unsigned int entrada= 879797,//valor arbitrario
			salida = 0,
			pin = 0;
	pin=4; //lo podria hacer directamente
	BitSet(salida,pin); //PONGO EL PIN 4 DE LA SALIDA EN 1
	pin=2;
	BitSet(salida,pin); //PONGO EL PIN 2 DE LA SALIDA EN 1, SIN APAGAR EL 4


	//SI QUIERO LIMPIAR UN PIN DE SALIDA (APAGAR UN LED)
	BitClear(salida,4); //PONGO EN CERO EL PIN 4

	//SI QUIERO LEER UN PIN DE ENTRADA (fijarse cuando corro el programa)
	pin=4;
	printf("el pin %d de la entrada esta en: %s\n", pin, (BitCheck(entrada,pin)) ? "1":"0");
	pin=6;
	printf("el pin %d de la entrada esta en: %s\n", pin, (BitCheck(entrada,pin)) ? "1":"0");

int i;
for(i=0; i<5;i++){
	BitToggle(salida, pin); //ME LO ALTERNA, SIRVE PARA PARPADEAR UN LED POR EJEMPLO
}
//SI QUIERO PRINTEAR EN UN FORMATO BINARIO
print_binary(-25);
printf("\n%s\n",itoa(25,buffer,2));

return EXIT_SUCCESS;
}
