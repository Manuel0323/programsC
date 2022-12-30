#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define YEAR 2019
struct PASAJEROS{
	char nombre[30];
	int dia;
	int mes;
	int pago;
};

int main (){
	int asiento[20][6],x,y,opc,fila,columna,indice=0,band,cont;
	PASAJEROS p[20][6];
	char ccolumna,opc2;
	for(y=0;y<20;y++){
		for(x=0;x<6;x++){
			asiento[y][x]=-1;
		}
	}
	do{
		system("cls");
		printf("\tMENU\n");
		printf("1.Reservar un Asiento.\n");
		printf("2.Cancelar Reservacion.\n");
		printf("3.Consultar Reservaciones.\n");
		printf("4.Mostrar Asientos Disponibles.\n");
		printf("5.Salir.\n");
		printf("Elige una opcion: ");
		scanf("%d",&opc);
		
		switch(opc){
			case 1:
				do{
				system("cls");
					do{
						cont=0;
						band=0;
						printf("\tRESERVACION\n");
						printf("Elija la Columna (A,B,C,D,E,F): ");
						fflush(stdin);
						scanf("%c",&ccolumna);
						switch(ccolumna){
							case 'a':case'A':
								columna=0;
								break;
							case 'b':case'B':
								columna=1;
								break;
							case 'c':case'C':
								columna=2;
								break;
							case'd':case'D':
								columna=3;
								break;
							case'e':case'E':
								columna=4;
								break;
							case'f':case'F':
								columna=5;
								break;	
							default:
								printf("Opcion Invalida.\n");
								band=1;
								system("pause");
								break;
						}	
					}while(band==1);
					printf("Elija la Fila (1-20): ");
					scanf("%d",&fila);
					fila=fila-1;
					if(asiento[fila][columna]!=-1){
						printf("Asiento Ocupado.\n");
						system("pause");
					}
				}while(asiento[fila][columna]!=-1);	
				for(y=0;y<20;y++){
					for(x=0;x<6;x++){
						if(asiento[y][x]!=-1){
							cont++;
						}
					}
				}
				if(cont<120){
					printf("Nombre: ");
					fflush(stdin);
					gets(p[fila][columna].nombre);
					printf("FECHA:\n");
					do{
						printf("Dia: ");
						scanf("%d",&p[fila][columna].dia);
						if(p[fila][columna].dia>31 or p[fila][columna].dia<1){
							printf("Dia Invalido.\n");
						}
					}while(p[fila][columna].dia>31 or p[fila][columna].dia<1);
					do{
						printf("Mes(1:Enero,2:Febrero...): ");
						scanf("%d",&p[fila][columna].mes);	
						if(p[fila][columna].mes>12 or p[fila][columna].mes<1){
							printf("Mes Invalido.\n");
						}
					}while(p[fila][columna].mes>12 or p[fila][columna].mes<1);
					do{
						printf("Tipo de Pago(1.Pago en Efectivo, 2.Pago con Tarjeta): ");
						scanf("%d",&p[fila][columna].pago);
					}while(p[fila][columna].pago<1 or p[fila][columna].pago>2);
					
					asiento[fila][columna]=indice;
					printf("Asiento Reservado.\n");	
					indice++;
				}else{
					printf("AVION LLENO.\n");
				}
				system("pause");
				break;
			case 2:
				do{
					band=0;
					system("cls");
					printf("\tCANCELACION\n");
					printf("Elija la Columna (A,B,C,D,E,F): ");
					fflush(stdin);
					scanf("%c",&ccolumna);
					switch(ccolumna){
						case 'a':case'A':
							columna=0;
							break;
						case 'b':case'B':
							columna=1;
							break;
						case 'c':case'C':
							columna=2;
							break;
						case'd':case'D':
							columna=3;
							break;
						case'e':case'E':
							columna=4;
							break;
						case'f':case'F':
							columna=5;
							break;	
						default:
							printf("Opcion Invalida.\n");
							band=1;
							system("pause");
							break;
						}	
				}while(band==1);
				printf("Elija la Fila (1-20): ");
				scanf("%d",&fila);
				fila=fila-1;
				if(asiento[fila][columna]!=-1){
					printf("\tDATOS\n");
					printf("Nombre: %s\n",p[fila][columna].nombre);
					printf("Fecha de Reservacion: %d/%d/%d\n",p[fila][columna].dia,p[fila][columna].mes,YEAR);
					switch(p[fila][columna].pago){
						case 1:
							printf("Pago: Efectivo\n");					
							break;
						case 2:
							printf("Pago: Tarjeta\n");
							break;
					}
					printf("\nSeguro que desea cancelar esta reservacion?(s/n): ");
					fflush(stdin);
					scanf("%c",&opc2);
					if(opc2=='s' or opc2=='S'){
						asiento[fila][columna]=-1;
						printf("Reservacion Cancelada con Exito.\n");
					}
				}else{
					printf("Asiento Sin Reservacion.\n");
				}
				system("pause");
				break;
			case 3:
				system("cls");	
				printf("\tCONSULTA\n");
				for(y=0;y<20;y++){
					for(x=0;x<6;x++){
						if(asiento[y][x]!=-1){
							printf("Pasajero %d:\n",asiento[y][x]+1);
							printf("Nombre: %s\n",p[y][x].nombre);
							printf("Fecha: %d/%d/%d\n",p[y][x].dia,p[y][x].mes,YEAR);
							switch(p[y][x].pago){
								case 1:
									printf("Pago: Efectivo\n");
									break;
								case 2:
									printf("Pago: Tarjeta\n");
									break;	
							}
							switch(x){
								case 0:
									ccolumna='A';
									break;
								case 1:
									ccolumna='B';
									break;
								case 2:
									ccolumna='C';
									break;
								case 3:
									ccolumna='D';
									break;
								case 4:
									ccolumna='E';
									break;	
								case 5:
									ccolumna='F';
									break;
							}
							fila=y+1;
							printf("Asiento: %c,%d\n\n",ccolumna,fila);
						}
					}
				}
				system("pause");
				break;
			case 4:
				system("cls");
				printf("\tA\tB\tC\tF\tE\tF\n");
				for(y=0;y<20;y++){
					printf("%d\t",y+1);
					for(x=0;x<6;x++){
						if(asiento[y][x]!=-1){
							printf("%d",asiento[y][x]+1);
						}
						printf("\t");
					}
					printf("\n");
				}
				system("pause");
				break;
			case 5:
				break;
			default:
				printf("OPCION INVALIDA.\n");
				system("pause");
				break;	
		}
	}while(opc!=5);
	return 0;
}
