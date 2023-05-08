/*
 * codigo.c
 *
 *  Created on: 3 may. 2023
 *      Author: joaqu
 */


#include<stdio.h>
#include<stdlib.h>

enum opciones{Crear=1,Leer,Mostrar,Eliminar,Salir};

void menu(); //muestra el menú de opciones y redirecciona según la opción seleccionada
void regmenu(); //pregunta si se desea regresar al menú de opciones o se desea terminar el programa
void crear_archivo(); //Crea el archivo con casos de prueba
void leer_archivo(); //Lee el archivo con casos de prueba tal cual fue creado
void frecuencia(); //Muestra la frecuencia de aparición de cada caracter por caso de prueba en el archivo de prueba
void eliminar_archivo(); //Elimina el archivo con casos de prueba


//---------------------------------------------------------------------------------------------------


int main(){
	setbuf(stdout,0);


	menu();
}


//---------------------------------------------------------------------------------------------------



void menu(){
	int opc;

	printf("\t\t\tMenú\n");
	printf("--------------------------------------------------------\n");
	printf("\n");
	printf("1 - Crear archivo con casos de prueba (terminado)\n");
	printf("\n");
	printf("2 - Leer archivo con casos de prueba (terminado)\n");
	printf("\n");
	printf("3 - Mostrar frecuencia de caractéres en casos de prueba (en construcción)\n");
	printf("\n");
	printf("4 - Eliminar archivo con casos de prueba (terminado)\n");
	printf("\n");
	printf("5 - Salir\n");
	printf("\n");
	printf("--------------------------------------------------------\n");
	printf("\n\n");

	printf("Seleccione un opción: \n");
	scanf("%d",&opc);
	printf("\n\n");

	while(opc!=Crear && opc!=Leer && opc!=Mostrar && opc!=Eliminar && opc!=Salir ){
		printf("La opción seleccionada no es válida. Seleccione unao opción válida\n");
		setbuf(stdin,0);
		scanf("%d",&opc);
	}

	switch (opc){

	case Crear:
		crear_archivo();
		break;
	case Leer:
		leer_archivo();
		break;
	case Mostrar:
		frecuencia();
		break;
	case Eliminar:
		eliminar_archivo();
		break;
	case Salir:
		printf("Programa finalizado\n");
		break;
	}
}


//---------------------------------------------------------------------------------------------------


void regmenu(){
	setbuf(stdin,0);
	char conf;

	printf("\n\n¿Desea regresar al menú? Ingrese S para confirmar o N para terminar.\n\n");
	scanf("%c",&conf);

	while(conf!='S' && conf!='s' && conf!='N' && conf!='n'){
		printf("La opción ingresada no es válida. Ingrese S para confirmar o N para terminar\n");
		scanf("%c",&conf);
	}
	if(conf=='s' || conf=='S' ){
		menu();
	}else{
		printf("Programa finalizado.");
	}
}


//---------------------------------------------------------------------------------------------------


void crear_archivo(){

	#define NUM 93 // NUM+33 es el extremo superior del rango de valores ascii que puede tomar la variable dec. 126=NUM+33 => NUM=93
	#define CANTEL 10 // CANTEL= Cantidad máxima de elementos por caso de prueba
	int i,j,dec,cant,elem; //dec: decimal ascii , cant: cantidad casos de prueba, elem: cantidad aleatoria de elementos para el n-esimo caso
	FILE *archivo;

	printf("Ingrese la cantidad deseada de casos de prueba:\n");
	scanf("%d",&cant);
	while(cant<1){
			printf("La cantidad de casos de prueba debe ser un número positivo\n");
			scanf("%d",&cant);
		}


	srand(time(NULL));

	mkdir("datos", 0777); //crea directorio para el archivo de texto "datos"
	archivo=fopen("datos/pruebas.txt","w");

	if(archivo==NULL){
		printf("El archivo no pudo ser creado.\n");
	}else{
		for(j=1;j<=cant;j++){
			elem=1+rand()%(CANTEL); //1+rand%CANTEL devuelve una cantidad random de elementos para el caso de prueba n-esimo
			printf("El caso %d tiene %d elementos\n", j, elem);
			for (i=1;i<=elem;i++){
				dec=33+rand()%(NUM+1);//La operación resto de la división rand()%(NUM+1) devuelve un número entre 0 y NUM. De este modo es que esta línea almacena en dec número desde el 33 hasta el valor NUM+33.
				fprintf(archivo,"%c",dec);
			}
			if(j!=cant){
				fprintf(archivo,"\n"); //¡¡¡pulir doble espacio final en archivo!!!!
			}
		}
		printf("Archivo creado con éxito.\n\n");
		fclose(archivo);
	}
	regmenu();
}


