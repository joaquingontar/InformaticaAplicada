/*
 * ej2.c
 *
 *  Created on: 10 mar. 2023
 *      Author: joaquin
 */
#include <stdlib.h>
#include <stdio.h>
#define CANT_NUMEROS 5
int main(){
	setbuf(stdout,0);
	int num[CANT_NUMEROS],valor,i,cont;
	cont=0;
	while(cont<CANT_NUMEROS){
		printf("ingrese un numero entero distinto de cero:\n");
		scanf("%d",&valor);
		if(valor!=0){
			num[cont]= valor;
			cont=cont+1;
		}
		else{
			printf("valor incorrecto. Ingrese un numero entero distinto de cero\n");
		}
	}
	printf("ingrese un valor. Con cero finalizara el programa\n");
	scanf("%d", &valor);
	while (valor!=0){
		for (i=0;i<CANT_NUMEROS;i++){
			if(valor==num[i]){
				printf("EL VALOR SE ENCUENTRA EN LA SECUENCIA DE NUMEROS.\n Ingrese otro valor:\n");
				scanf("%d", &valor);
			}
		}
		printf("ingrese otro valor. Con cero finaliza el programa\n");
		scanf("%d", &valor);
	}
}

