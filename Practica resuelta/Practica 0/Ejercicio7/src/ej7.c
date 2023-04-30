/*
 * ej7.c
 *
 *  Created on: 16 mar. 2023
 *      Author: joaqu
 */
#include <stdio.h>
#include <stdlib.h>
#define TRUE 2
int main(){

#ifdef TRUE
	/*TRUE ESTA DEFINIDO LO SACO*/
	printf("TRUE esta definido como: %d\n",TRUE);
#undef TRUE
#define TRUE 1
	printf("Nuevo valor de TRUE, esta definido como: %d\n",TRUE);
#endif
}
