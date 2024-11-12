#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TTL 150
#define DSC 500

void menuRegistrarTarjeta();
void menuPrincipal();
void push();

struct Tarjeta{
	char titulo[TTL];
	char descripcion[DSC];
	int prioridad;
	struct Tarjeta* siguiente;
};

//[1] Trivial, [2] Baja, [3] Media, [4] Alta [5] Bloqueante
typedef enum {
	TRIVIAL = 1,
	BAJA,
	MEDIA,
	ALTA,
	BLOQUEANTE
};

struct Tarjeta* crearTarjeta(char titulo[TTL], char descripcion[DSC], int prioridad){
	
	struct Tarjeta* nuevaTarjeta = (struct Tarjeta*)malloc(sizeof(struct Tarjeta));
	
	nuevaTarjeta->titulo[TTL] = titulo[TTL];
	nuevaTarjeta->descripcion[DSC] = descripcion[DSC];
	nuevaTarjeta->prioridad = prioridad;
	nuevaTarjeta->siguiente = NULL;
	
	return nuevaTarjeta;
};


void push(struct Tarjeta** tope, char titulo[TTL], char descripcion[DSC], int prioridad){
	
	struct Tarjeta* nuevaTarjeta = crearTarjeta(titulo, descripcion, prioridad);
	
	nuevaTarjeta->siguiente = *tope;
	
	*tope = nuevaTarjeta;
	
	printf("Tarjeta %s a�adida.\n", nuevaTarjeta->titulo);
	
}

void registrarTarjeta(){
	struct Tarjeta* tope = NULL;
	char titulo[TTL], descripcion[DSC];
	int prioridad, opt;
	do{
		
		printf("Escribe el titulo: \n");
		fgets(titulo, sizeof(titulo), stdin);
		//limpia el bufer para evitar que se mezclen datos, igual en descripcion
		titulo[strcspn(titulo, "\n")] = 0;
		 
		printf("Descripcion:\n");
		fgets(descripcion, sizeof(descripcion), stdin);
		descripcion[strcspn(descripcion, "\n")] = 0;
		
		printf("Prioridad: [1] Trivial, [2] Baja, [3] Media, [4] Alta [5] Bloqueante");
		
		while(scanf("%d", &prioridad) != 1 || prioridad < 1 || prioridad > 5){	
			printf("Ingresa una opci�n valida para la prioridad\n");
			while (getchar() != '\n'); //limpiar el bufer
		}
		
		push(&tope, titulo, descripcion, prioridad);
		
		printf("Titulo: %s", titulo);
		printf("\nDescripcion:");
		printf("\n%s", descripcion);
		printf("\nPrioridad: %d", prioridad);
		
		printf("A�adir nueva tarjeta?\n");
		printf("[1]Si / [2]No\n");
		while(scanf("%d", &opt)!=1 || opt < 1 || opt >2){
			printf("Por favor, ingresa una opcion valida para la prioridad\n");
			while (getchar() != '\n'); //limpiar el bufer
		}
		while (getchar() != '\n'); //limpiar el bufer
	}while(opt!=2);
}

//Espacio para función delet tasks

//Espacio para la funcion update

void menuRegistrarTarjeta(){
	int opt;
	system("cls");
	printf("==================================================\n");
	printf("|                                                |\n");
	printf("|                                                |\n");
	printf("|                  To-Do List                    |\n");
	printf("|                                                |\n");
	printf("|   Presiona una de las opciones para continuar  |\n");
	printf("==================================================\n");
	printf("\n\n");
	printf("[1] Nueva tarjeta\n");
	printf("[2] Editar tarjeta\n");
	printf("[0] Atr�s\n");

	scanf("%d", &opt);
	while (getchar() != '\n'); //limpiar el bufer
	
	switch(opt){
		case 0:
			menuPrincipal();
			break;
		case 1:
			registrarTarjeta();
			break;
		case 2:
			printf("Editar una tarjeta xd");
			break;
		default:
			system("cls");
			menuRegistrarTarjeta();
	}
	
}

void menuPrincipal(){
	int opt;
	system("cls");
	printf("==================================================\n");
	printf("|                                                |\n");
	printf("|                                                |\n");
	printf("|                  To-Do List                    |\n");
	printf("|                                                |\n");
	printf("|   Presiona una de las opciones para empezar    |\n");
	printf("==================================================\n");
	printf("\n\n");
	printf("[1] Registrar nueva tarjeta\n");
	printf("[2] Listar tarjetas\n");
	printf("[0] Salir\n");

	scanf("%d", &opt);
	while (getchar() != '\n'); //limpiar el bufer
	
	switch(opt){
		case 0:
			return;
		case 1:
			menuRegistrarTarjeta();
			break;
		case 2:
			printf("xd2");
			break;
		default:
			system("cls");
			menuPrincipal();
	}
}

void prubeadecambio(){

}

int main(){
	
	menuPrincipal();
	
	return 0;
}