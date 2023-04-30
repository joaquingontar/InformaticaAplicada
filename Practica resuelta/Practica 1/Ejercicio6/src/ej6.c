/*
 * ej6.c
 *
 *  Created on: 8 abr. 2023
 *      Author: joaqu
 */
#include <stdio.h>
#include <stdlib.h>
typedef enum { MAYUSCULAS, MINUSCULAS } may_min;

// ESCRIBIR LAS FUNCIONES  QUE SE ENCUNETRAN
int strLargo(const char *origen); //Cantidad de caracteres
int strVacio(const char *origen); //retorna 1 si tiene al menos un caracter, 0 en otro caso
void strCopia(char *destino, const char *origen); // Copiador
/*prototipo modificado para permitir argumentos de tipo string literales, en casi todos los compiladores un literal string es considerado una constante, o sea la función no podría modificarlos pero, en algunos compiladores tales como GCC es posible modificarlos (según K&R el comportamiento es indefinido)*/
char* reverse(char *string);//retorna una cadena que es string invertida
void strIzq(char *destino, const char *origen); // Saca blancos Izq.
void strDer(char *destino, const char *origen); // Saca blancos Der.
void strAmbos(char *destino, const char *origen); // Saca blancos Izq. y Der.
void strMayMin(char *destino, const char *origen, may_min m); // Convierte May. Min.


int main(){
char *text1 =" Sera Cierto ?? ";
int largo=strLargo(text1)+1;
char *result = (char *)malloc (largo);
char* reves;
if(result == NULL)
return -1;//sino pudo reservar memoria para result
printf("La cadena: ");
puts(text1);
printf("Se encuentra: %s\n",(strVacio(text1) ? "No vacia" : "Vacia"));
printf("Largo : %d\n", strLargo(text1));
strCopia(result,text1);
printf("Copia : [%s]\n", result);
strIzq(result,text1);
printf("Sin blancos a la Izq:");
puts(result);
strDer(result,text1);
printf("Der : [%s]\n", result);
//strAmbos(result,text1);
//printf("Ambos: [%s], sin blancos al principio ni al final.\n", result);
//strMayMin(result,text1, MAYUSCULAS);
//printf("Mayusculas : [%s]\n", result);
//strMayMin(result,text1, MINUSCULAS);
//printf("Minusculas : [%s]\n", result);
//reves=reverse(text1);
//printf("La cadena: %s invertida queda: %s\n",text1, reves);
//return 0;
}

int strLargo(const char *origen){
	//esta funcion determina el largo el largo de la cadena
	int largo=0;
	while(*(origen+largo)!='\0'){
		largo=largo+1;
	}
	return(largo);
}
int strVacio(const char *origen){
	//esta funcion determina si el string esta vacio o no
	if(*origen==NULL){
		return(0);
	}
	else{
		return(1);
	}
}
void strCopia(char *destino, const char *origen){
	//esta funcion copia el string en otra variable puntero
	int i=0;
	while(*(origen+i)!='\0'){
		*(destino+i)=*(origen+i);
		i++;
	}
*(destino+i)='\0';
}

char* reverse(char *string){
	//esta funcion copia el string en otra variable pero dada vuelta
	int larg;
	char *destino;
	larg=strLargo(string); //utilizo la funcion largo
	char* rever=(char*)malloc(larg+1);
	int i=0;
	while(*(string+i)!='\0'){
		*(destino+i)=*(string+larg-1-i);
		i++;
	}
	*(destino+i)='\0';
}

void strIzq(char *destino, const char *origen){
	//esta funcion saca los espacios en blancos de la izquierda del string
	int i=0;
	while(*(origen+i)==' '){
		i=i+1;
	}
	strCopia(destino,(origen+i));
}
void strDer(char *destino, const char *origen){
	//esta funcion saca los espacios en blancos de la derecha del string
	char*pt;
	pt=reverse(origen);//doy vuelta la frase
	strIzq(destino, pt); //le quito el espacio de la izquierda
	pt=reverse(destino);//doy vuelta la frase nuevamente
	strCopia(destino, pt);
}

