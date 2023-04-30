/*
 * ej8.c
 *
 *  Created on: 16 mar. 2023
 *      Author: joaqu
 */
#include <stdio.h>
#include <stdlib.h>
int main(){
#define MINIMO2(a,b) ((a)<(b)?a:b)
#define MINIMO3(a,b,c) ((a)<(MINIMO2(b,c))?a:MINIMO2(b,c))
	printf("el minimo de 1 y 2 es: %d\n", MINIMO2(4,1));
	printf("el minimo del MINIMO2 y 3 es: %d\n", MINIMO3(4,3,2));
}
