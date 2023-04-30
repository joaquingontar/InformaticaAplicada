/*
 * ej3.c
 *
 *  Created on: 6 abr. 2023
 *      Author: joaqu
 */
#include <stdio.h>
#include <stdlib.h>
#define n 99
int main(){
	setbuf(stdout,0);
	float num,vec[n];
	//ingreso los numeros por teclado
	int i=0;
	printf("ingrese un numero por teclado, hasta 100, o cero para finalizar\n");
	scanf("%f", &num);
	vec[0]=num;
	while(num!=0 && i<n){
		i++;
		printf("ingrese otro numero por teclado, hasta 100, o cero para finalizar\n");
		scanf("%f", &num);
		vec[i]=num;
	}
	float *pc;
	int c;
	pc=vec;
	printf("la forma inversa es:\n");
	for(c=0;c<i+1;c++){
		printf("%f\n", *((pc+i)-c));
	}
}

