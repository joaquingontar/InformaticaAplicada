/*
 * ej4.c
 *
 *  Created on: 10 mar. 2023
 *      Author: joaqu
 */
#include <stdio.h>
#include <stdlib.h>
int main(){
#define N 2
	setbuf(stdout,0);
	int i,j;
	float mat[N][N];
	//cargo la matriz
	for(i=0;i<N;i++){
		for(j=0;j<N	;j++){
			printf("ingresar el elemento (%d,%d) de la matriz\n",i,j);
			scanf("%f",&mat[i][j]);
		}
	}
	//TRAZA
	//suma de los elementos de su diagonal principal
	double suma;
	suma=0;
	for(i=0;i<N;i++){
		suma+=mat[i][i];
	}
	printf("La traza de la matriz es %.1f\n", suma);
	//TRASPUESTA
	//Las columnas de la matriz original se transforman en filas de la matriz transpuesta
	printf("Matriz traspuesta:\n");
	float tras[N][N];
	for (i=0;i<N;i++){
		for(j=0;j<N;j++){
			tras[j][i]=mat[i][j];
		}
	}
	//imprimo la matriz
	for (i=0;i<N;i++){
		for(j=0;j<N;j++){
			printf("%f\t",tras[i][j]);
		}
		printf("\n");
	}
	//PRODUCTO DE MATRICES
	printf("Ingrese otra matriz de la misma dimension que quiera multiplicar");
	float mat2[N][N];
	for(i=0;i<N;i++){
			for(j=0;j<N	;j++){
				printf("ingresar el elemento (%d,%d) de la matriz\n",i,j);
				scanf("%f",&mat2[i][j]);
			}
		}
	//para hacer el producto de matrices debo multiplicar la fila de la primera matriz por la columna de la segunda
	float prod[N][N],sum;
	int k;
	for (i=0;i<N;i++){
		for (j=0;j<N;j++){
			sum=0;
			for(k=0;k<N;k++){
			sum=mat[j][k]*mat2[k][i];
			}
			prod[j][i]=sum;
		}
	}
	//imprimo la matriz resultado
	printf("El producto de las matrices es:\n");
	for (i=0;i<N;i++){
		for(j=0;j<N;j++){
			printf("%f\t",prod[i][j]);
		}
		printf("\n");
	}
}


