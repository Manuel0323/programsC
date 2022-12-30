#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
 void gotoxy(int x,int y){  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
 } 
struct Cliente{
	char nom[50],calle[30],ciudad[30];
	int numdecasa,cp;
	int num=-1;
	long long int numcliente;
};
struct Articulos{
	char desc[30];
	int codigo=-1;
	int cant;
	float precio;
	float costo;
	float descuento;
};
struct PRODUCTOS{
	char desc[10][30]={"LAPIZ","PLUMA","BORRADOR","CUADERNOS RAYA","CUADERNOS CUAD.","CARPETAS","ENGARGOLADO","TIJERAS","MARCADORES","HOJAS DE COLOR"};
	int codigo[10]={1,2,3,4,5,6,7,8,9,10};
	float precio[10]={3,2.5,3,15,15,2,25.5,17.5,20,2};
};
int main (){
	const float desc0=.05,desc1=.1,desc2=.15,desc3=.2,desc4=.25,desc5=.3,desc6=.5,IVA=1.16;
	int opc,hora,mes,year,dia,indice=0,numcliente,numvendedor,cp,unidades,codigobusc,indenc=0,num[10],tempu[10],temp,y,indfac=0,cant,band1=0;
	char calle[30],colonia[30],cd[30],nomvendedor[30];
	char resp;
	long int tel;
	float total,subtotal,pago,descuento;
	int x,band=0,codbusc,c=0;
	int renglon=0;
	PRODUCTOS prod;
	Cliente cliente[20];
	Articulos arti[10];
	FILE *comprobante;
	char nom[]=("comprobante.txt");
	comprobante=fopen(nom,"w");
	
	do{
		system("cls");
		printf("		PAPELERIA CASTORES\n");
		printf("MENU:\n");
		printf("1. LLENAR DATOS DE FACTURA\n");	
	 	printf("2. INSERTAR ARTICULOS  \n");
	 	printf("3. CONSULTAR O VISUALIZAR ARTICULOS  \n");
	 	printf("4. ELIMINAR ARTICULOS  \n");
	 	printf("5. ORDENAR ARTICULOS (NUMERO DE UNIDADES)  \n");
	 	printf("6. CONSULTAR FACTURA  \n");
	 	printf("7. FACTURA NUEVA\n");
		printf("8. SALIR  \n\n");
		printf("Introduce la opcion: ");
		scanf("%d",&opc);
		switch(opc){
			case 1:
				system("cls");
					printf("Desea Crear Factura?(s/n)");
					fflush(stdin);
					scanf("%c",&resp);
					if(resp=='s' || resp=='S'){
						printf("Ingresa el dia: ");
						scanf("%d",&dia);
						printf("Ingresa el mes: ");
						scanf("%d",&mes);
						printf("Ingresa la hora: ");
						scanf("%d",&hora);
						fflush(stdin);
						printf("Ingresa el nombre del cliente:  ");
						scanf("%s",cliente[c].nom);
						fflush(stdin);
						printf("Ingresa la ciudad del cliente:  ");
						scanf("%s",cliente[c].ciudad);
						fflush(stdin);
						printf("Ingresa el nombre de la calle del cliente:  ");
						scanf("%s",cliente[c].calle);
						fflush(stdin);
						printf("Ingresa el numero de la casa del cliente:  ");
						scanf("%d",&cliente[c].numdecasa);
						printf("Ingresa el codigo postal: ");
						scanf("%d",&cliente[c].cp);
						printf("Ingresa el numero telefonico del cliente:  ");
						scanf("%lli",&cliente[c].numcliente);
						indfac++;
						cliente[c].num=indfac;
						
					}else{
						printf("Adios\n");
					}
				Sleep(1000);
				
				
				system("pause");
			
			break;
			case 2:
				system("cls");
				printf("	LISTA DE PRODUCTOS\n");
				printf(" NOM PRODUCTO 		PRECIO\n");
				printf("1. LAPIZ 		$3.00\n");
				printf("2. PLUMA 		$2.50\n");
				printf("3. BORRADOR 		$3.00\n");
				printf("4. CUADERNOS (Raya) 	$15.00\n");
				printf("5. CUADERNOS (Cuad.)	$15.00\n");
				printf("6. CARPETAS 	 	$2.00 \n");
				printf("7. ENGARGOLADO 		$25.50\n");
				printf("8. TIJERAS	 	$17.5O\n");
				printf("9. MARCADORES  		$20.00\n");
				printf("10. HOJAS DE COLOR 	$2.00\n");
				do{	
					printf("Gusta a%cadir un articulo? (S/N)",164);
					fflush(stdin);
					scanf("%c",&resp);
					if(resp=='s' or resp=='S'){
						if(indice<10){
							system("cls");
							printf("	LISTA DE PRODUCTOS\n");
							printf(" NOM PRODUCTO 		PRECIO\n");
							printf("1. LAPIZ 		$3.00\n");
							printf("2. PLUMA 		$2.50\n");
							printf("3. BORRADOR 		$3.00\n");
							printf("4. CUADERNOS (Raya) 	$15.00\n");
							printf("5. CUADERNOS (Cuad.)	$15.00\n");
							printf("6. CARPETAS 	 	$2.00 \n");
							printf("7. ENGARGOLADO 		$25.50\n");
							printf("8. TIJERAS	 	$17.5O\n");
							printf("9. MARCADORES  		$20.00\n");
							printf("10. HOJAS DE COLOR 	$2.00\n");
							printf("Ingresa el codigo del articulo: ");
							scanf("%d",&codigobusc);
							for(x=0;x<10;x++){
								if(codigobusc==prod.codigo[x]){
									band=1;
									indenc=x;
									
								}
							}
							for(x=0;x<indice;x++){
								if(codigobusc==arti[x].codigo){
									printf("El producto %s ya existe a%cadida a la lista de articulos, desea agregar una nueva cantidad?(s/n): ",arti[x].desc,164);
									fflush(stdin);
									scanf("%c",&resp);
									if(resp=='s' or resp=='S'){
										printf("Ingresa la cantidad: ");
										fflush(stdin);
										scanf("%d",&cant);
										arti[x].cant+=cant;
										arti[x].costo=arti[x].precio*(float)arti[x].cant;
										if(arti[x].cant>=0 and arti[x].cant<=5){
											arti[x].descuento=arti[x].costo*desc0;
											arti[x].costo=arti[x].costo-arti[x].descuento;
										}else if(arti[x].cant>=6 and arti[x].cant<=10){
											arti[x].descuento=arti[x].costo*desc1;
											arti[x].costo=arti[x].costo-arti[x].descuento;
										}else if(arti[x].cant>=11 and arti[x].cant<=15){
											arti[x].descuento=arti[x].costo*desc2;
											arti[x].costo=arti[x].costo-arti[x].descuento;
										}else if(arti[indice].cant>=16 and arti[x].cant<=20){
											arti[x].descuento=arti[x].costo*desc3;
											arti[x].costo=arti[x].costo-arti[x].descuento;
										}else if(arti[x].cant>=21 and arti[x].cant<=25){
											arti[x].descuento=arti[x].costo*desc4;
											arti[x].costo=arti[x].costo-arti[x].descuento;
										}else if(arti[x].cant>=26 and arti[x].cant<=30){
											arti[x].descuento=arti[x].costo*desc5;
											arti[x].costo=arti[x].costo-arti[indice].descuento;
										}else{
											arti[x].descuento=arti[x].costo*desc6;
											arti[x].costo=arti[x].costo-arti[x].descuento;
										}
										band=0;
										band1=1;
									}else{
										band=0;
										band1=1;
									}
								}
							}
							if(band==1){
								arti[indice].codigo=codigobusc;
								strcpy(arti[indice].desc,prod.desc[indenc]);
								arti[indice].precio=prod.precio[indenc];
								printf("Ingresa la cantidad: ");
								scanf("%d",&arti[indice].cant);
								arti[indice].costo=arti[indice].precio*(float)arti[indice].cant;
								if(arti[indice].cant>=0 and arti[indice].cant<=5){
									arti[indice].descuento=arti[indice].costo*desc0;
									arti[indice].costo=arti[indice].costo-arti[indice].descuento;
								}else if(arti[indice].cant>=6 and arti[indice].cant<=10){
									arti[indice].descuento=arti[indice].costo*desc1;
									arti[indice].costo=arti[indice].costo-arti[indice].descuento;
								}else if(arti[indice].cant>=11 and arti[indice].cant<=15){
									arti[indice].descuento=arti[indice].costo*desc2;
									arti[indice].costo=arti[indice].costo-arti[indice].descuento;
								}else if(arti[indice].cant>=16 and arti[indice].cant<=20){
									arti[indice].descuento=arti[indice].costo*desc3;
									arti[indice].costo=arti[indice].costo-arti[indice].descuento;
								}else if(arti[indice].cant>=21 and arti[indice].cant<=25){
									arti[indice].descuento=arti[indice].costo*desc4;
									arti[indice].costo=arti[indice].costo-arti[indice].descuento;
								}else if(arti[indice].cant>=26 and arti[indice].cant<=30){
									arti[indice].descuento=arti[indice].costo*desc5;
									arti[indice].costo=arti[indice].costo-arti[indice].descuento;
								}else{
									arti[indice].descuento=arti[indice].costo*desc6;
									arti[indice].costo=arti[indice].costo-arti[indice].descuento;
								}
							}
							if(band==0){
								if(band1==0){
									printf("CODIGO NO ENCONTRADO\n");	
								}
								
							}
							band=0;
							band1=0;
							indice++;
							}else{
								printf("PEDIDO LLENO\n");
							}
					}
					else if(resp=='n' or resp=='N'){
						printf("Adios\n");
					}
					else{
						printf("Respuesta invalida \n");
					}
				}while(resp!='n' and resp!='N');
				system("pause");
				
			break;
			case 3:
				
				system("cls");
				printf("\tARTICULOS ENLISTADOS\n\n");
				renglon=0;
					for(x=0;x<indice;x++){
						if(arti[x].codigo!=-1){
						gotoxy(0,2+renglon);printf("%d \t",arti[x].codigo);	
						gotoxy(12,2+renglon);printf("	%s \t",arti[x].desc);	
						gotoxy(26,2+renglon);printf("		%.2f \t",arti[x].precio);
						gotoxy(42,2+renglon);printf("		%d \t\n",arti[x].cant);			
						renglon++;
						}
					}	
				system("pause");
		   	
			break;
			case 4:
				system("cls");
				
				printf("Deseas cancelar un articulo?(s/n): ");
				fflush(stdin);
				scanf("%c",&resp);
				if(resp=='s' or resp=='S'){
					printf("Ingresa el codigo del articulo: ");
					scanf("%d",&codigobusc);
					for(x=0;x<10;x++){
						if(codigobusc==arti[x].codigo){
							band=1;
							indenc=x;
						}
					}	
					if(band==1){
						arti[indenc].codigo=-1;
						printf("Articulo Eliminado\n");
					}
					if(band==0){
						printf("Articulo no encontrado\n");
					}
						
				}else if(resp=='n' or resp=='N'){
					printf("Adios\n");
				}else{
					printf("Respuesta Invalida\n");
				}
				
				system("pause");
				
			break;
			case 5:
				system("cls");
				renglon=0;
				for(x=0;x<indice;x++){
					num[x]=x;
					tempu[x]=arti[x].cant;
				}
				for(y=0;y<(indice-1);y++){
					for(x=0;x<(indice-1);x++){
							if(tempu[x]>tempu[x+1]){
							temp=tempu[x];
							tempu[x]=tempu[x+1];
							tempu[x+1]=temp;
							
							temp=num[x];
							num[x]=num[x+1];
							num[x+1]=temp;
						}
						
					}
				}
				printf("\tARTICULOS ORDENADOS\n\n");
				
					for(x=0;x<indice;x++){
						if(arti[x].codigo!=-1){
						gotoxy(0,2+renglon);printf("%d \t",arti[num[x]].codigo);	
						gotoxy(12,2+renglon);printf("	%s \t",arti[num[x]].desc);	
						gotoxy(26,2+renglon);printf("		%.2f \t",arti[num[x]].precio);
						gotoxy(42,2+renglon);printf("		%d \t\n",arti[num[x]].cant);			
						renglon++;
						}
					}	
				system("pause");
				
			break;
			case 6:
				comprobante=fopen(nom,"w");
			    system("cls");
			    descuento=0;
			    total=0;
				renglon=0;
				if(cliente[c].num!=-1){
					gotoxy(89,0);printf("NO.Factura: %d",cliente[c].num);
					fprintf(comprobante,"NO.Factura: %d\n",cliente[c].num);
					gotoxy(10,1);printf("FACTURA PROYECTO FINAL");
					fprintf(comprobante,"\tFACTURA PROYECTO FINAL\n");
					gotoxy(89,2);printf("Fecha: %d/%d/2019",dia,mes);
					fprintf(comprobante,"\t\t\t\t\t\tFecha: %d/%d/2019\n",dia,mes);
					gotoxy(89,4);printf("Hora: %d",hora);
					fprintf(comprobante,"\t\t\t\t\t\tHora: %d\n",hora);
					gotoxy(5,5);printf("Cliente: %s",cliente[c].nom);
					fprintf(comprobante,"Cliente: %s\n",cliente[c].nom);
					gotoxy(5,6);printf("Domicilio: %s %d, %s",cliente[c].calle,cliente[c].numdecasa,cliente[c].ciudad);
					fprintf(comprobante,"\t\t\t\t\tDomicilio: %s %d, %s\n",cliente[c].calle,cliente[c].numdecasa,cliente[c].ciudad);
					gotoxy(89,6);printf("C.P: %d",cliente[c].cp);
					fprintf(comprobante,"\t\t\t\t\tC.P: %d\n",cliente[c].cp);
					gotoxy(5,7);printf("Telefono: %lli",cliente[c].numcliente);
					fprintf(comprobante,"\t\t\t\t\tTelefono: %lli\n",cliente[c].numcliente);
				}else{
					gotoxy(50,5);printf("Favor de Llenar los Datos del Cliente");
				}
			
				
				gotoxy(0,9);printf("Codigo \t 	Descripcion\t 	Precio\t 	Cantidad\t Descuento\t Total-Importe\n");fprintf(comprobante,"Codigo \t 	Descripcion\t 	Precio\t 	Cantidad\t Descuento\t Total-Importe\n");
					for(x=0;x<indice;x++){
						if(arti[x].codigo!=-1){
						total+=arti[x].costo;
						gotoxy(2,10+renglon);printf("%d",arti[x].codigo);
						fprintf(comprobante,"%d\t",arti[x].codigo);
						gotoxy(16,10+renglon);printf("%s",arti[x].desc);
						fprintf(comprobante,"\t%s\t\t",arti[x].desc);
						gotoxy(40,10+renglon);printf("$%.2f",arti[x].precio);
						fprintf(comprobante,"$%.2f\t\t",arti[x].precio);
						gotoxy(56,10+renglon);printf("%d",arti[x].cant);
						fprintf(comprobante,"%d\t\t",arti[x].cant );
						gotoxy(73,10+renglon);printf("%.2f",arti[x].descuento);
						fprintf(comprobante,"%.2f\t",arti[x].descuento);
						gotoxy(89,10+renglon);printf("%.2f\n",arti[x].costo);
						fprintf(comprobante,"\t\t%.2f\n",arti[x].costo);
						renglon++;
						}
					}	
					gotoxy(89,10+renglon);printf("Total: $%.2f",total);
					if(total>1000){
						descuento=.1;
					}
					gotoxy(89,13+renglon);printf("Descuento: %.2f",total*descuento);
									   	fprintf(comprobante,"Descuento: %.2f\n",total*descuento);
									   	total=total-descuento;
					gotoxy(89,14+renglon);printf("Subtotal: %.2f",total);
										 fprintf(comprobante,"Subtotal: %.2f\n",total);
					gotoxy(89,15+renglon);printf("I.V.A: %.2f",total*.16);
										 fprintf(comprobante,"I.V.A: %.2f\n",total*.16);
										 total=total*IVA;
					gotoxy(89,16+renglon);printf("Total: %.2f",total);
									    	fprintf(comprobante,"Total: %.2f\n",total);
					
					gotoxy(89, 20+renglon);printf("Pago en Efectivo: ");
									    	fprintf(comprobante,"Pago en Efectivo: ");
					gotoxy(106, 20+renglon);scanf("%f",&pago);
						  				 	fprintf(comprobante,"%.2f\n",pago);
					gotoxy(89, 21+renglon);printf("Cambio: %.2f\n",pago-total);
										   fprintf(comprobante,"Cambio: %.2f\n",pago-total);
					fclose(comprobante);
				system("pause");
			 
			break;
			case 7:
				system("cls");
				printf("Seguro que quiere realizar una nueva factura?(Todos los datos de la factura anterior se borraran)\n");
				printf(" S/N : ");
				fflush(stdin);
				scanf("%c",&resp);
				if(resp=='S' or resp=='s'){
					for(x=0;x<indice;x++){
					arti[x].codigo=-1;	
					}
					indice=0;
					c++;
					printf("Nueva Factura Creada Con Exito\n");
				}else{
					printf("Adios.\n");
				}
				system("pause");				
				break;
			case 8:
			    system("cls");	
				printf("ADIOS\n");
				system("pause");
			break;
			default: 
				system("cls");
				printf("OPCION INVALIDA\n");
			break;
		}
	}while(opc!=8);	
	fclose(comprobante);
	return 0;
}
