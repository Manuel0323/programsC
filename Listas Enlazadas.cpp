#include<stdio.h>
#include<stdlib.h>
struct ELista{
	int valor;
	ELista *sig;
	
};



int main(){
	int opc, temp;
	ELista *inicio;
	inicio=NULL;
	ELista *nodo;
	ELista *aux;
	do{
		system("cls");
		printf("\t Menu\n");
		printf("1. Agregar Nodo al Principio\n");
		printf("2. Agregar Nodo al Final\n");
		printf("3. Agregar Nodo Intermedio\n");
		printf("4. Borrar el Primer Nodo\n");
		printf("5. Borrar el Ultimo Nodo\n");
		printf("6. Borrar el Nodo Intermedio\n");
		printf("7. Borrar Lista\n");
		printf("8. Recorrer Lista\n");
		printf("9. Salir\n");
		printf("Ingresa la opcion: ");
		scanf("%d",&opc);
		switch(opc){
			case 1: 
				system("cls");
				nodo=(struct ELista*)malloc(sizeof(ELista));
				printf("Valor del Nodo Nuevo: ");
				scanf("%d",&nodo->valor);
				nodo->sig=inicio;
				inicio=nodo;
				printf("Nodo Agregado\n");
				system("pause");
				break;
			
			case 2:
				system("cls");
				nodo=(struct ELista*)malloc(sizeof(ELista));
				printf("Valor del Nodo Nuevo: ");
				scanf("%d",&nodo->valor);
				nodo->sig=NULL;
				aux=inicio;
				while(aux->sig!=NULL){
					aux=aux->sig;
				}
				aux->sig=nodo;
				printf("Nodo Agregado\n");
				system("pause");
				break;
			case 3:
				system("cls");
				nodo=(struct ELista*)malloc(sizeof(ELista));
				printf("Valor del Nodo Nuevo: ");
				scanf("%d",&nodo->valor);
				printf("Valor del Nodo Anterior a la Posicion Deseada: ");
				scanf("%d",&temp);
				aux=inicio;
				while(aux->valor!=temp and aux!=NULL){
					aux=aux->sig;
				}
				if(aux!=NULL){
					nodo->sig=aux->sig;
					aux->sig=nodo;
					printf("Nodo Agregado\n");
				}else{
					printf("Nodo Anterior a la Posicion Deseada no Encontrado");
				}
				system("pause");
				break;	
			case 4: 
				system("cls");
				inicio=inicio->sig;
				printf("Primer Nodo Eliminado\n");
				system("pause");
			 	break;
			 	
			case 5:
				system("cls");
				aux=inicio;
				while(aux->sig->sig!=NULL){
					aux=aux->sig;
				}
				aux->sig=NULL;
				printf("Ultimo Nodo Eliminado\n");
				system("pause");
				break;
				
			case 6:
				system("cls");
				printf("Valor del Nodo a Eliminar:");
				scanf("%d",&temp);
				aux=inicio;
				while(aux->sig->valor!=temp and aux!=NULL){
					aux=aux->sig;
				}
				if(aux!=NULL){
					aux->sig=aux->sig->sig;
					printf("Nodo Eliminado\n");
				}else{
					printf("Nodo No Encontrado\n");
				}
				system("pause");
				break;
				
			case 7:
				system("cls");
				inicio=NULL;
				printf("Lista Borrada\n");
				system("pause");
				break;
				
			case 8:
				system("cls");
				aux=inicio;
				printf("inicio");
				while(aux!=NULL){
					printf("->%d",aux->valor);
					aux=aux->sig;
				}
				printf("->NULL\n");
				system("pause");
				break;
				
			case 9:
				system("cls");
				printf("Adios\n");
				system("pause");
				break;
			default:
				system("cls");
				printf("Opcion Invalida\n");
				system("pause");
				break;
		}
	}while(opc!=9);
	
	
	
	return 0;
}
