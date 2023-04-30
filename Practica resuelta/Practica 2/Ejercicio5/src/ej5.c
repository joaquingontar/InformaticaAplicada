/*
 * ej5.c
 *
 *  Created on: 28 abr. 2023
 *      Author: joaqu
 */


#include<stdio.h>
#include<stdlib.h>

typedef union{
	unsigned char c;
		struct{ //declare una estructura en mi nuevo tipo de dato que es Ascii
			char b1:1;
			char b2:1;
			char b3:1;
			char b4:1;
			char b5:1;
			char b6:1;
			char b7:1;
			char b8:1;
		}byte;
}Ascii;
Ascii cambiar(Ascii byte);

main(){
	printf("ingrese una cadena de caracteres que represente los bits de un numero del codigo ascii");
	scanf("%s", )
}

Ascii cambiar(Ascii byte){
	if(byte.b1==0){
		byte.b1=1;
	}
	else{
		byte.b1=0;
	}
	if(byte.b3==0){
		byte.b3=1;
		}
	else{
		byte.b3=0;
		}
	if(byte.b5==0){
		byte.b5=1;
	}
	else{
		byte.b5=0;
	}
	if(byte.b7==0){
		byte.b7=1;
	}
	else{
		byte.b7=0;
	}
}

