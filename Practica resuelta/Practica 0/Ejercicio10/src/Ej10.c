/*
 * Ej10.c
 *
 *  Created on: 26 mar. 2023
 *      Author: joaqu
 */
#include <stdio.h>
#include <stdlib.h>


void paridad_par(int byte[8])//en entrada tengo mis 8 bits
{
	int i,cont_uno,cont_cero;
	for(i=0;i<8;i++){ //cuento la cantidad de unos y ceros que tiene el byte
		if(byte[i]==0){
			cont_cero++;
		}
		if(byte[i]==1){
			cont_uno++;
		}
	}
	if(cont_uno %2!=0){ //chequeo que la cantidad de unos sea par
		if(byte[0]==1){
			byte[0]=0;
		}
		else{
			byte[0]=1;
		}
	}
	for(i=0;i<8;i++){
			printf("%d ",byte[i]);
		}
}

int main(){
	int byte[8], bit,i;
	//ingreso el bit que quiero
	for(i=0;i<8;i++){
		printf("Ingrese el valor de un byte, bit a bit (cero o uno)\n");
		scanf("%d",&bit);
		while(bit!=0 && bit!=1){
			printf("el bit debe ser cero o uno, ingrese un numero\n");
			scanf("%d", &bit);
		}
		byte[i]=bit;
	}
	printf("el byte ingresado es:\n"); //imprimo el byte ingresado
	for(i=0;i<8;i++){
			printf("%d ",byte[i]);
		}
	printf("\n el byte de salida es:\n");
	paridad_par(byte); //LLAMO A LA FUNCION, NO DEVUELVE NINGUN VALOR
	return 0;
}
