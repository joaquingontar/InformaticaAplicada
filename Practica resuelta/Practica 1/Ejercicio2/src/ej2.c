/*
 * ej2.c
 *
 *  Created on: 6 abr. 2023
 *      Author: joaqu
 */
#include <stdio.h>
#include <stdlib.h>
int main(){
int i=5, j[]={1,2,3,4,5,6,7,8,9,10};
char pal [] ="texto en c";
int *pi;
char *pc;
//ITEM A - MOSTRAR LA DIRECCION DE MEMORIA DE i Y SU VALOR
printf("direccion de memoria: %x\n", &i);
printf("valor de la variable: %d\n", i);
//ITEM B - MOSTRAR LOS MISMOS VALORES PERO CON EL PUNTERO pi
pi=&i;
printf("direccion de memoria: %p\n", pi);
printf ("valor de la varible: %d\n" , *pi);
//ITEM C - RECORRER EL VECTOR j MOSTRANDO PARA CADA ELEMENTO, SU DIRECCION Y SU VALOR
sizeof j; //tamaño del arreglo
int c;
//sin usar el puntero
for(c=0;c<10;c++){
	printf("la direccion de memoria de la posicion %d del arreglo, es: %p\n",c , &c);
	printf("el valor de la variable de la posicion %d es: %d\n", c, j[c]);
	}
//ITEM 4 - RECORRER EL ARREGLO CON EL PUNTERO pi
pi=j;
for(c=0;c<10;c++){
	printf("la direccion de memoria de la posicion %d del arreglo, es: %x\n",c ,pi+c);
	printf("el valor de la posicion %d del arreglo, es: %x\n", c, *(pi+c));
}
//ITEM 5 - RECORRER EL ARREGLO DE char A PARTIR DEL PUNTERO pc
int sf;
pc=pal;
sf=sizeof pal;
printf("=======================\n recorrer el texto\n:");
for(c=0;c<sf;c++){
	printf("%c", *(pc+c));
	}
//ITEM 6 - MOSTRAR LA DIRECCION DE AMBOS PUNTEROS
printf("la direccion de memoria del puntero pi es %p\n", &pi);
printf ("la direccion de memoria del puntero pc es %p\n", &pc);
}