//---------------------------------------------------------------------------------------------------


void leer_archivo(){


	char lec;
	int caso=1, b=0;
	FILE *archivo;

	archivo=fopen("datos/pruebas.txt","r");

	if(archivo==NULL){
		printf("El archivo no existe.\n");
	}else{
		while(!feof(archivo)){
			if(b==0){
				printf("Caso %d\n",caso);
			}
			fscanf(archivo,"%c",&lec);
			if(lec!='\n' || lec!='feof'){
				printf("%c ",lec);
				b=1;
			}else{
				b=0;
				caso+=1;
				setbuf(stdout,0);
				setbuf(stdin,0);
				printf("%c",lec);
			}
		}
		fclose(archivo);
	}



	regmenu();
}


//---------------------------------------------------------------------------------------------------

void frecuencia(){

    char lec, car;
    int b = 0, casos = 1;

    FILE *archivo;
    archivo = fopen("datos/pruebas.txt", "r");

    if (archivo == NULL){
        printf("El archivo no existe. Cree un archivo de casos de pruebas.\n");
    } else {
        while (!feof(archivo)){
            fscanf(archivo, "%c", &lec);
            if (lec == '\n'){
                casos++;
            }
        }
        printf("La cantidad de casos es %d\n\n", casos);

        // Declaración de estructura
        typedef struct {
            int *caso; // caso es un puntero a un arreglo de enteros
            int decimal;
        } ascii;

        ascii dec[93];

        // La función calloc asigna memoria inicializada en cero
        for (int i = 0; i < 93; i++) {
            dec[i].caso = (int*)calloc(casos, sizeof(int));
            dec[i].decimal=0;
        }

        // Contar frecuencia de aparición de caracteres por caso
        rewind(archivo);
        while (fscanf(archivo, "%c", &car) != EOF) {
            if (car != '\n') {
                dec[car - 33].caso[b]++;
                dec[car-33].decimal= car;
            } else {
                b++;
            }
        }

        fclose(archivo);

        // Ordenamiento
        int i, j, menor, lugar;
        for (int k = 0; k < casos; k++) {
            printf("\nCaso %d\n", k + 1);
            for (i = 0; i < 93 - 1; i++) {
                menor = dec[i].caso[k];
                lugar = i;
                for (j = i + 1; j < 93; j++) {
                	//caso en el que el siguiente es menor que la variable menor
                    if (menor > dec[j].caso[k]) {
                        menor = dec[j].caso[k];
                        lugar = j;
                    }
                    //caso en el que el siguiente es igual que la variable menor
                    if (menor == dec[j].caso[k]) {
                    	if (dec[lugar].decimal<dec[j].decimal){
							menor = dec[j].caso[k];
							lugar = j;
											}
                    }
                }
                if (lugar != i) {
                    int *temp = dec[i].caso;
                    dec[i].caso = dec[lugar].caso;
                    dec[lugar].caso = temp;

                    int tempDecimal = dec[i].decimal;
                    dec[i].decimal = dec[lugar].decimal;
                    dec[lugar].decimal = tempDecimal;
                }
            }

            // Imprimir por pantalla los casos y frecuencias asociados
            for (i = 0; i < 93; i++) {
                if (dec[i].caso[k]) {
                    printf("El caracter %d es %c y tiene frecuencia %d\n", dec[i].decimal, dec[i].decimal, dec[i].caso[k]);
                }
            }
        }

        // Liberar memoria
        for (int i = 0; i < 93; i++) {
            free(dec[i].caso);
        }
    }

    regmenu();
}

//---------------------------------------------------------------------------------------------------


void eliminar_archivo(){
	FILE *archivo;
	remove("datos/pruebas.txt");
	rmdir("datos");

	archivo=fopen("datos/pruebas.txt","r");

	if(archivo==NULL){
			printf("El archivo de pruebas fue eliminado exitosamente\n");
		}else{
			printf("El archivo de pruebas no pudo ser eliminado\n");
		}

	fclose(archivo);

	regmenu();
}
