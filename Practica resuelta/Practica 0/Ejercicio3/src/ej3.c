/*
 * ej3.c
 *
 *  Created on: 10 mar. 2023
 *      Author: joaqu
 */
#include <stdio.h>
#include <stdlib.h>
int main(){
setbuf(stdout,0);
	int mes,cant_dias,agua,mayor,menor,i,dia_mayor,dia_menor,suma;
	printf("ingrese un numero del 1 al 12 dependiendo del mes\n");
	scanf("%d",&mes);
	while(mes<=0 && mes>12){
		printf("mes ingresado incorrecto. Ingrese otro numero");
		scanf("%d",&mes);
	}
	if(mes==1||mes==3||mes==5||mes==7||mes==9||mes==11){
		cant_dias=31;
		printf("la cantidad de dias de este mes es %d:\n",cant_dias);
	}
	if(mes==4||mes==6||mes==8||mes==10||mes==12){
		cant_dias=30;
		printf("la cantidad de dias de este mes es %d:\n",cant_dias);
	}
	if(mes==2){
		cant_dias=28;
		printf("la cantidad de dias de este mes es: %d\n",cant_dias);
	}
	printf("Ingrese la cantidad de agua caida (mm) del dia 1\n");
	scanf("%d",&agua);
	mayor=agua;
	menor=agua;
	suma=agua;
	for(i=1;i<cant_dias;i++){
		printf("Ingrese la cantidad de agua caida (mm) del dia %d\n",i+1);
		scanf("%d",&agua);
		if (agua>mayor){
			mayor=agua;
			dia_mayor=i+1;
		}
		if (agua<menor){
			menor=agua;
			dia_menor=i+1;
		}
		suma=suma+agua;
	}
	printf("El dia que cayo mas agua es: %d \t y la cantidad fue: %d\n", dia_mayor, mayor);
	printf("El dia que cayo menos agua es: %d \t y la cantidad fue: %d\n", dia_menor, menor);
	printf("El promedio de agua caida en el mes es: %d\n", suma/cant_dias);
	return 0;
}


