/*
 * ej4.c
 *
 *  Created on: 6 abr. 2023
 *      Author: joaqu
 */
#include <stdio.h>
#include <stdlib.h>

char dia[7][10]={"lunes", "martes", "miercoles", "jueves", "viernes", "sabado", "domingo"};

char* buscar(int num){
	char*pb;
	pb=(dia+num-1);
	return(pb);
}

int main(){
	setbuf(stdout, 0);
int num;
int *pt,i,j;
printf("ingrese un numero del 1 al 7\n");
scanf("%d", &num);
//obtengo valor
printf("el dia de la semana es: %s\n", buscar(num));
}

