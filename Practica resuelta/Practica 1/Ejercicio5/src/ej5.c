/*
 * ej5.c
 *
 *  Created on: 8 abr. 2023
 *      Author: joaqu
 */

#include <stdio.h>
#include <stdlib.h>

float compra(float cant,float precio){
	float pagar, *pp;
	pp=&pagar;
	*pp=cant*precio;
	if(*pp>100){
		*pp=*pp-(0.1*(*pp));
	}
	return(pagar);
}

int main(){
	setbuf(stdout,0);
	float cant, precio;
	//ingreso de los datos
	printf("ingrese la cantidad de kilos que quiere comprar:\n");
	scanf("%f", &cant);
	printf("ingrese el precio del kilo:\n");
	scanf("%f", &precio);
	//printeo resultado
	printf("el importe de la compra es: %f\n",compra(cant,precio));
}
