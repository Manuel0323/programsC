/*
Manejo de ventas
Catalogo de Articulos: Clave, Descripcion, costo, precio, inventario, canitdad minima).
Opciones:
1. Alta de un articulo
2. Surtir inventario
3. Consulta Inentario
4. Venta
5. Consulta de Ventas
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>

struct EArticulos{
	int clave;
	char descripcion[30];
	float costo, precio;
	int inventario, minimo;
};

struct EVentas{
	int noventa;
	int clave;
	char descripcion[30];
	int cantidad;
	float precio;	
};

 void gotoxy(int x,int y){  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
 } 

int main(){
	EArticulos articulos[50];
	EVentas ventas[10000];
	char resp;
	int clave,i, posicion=-1, cantidad;
	int indicearticulos = 0;
	int indiceventas = 0;
	int indiceventa = 1;
	int noventa;
	int renglon=0;
	float subtotal=0;
	int opcion=0;
	do{
		system("cls");
		printf("MENU DE OPCIONES\n");
		printf("1. Alta de articulos\n");
		printf("2. Surtir inventario\n");
		printf("3. Consulta de Inventario\n");
		printf("4. Ventas\n");
		printf("5. Consulta de Ventas\n");
		printf("6. Salir\n");
		printf("Indique una opcion: ");
		scanf("%d",&opcion);
		switch(opcion){
			case 1:
				system("cls");
				if(indicearticulos<50){				
					printf("ALTA DE ARTICULOS\n");
					printf("Indique la clave del producto: ");
					scanf("%d",&articulos[indicearticulos].clave);
					fflush(stdin);
					printf("Indique la descripcion del producto: ");
					gets(articulos[indicearticulos].descripcion);
					printf("Indique el costo del producto: ");
					scanf("%f",&articulos[indicearticulos].costo);
					printf("Indique el precio del producto: ");
					scanf("%f",&articulos[indicearticulos].precio);
					printf("Indique la cantidad en inventario del producto: ");
					scanf("%d",&articulos[indicearticulos].inventario);
					printf("Indique la cantidad minima en inventario del producto: ");
					scanf("%d",&articulos[indicearticulos].minimo);
					indicearticulos++;					
					printf("ARTICULO DADO DE ALTA");
					Sleep(2000);
				}else{
					printf("No existe capacidad para almacenar mas articulos");
				}
				break;
				
			case 2:
				posicion=-1;
				system("cls");
				printf("SURTIR EN INVENTARIO\n");
				printf("Clave del producto a buscar: ");
				scanf("%d",&clave);
				for(i=0;i<indicearticulos;i++){
					if(articulos[i].clave==clave){
						posicion = i;
					}
				}
				if(posicion!=-1){
					printf("¿Seguro que desea surtir el inventario de %d-%s (s/n)?", articulos[posicion].clave, articulos[posicion].descripcion);
					fflush(stdin);
					scanf("%c",&resp);
					if(resp=='s' || resp=='S'){
						printf("Indique la cantidad a surtir: ");
						
						scanf("%d",&cantidad);
						articulos[posicion].inventario=articulos[posicion].inventario+cantidad;
						printf("INVENTARIO SUTRIDO EXITOSAMENTE");
						Sleep(2000);
					}
				}else{
					printf("CLAVE DE ARTICULO NO ENCONTRADA");
					Sleep(2000);
				}
				break;
				
			case 3:
				system("cls");
				gotoxy(20,5);printf("INVENTARIO");
				gotoxy(5,6);printf("_________________________________________________________________________________");
				gotoxy(5,7);printf("|Clave");
				gotoxy(15,7);printf("|Descripcion");
				gotoxy(35,7);printf("|Costo");
				gotoxy(45,7);printf("|Precio");
				gotoxy(55,7);printf("|Inventario");
				gotoxy(68,7);printf("|Minimo");
				gotoxy(78,7);printf("|Surtir|");
				gotoxy(5,8);printf("¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯");
				for(i=0;i<indicearticulos;i++){
					gotoxy(5,9+i);printf("%d",articulos[i].clave);
					gotoxy(15,9+i);printf("%s",articulos[i].descripcion);
					gotoxy(35,9+i);printf("%.2f",articulos[i].costo);
					gotoxy(45,9+i);printf("%.2f",articulos[i].precio);
					gotoxy(55,9+i);printf("%d",articulos[i].inventario);
					gotoxy(68,9+i);printf("%d",articulos[i].minimo);
					if(articulos[i].inventario<=articulos[i].minimo){
						gotoxy(78,9+i);				
						printf(" ***");
					}					
				}						
				gotoxy(5,20);
				system("pause");
				break;
				
			case 4:
				renglon=0;
				subtotal=0;
				system("cls");
				gotoxy(20,4);printf("VENTAS DE PRODUCTOS");
				gotoxy(20,5);printf("VENTA #%d",indiceventa);
				gotoxy(5,7);printf("|Clave");
				gotoxy(15,7);printf("|Descripcion");
				gotoxy(55,7);printf("|Cantidad");
				gotoxy(65,7);printf("|Precio");
				gotoxy(75,7);printf("|Importe|");
				gotoxy(5,8);printf("¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯");
				do{
					gotoxy(6,9+renglon);printf("_____");
					gotoxy(6,9+renglon);
					scanf("%d",&clave);
					posicion = -1;
					for(i=0;i<indicearticulos;i++){
						if(articulos[i].clave==clave){
								posicion = i;
						}
					}
					if(posicion!=-1){
						gotoxy(6,9+renglon);printf("     ");
						gotoxy(6,9+renglon);printf("%d",clave);
						gotoxy(16,9+renglon);printf("%s",articulos[posicion].descripcion);	
						gotoxy(66,9+renglon);printf("%.2f",articulos[posicion].precio);	
						gotoxy(56,9+renglon);printf("_____");
						gotoxy(56,9+renglon);scanf("%d",&cantidad);
						gotoxy(56,9+renglon);printf("     ");
						gotoxy(56,9+renglon);printf("%d",cantidad);
						while(articulos[posicion].inventario<cantidad){
							gotoxy(80,9+renglon);printf("Cantidad no suficiente en inventario");
							Sleep(1000);
							gotoxy(80,9+renglon);printf("                                    ");
							gotoxy(56,9+renglon);printf("_____");
							gotoxy(56,9+renglon);scanf("%d",&cantidad);
							gotoxy(56,9+renglon);printf("     ");
							gotoxy(56,9+renglon);printf("%d",cantidad);
						}
						gotoxy(76,9+renglon);printf("%.2f",cantidad*articulos[posicion].precio);
						articulos[posicion].inventario-=cantidad;
						ventas[indiceventas].noventa=indiceventa;
						ventas[indiceventas].clave=clave;
						strcpy(ventas[indiceventas].descripcion,articulos[posicion].descripcion);
						ventas[indiceventas].cantidad=cantidad;
						ventas[indiceventas].precio = articulos[posicion].precio;
						subtotal+=cantidad*articulos[posicion].precio;
						indiceventas++;
						renglon++;						
				
					}else{
						if(clave!=0){						
							gotoxy(16,9+renglon);printf("CLAVE DE ARTICULO NO ENCONTRADA");
						}
						Sleep(2000);
						gotoxy(16,9+renglon);printf("                               ");
					}	
				}while(clave!=0);
				gotoxy(65,10+renglon);printf("Subtotal: ");
				gotoxy(65,11+renglon);printf("IVA:");
				gotoxy(65,12+renglon);printf("Total:");
				gotoxy(75,10+renglon);printf("%.2f",subtotal);
				gotoxy(75,11+renglon);printf("%.2f",subtotal*0.16);
				gotoxy(75,12+renglon);printf("%.2f",subtotal*1.16);
				indiceventa++;
				printf("\n\n");				
				system("pause");
				break;
			
			case 5:
				subtotal=0;
				system("cls");
				printf("Indica la venta a consultar (0 para todas las ventas): ");
				scanf("%d",&noventa);
				gotoxy(1,7);printf("|# Ve");
				gotoxy(5,7);printf("|Clave");
				gotoxy(15,7);printf("|Descripcion");
				gotoxy(55,7);printf("|Cantidad");
				gotoxy(65,7);printf("|Precio");
				gotoxy(75,7);printf("|Importe|");
				gotoxy(1,8);printf("¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯");
				renglon=2;
				for(i=0;i<indiceventas;i++){
					
					if(ventas[i].noventa==noventa||noventa==0){					
						gotoxy(2,7+renglon);printf("%d",ventas[i].noventa);
						gotoxy(6,7+renglon);printf("%d",ventas[i].clave);
						gotoxy(16,7+renglon);printf("%s",ventas[i].descripcion);
						gotoxy(56,7+renglon);printf("%d",ventas[i].cantidad);
						gotoxy(66,7+renglon);printf("%.2f",ventas[i].precio);
						gotoxy(76,7+renglon);printf("%.2f",ventas[i].cantidad*ventas[i].precio);
						subtotal+=ventas[i].cantidad*ventas[i].precio;					
						renglon++;
					}
					
										
				}
				gotoxy(65,10+renglon);printf("Subtotal: ");
				gotoxy(65,11+renglon);printf("IVA:");
				gotoxy(65,12+renglon);printf("Total:");
				gotoxy(75,10+renglon);printf("%.2f",subtotal);
				gotoxy(75,11+renglon);printf("%.2f",subtotal*0.16);
				gotoxy(75,12+renglon);printf("%.2f",subtotal*1.16);
				printf("\n\n");
				system("pause");
				break;
			
		}		
	}while(opcion!=6);
	return 0;
}

