#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define TAM 10
struct Clientes{
	char nom[30];
	char operacion[50];
};
Clientes cola[TAM];
int indice=0;

void push(Clientes);
Clientes pop(void);
int colallena(void);
int colavacia(void);
void listarcola(void);

int main (){
	int opc,caja;
	Clientes cliente;
	
	do{
		printf("FILA\n");
		printf("1.Agregar a Fila\n");
		printf("2.Atender\n");
		printf("3.Listar Fila\n");
		printf("4.Salir\n");
		printf("Dame la opcion: ");
		scanf("%d",&opc);
		
		switch(opc){
			case 1: 
				system("cls");
				if(colallena()==0){
					printf("Ingresa el nombre: ");
					fflush(stdin);
					gets(cliente.nom);
				
					printf("Ingresa la operacion: ");
					fflush(stdin);
					gets(cliente.operacion);
				
								
				
					push(cliente);
					
					
				}else{
					
					printf("Cola Llena\n");
				}
				system("pause");
				system("cls");
				
				break;
			case 2:
				system("cls");
				if(colavacia()==0){
					printf("Ingresa el numero de caja: ");
					scanf("%d",&caja);
					cliente=pop();
					printf("%s favor de pasar a la caja %d para: %s\n",cliente.nom,caja,cliente.operacion);
					
					
				}else{
					
					printf("Cola Vacia\n");
					
				}
				system("pause");
				system("cls");
				
				break;			
				
			case 3:
				system("cls");
				if(colavacia()==0){
					listarcola();	
				}
				else{
					printf("Fila vacia\n");	
				}
				
				system("pause");
				system("cls");
				
				break;
				
		}
		
		
		
		
	}while(opc!=4);	

	return 0;

}
void push(Clientes clientes){
	
	cola[indice]=clientes;
	indice++;
}
Clientes pop(void){
	Clientes temp=cola[0];
	for(int i=0;i<indice-1;i++){
		cola[i]=cola[i+1];
	}
	indice--;
	return temp;
	
	
}

int colallena(void){
	if(indice==TAM){
		return 1;
		
	}
	else{
		return 0;
	}
	
}
int colavacia(void){
	if(indice==0){
		return 1;
		
	}
	else {
		return 0;
	}
	
}
void listarcola(void){
	for(int i=0;i<indice;i++){
		printf("Nom: %s Operacion: %s \n",cola[i].nom,cola[i].operacion);
		
		
	}
	
	
	
}
