#include<stdio.h>
#include<stdlib.h>

enum opciones{Crear=1,Leer,Mostrar,Eliminar,Salir};

void menu(); //muestra el menú de opciones y redirecciona según la opción seleccionada
void regmenu(); //pregunta si se desea regresar al menú de opciones o se desea terminar el programa
void crear_archivo(); //Crea el archivo con casos de prueba
void leer_archivo(); //Lee el archivo con casos de prueba tal cual fue creado
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

	while(opc<1 || opc>5){
		printf("La opción seleccionada no es válida. Seleccione unao opción válida\n");
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
		printf("Opción en construcción\nPrograma finalizado\n");
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

	printf("¿Desea regresar al menú? Ingrese S para confirmar o N para terminar.\n\n");
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

	#define NUM 94
	int i,j,dec,cant,elem; //dec: decimal ascii , cant: cantidad casos de prueba, elem: cantidad random de elementos para el n-esimo caso
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
			elem=1+rand()%1001; //1+rand%1001 devuelve una cantidad random de elementos para el caso de prueba n-esimo
			printf("El caso %d tiene %d elementos\n", j, elem);
			for (i=1;i<=elem;i++){
				dec=33+rand()%(NUM+1);//La operación resto de la división rand()%(NUM+1) devuelve un número entre 0 y NUM. De este modo es que esta línea almacena en dec número desde el 33 hasta el valor NUM+33.
				fprintf(archivo,"%c",dec);
			}
			fprintf(archivo,"\n\n");
		}
		printf("Archivo creado con éxito.\n\n");
		fclose(archivo);
	}
	regmenu();
}


//---------------------------------------------------------------------------------------------------


void leer_archivo(){

	char lec;
	FILE *archivo;

	archivo=fopen("datos/pruebas.txt","r");

	if(archivo==NULL){
			printf("El archivo no existe.\n");
		}else{
				while(!feof(archivo)){
					fscanf(archivo,"%c",&lec);
					printf("%c ",lec);
				}
				fclose(archivo);
		}
	regmenu();
}

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
