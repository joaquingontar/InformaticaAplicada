/*
 * ej1.c
 *
 *  Created on: 29 abr. 2023
 *      Author: joaqu
 */

#include <stdio.h>
#include <stdlib.h>

//defino tipo de datos y funciones
typedef struct tiempo{
	int anio, mes, dia, hora, minuto, segundo;
	} Tiempo;
int compara_tiempos( Tiempo *t1, Tiempo * t2);
//main
int main(){
	Tiempo t1,t2;
	Tiempo *pt;
	*pt=t1;
	//INGRESO EL PRIMER TIEMPO
	printf("INGRESE EL PRIMER TIEMPO:\n");
	printf("anio:\n");
	scanf("%d", &pt->anio);
	printf("mes:\n");
	scanf("%d", &pt->mes);
//	printf("dia:\n");
//	scanf("%d", &t1.dia);
//	printf("hora:\n");
//	scanf("%d", &t1.hora);
//	printf("minuto:\n");
//	scanf("%d", &t1.minuto);
//	printf("segundo:\n");
//	scanf("%d", &t1. segundo);
	//INGRESO EL SEGUNDO TIEMPO
//	printf("INGRESE EL SEGUNDO TIEMPO:\n");
//	printf("anio:\n");
//	scanf("%d", &t1.anio);
//	printf("mes:\n");
//	scanf("%d", &t1. mes);
//	printf("dia:\n");
//	scanf("%d", &t1.dia);
//	printf("hora:\n");
//	scanf("%d", &t1.hora);
//	printf("minuto:\n");
//	scanf("%d", &t1.minuto);
//	printf("segundo:\n");
//	scanf("%d", &t1. segundo);

	printf("tiempo 1: %d %d", (*pt).anio, (*pt).mes);
}
