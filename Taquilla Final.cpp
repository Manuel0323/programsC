#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<cctype>;
struct Funcion{
	char desc[30];
	float longitud;
	float precion;
	float precioa;
	float precioam;
	int sala;
	int indice=-1;
};
struct Boleto{
	int fila;
	char filac;
	int num;
	char desc[30];
	int sala;
	float precio;
};
struct Cliente{
	int indboleto;
	int cantidad;
	int sala;
	float total=0;
	float descuento;
	Boleto boleto[10];
};

int main(){
	int opc,opc2, indicep=0,salabusc,x,y,filac,z,indenc,f,c,cantidad;
	float cambio;
	int TAM=10, TAMC=100,band=0,TAMF=25,TAMCO=20;
	int sala[TAM][TAMF][TAMCO];
	int fila[TAM],col[TAM];
	char resp;
	Funcion pelicula[TAM];
	Cliente cliente;
	FILE *comprobante;
	char nom[]={"comprobante.txt"};
	comprobante=fopen(nom,"w");
	fclose(comprobante);
	for(x=0;x<TAM;x++){
		fila[x]=TAMF;
		col[x]=TAMCO;
	}
	for(z=0;z<TAM;z++){
		for(y=0;y<TAMF;y++){
			for(x=0;x<TAMCO;x++){
				sala[z][y][x]=-1;
			}
		}
	}
	do{
		system("cls");
		printf("\tMenu\n");
		printf("1-Mostrar Funciones\n");
		printf("2-Compra de Boletos\n");
		printf("3-Alta de Funcion\n");
		printf("4-Remplazar Funcion de Sala\n");
		printf("5-Modificar Salas\n");
		printf("6-Salir\n");	
		scanf("%d",&opc);
		switch(opc){
			case 1:
				system("cls");
				if(indicep==0){
					printf("No Hay Funciones Disponibles\n");
				}else{
					printf("\tFunciones\n");
						for(x=0;x<indicep;x++){
				    		printf("Funcion: %s Sala: %d Duracion: %.2f\n",pelicula[x].desc,pelicula[x].sala+1,pelicula[x].longitud);
				    	}
				}
				system("pause");
				break;
			case 2:
				system("cls");
				cliente.cantidad=0;
				cliente.indboleto=0;
				printf("\t\tCOMPRA DE BOLETOS\n\n");
				if(indicep==0){
					printf("No Hay Funciones Disponibles\n");
				}else{
					printf("\tFunciones\n");
						for(x=0;x<indicep;x++){
				    		printf("Funcion: %s Sala: %d Duracion: %.2f\n",pelicula[x].desc,pelicula[x].sala+1,pelicula[x].longitud);
				    	}
				
					printf("Ingresa la Sala Deseada(0 para salir): ");
					scanf("%d",&salabusc);
				if(salabusc!=0 and pelicula[salabusc].indice!=-1){
					salabusc=salabusc-1;
					do{
						system("cls");
						printf("\t COMPRA DE BOLETOS\n\n");
						filac=65;
						for(x=0;x<col[salabusc];x++){
							printf("\t%d",x+1);
						}
						printf("\n");
						for(y=0;y<fila[salabusc];y++){
							printf("%c\t ",filac);
							for(x=0;x<col[salabusc];x++){
								if(sala[salabusc][y][x]!=-1){
									printf("x\t");
								}else{
									printf("\t");
								}
							}
							printf("\n");
							filac++;
						}
					
						printf("Tipos de Boletos:\n");
						printf("1. Ni%co: %.2f\n",164,pelicula[salabusc].precion);
						printf("2. Adulto: %.2f\n",pelicula[salabusc].precioa);
						printf("3. Adulto Mayor: %.2f\n",pelicula[salabusc].precioam);
						printf("4. Salir\n");
						printf("Elige la clase del boleto: ");
						scanf("%d",&opc2);	
						switch(opc2){
							case 1:
								printf("\t Ni%co\n",164);
								printf("Ingresa la cantidad de boletos: ");
								scanf("%d",&cantidad);
								cliente.total+=cantidad*pelicula[salabusc].precion;
								cliente.cantidad+=cantidad;
								for(x=0;x<cantidad;x++){
									do{	
									printf("Asiento Ni%co %d: \n",164,x+1);
									printf("Fila: ");
									fflush(stdin);
									scanf("%c",&filac);
									filac=toupper(filac);
									f=(int)filac-65;
									printf("Asiento: ");
									scanf("%d",&c);
									c--;
										if(sala[salabusc][f][c]!=-1){
											printf("Asiento Ocupado.\n\n");
										}
									}while(sala[salabusc][f][c]!=-1);	
									cliente.boleto[cliente.indboleto].fila=f;
									cliente.boleto[cliente.indboleto].num=c+1;
									cliente.boleto[cliente.indboleto].precio=pelicula[salabusc].precion;
									cliente.indboleto++;
									sala[salabusc][f][c]=0;		
								}
								system("pause");
								system("cls");
								break;
								
							case 2:
								
								printf("\t Adulto\n");
								printf("Ingresa la cantidad de boletos: ");
								scanf("%d",&cantidad);
								cliente.total+=cantidad*pelicula[salabusc].precioa;
								cliente.cantidad+=cantidad;
								for(x=0;x<cantidad;x++){
									do{	
									printf("Asiento Adulto %d: \n",x+1);
									printf("Fila: ");
									fflush(stdin);
									scanf("%c",&filac);
									filac=toupper(filac);
									f=(int)filac-65;
									printf("Asiento: ");
									scanf("%d",&c);
									c--;
										if(sala[salabusc][f][c]!=-1){
											printf("Asiento Ocupado.\n\n");
										}
									}while(sala[salabusc][f][c]!=-1);	
									cliente.boleto[cliente.indboleto].fila=f;
									cliente.boleto[cliente.indboleto].num=c+1;
									cliente.boleto[cliente.indboleto].precio=pelicula[salabusc].precioa;
									cliente.indboleto++;
									sala[salabusc][f][c]=0;			
								}
								
								system("pause");
								system("cls");
								break;
								
							case 3:
								printf("\t Adulto mayor\n");
								printf("Ingresa la cantidad de boletos: ");
								scanf("%d",&cantidad);
								cliente.total+=cantidad*pelicula[salabusc].precioam;
								cliente.cantidad+=cantidad;
								for(x=0;x<cantidad;x++){
									do{	
									printf("Asiento Adulto Mayor %d: \n",x+1);
									printf("Fila: ");
									fflush(stdin);
									scanf("%c",&filac);
									filac=toupper(filac);
									f=(int)filac-65;
									printf("Asiento: ");
									scanf("%d",&c);
									c--;
									if(sala[salabusc][f][c]!=-1){	
										printf("Asiento Ocupado.\n\n");
									}
									}while(sala[salabusc][f][c]!=-1);	
									cliente.boleto[cliente.indboleto].fila=f;
									cliente.boleto[cliente.indboleto].num=c+1;
									cliente.boleto[cliente.indboleto].precio=pelicula[salabusc].precioam;
									cliente.indboleto++;
									sala[salabusc][f][c]=0;			
								}
								system("pause");
								system("cls");
								break;
								
							case 4:
								system("cls");
								printf("Adios\n");
								break;
								
							default:
								system("cls");
								printf("Opcion Invalida\n");
								system("pause");
								break;	
						}
					}while(opc2!=4);
				for(x=0;x<cliente.cantidad;x++){
					strcpy(cliente.boleto[x].desc,pelicula[salabusc].desc);
					cliente.boleto[x].filac=(char)cliente.boleto[x].fila;
					cliente.boleto[x].sala=salabusc+1;
				}
				printf("Total: $%.2f\n",cliente.total);
				printf("Efectivo: ");
				scanf("%f",&cambio);
				printf("Cambio: $%.2f\n",cambio-cliente.total);
				system("pause");
				system("cls");
				comprobante=fopen(nom,"w");
				for(x=0;x<cliente.cantidad;x++){
					printf("\t CINE LOPEZ\n\n");
					fprintf(comprobante,"\t CINE LOPEZ\n\n");
					printf("Sala: %d\n",cliente.boleto[x].sala);
					fprintf(comprobante,"Sala: %d\n",cliente.boleto[x].sala);
					printf("Funcion: %s\n",cliente.boleto[x].desc);
					fprintf(comprobante,"Funcion: %s\n",cliente.boleto[x].desc);
					if(cliente.boleto[x].precio==pelicula[salabusc].precioa){
						printf("Tipo de Boleto: Adulto \n");
						fprintf(comprobante,"Tipo de Boleto: Adulto \n");			
					}else if(cliente.boleto[x].precio==pelicula[salabusc].precioam){
						printf("Tipo de Boleto: Adulto Mayor \n");
						fprintf(comprobante,"Tipo de Boleto: Adulto Mayor \n");
					}else if(cliente.boleto[x].precio==pelicula[salabusc].precion){
						printf("Tipo de Boleto: Infantil \n");
						fprintf(comprobante,"Tipo de Boleto: Infantil \n");
					}
					printf("Precio: %.2f\n",cliente.boleto[x].precio);
					fprintf(comprobante,"Precio: %.2f\n",cliente.boleto[x].precio);
					printf("Asiento: %c,%d\n",cliente.boleto[x].fila+65,cliente.boleto[x].num);
					filac=(char)cliente.boleto[x].fila;
					fprintf(comprobante,"Asiento: %c,%d\n\n\n",filac,cliente.boleto[x].num);
					printf("\n\n");
					
				}
				fclose(comprobante);		
				}else{
					printf("Adios\n");
				}
				}
				system("pause");
				break;
			case 3:
				system("cls");
				printf("\t NUEVA FUNCION\n\n");
				indenc=-1;
				band=0;
				printf("Desea agregar una nueva funcion?(s/n)");
				fflush(stdin);
				scanf("%c",&resp);
				if(resp=='s' or resp=='S'){
					if(indicep<TAM){
						do{
						printf("Sala: ");
			    		scanf("%d",&salabusc);
			    		salabusc--;
			    			for(x=0;x<indicep;x++){
			    				if(salabusc==pelicula[x].sala){
			    					band=1;
			    				}
			    			}
					    }while(band!=0);
			    		pelicula[indicep].sala=salabusc;
					    printf("Nombre de pelicula: ");
					    fflush(stdin);
				    	gets(pelicula[indicep].desc);
				    	printf("Duracion de pelicula en horas: ");
				    	scanf("%f",&pelicula[indicep].longitud);
				    	printf("Precio del Boleto(Ni%co): ",164);
				    	scanf("%f",&pelicula[indicep].precion);
				    	printf("Precio del Boleto(Adulto): ");
				    	scanf("%f",&pelicula[indicep].precioa);
				    	printf("Precio del Boleto(Adulto Mayor): ");
				    	scanf("%f",&pelicula[indicep].precioam);
				    	indicep++;
						pelicula[indicep].indice=0;
					}else{
						system("cls");
						printf("\tFunciones\n");
						for(x=0;x<indicep;x++){
				    		printf("Funcion: %s Sala: %d \n",pelicula[x].desc,pelicula[x].sala+1);
				    	}
				    	printf("Desea remplazar la pelicula de una sala existente?(s/n)\n");
				    	fflush(stdin);
				    	scanf("%c",&resp);
				    	if(resp=='s' or resp=='S'){
				    		printf("Sala que desea reemplazar: ");
				    		scanf("%d",&salabusc);
				    		salabusc--;
				    		for(x=0;x<indicep;x++){
				    			if(pelicula[x].sala==salabusc){
				    				indenc=x;
								}
							}
							if(indenc!=-1){
								pelicula[indenc].sala=salabusc;
								printf("Nombre de pelicula: ");
							    fflush(stdin);
						    	gets(pelicula[indenc].desc);
						    	printf("Duracion de pelicula en minutos: ");
						    	scanf("%d",&pelicula[indenc].longitud);
						    	printf("Precio del Boleto(Ni%co): ",164);
						    	scanf("%f",&pelicula[indenc].precion);
						    	printf("Precio del Boleto(Adulto): ");
						    	scanf("%f",&pelicula[indenc].precioa);
						    	printf("Precio del Boleto(Adulto Mayor): ");
						    	scanf("%f",&pelicula[indenc].precioam);		
								for(y=0;y<TAMF;y++){
									for(x=0;x<TAMCO;x++){
									sala[indenc][y][x]=-1;
									}
								}
								
							}
				    		
				    	}else{
				    		printf("Adios\n");
				    	}
					}
				}else{
					printf("Adios.\n");
				}
				system("pause");
				break;				
			case 4:
				indenc=-1;
				system("cls");
				printf("\tFunciones\n");
				for(x=0;x<indicep;x++){
		    		printf("Funcion: %s Sala: %d \n",pelicula[x].desc,pelicula[x].sala+1);
		    	}
		    	printf("Desea remplazar la pelicula de una sala existente?(s/n)\n");
		    	fflush(stdin);
		    	scanf("%c",&resp);
		    	if(resp=='s' or resp=='S'){
		    		printf("Sala que desea reemplazar: ");
				    		scanf("%d",&salabusc);
				    		salabusc--;
				    		for(x=0;x<indicep;x++){
				    			if(pelicula[x].sala==salabusc){
				    				indenc=x;
								}
							}
							if(indenc!=-1){
								pelicula[indenc].sala=salabusc;
								printf("Nombre de pelicula: ");
							    fflush(stdin);
						    	gets(pelicula[indenc].desc);
						    	printf("Duracion de pelicula en minutos: ");
						    	scanf("%f",&pelicula[indenc].longitud);
						    	printf("Precio del Boleto(Ni%co): ",164);
						    	scanf("%f",&pelicula[indenc].precion);
						    	printf("Precio del Boleto(Adulto): ");
						    	scanf("%f",&pelicula[indenc].precioa);
						    	printf("Precio del Boleto(Adulto Mayor): ");
						    	scanf("%f",&pelicula[indenc].precioam);
								for(y=0;y<TAMF;y++){
									for(x=0;x<TAMCO;x++){
									sala[indenc][y][x]=-1;
									}
								}
								
							}
		    	}else{
		    		printf("Adios\n");
		    	}
				
				system("pause");
				break;	
			case 5:
				system("cls");
				printf("\t MODIFICACION DE SALAS\n\n");
				for(x=0;x<TAM;x++){
					printf("Sala: %d, Filas: %d, Columnas: %d\n",x+1,fila[x],col[x]);
				}
				printf("Ingresa la sala que desea modificar(0 para salir): ");
				scanf("%d",&salabusc);
				if(salabusc!=0){
				salabusc--;
				system("cls");
				printf("Sala: %d, Filas: %d, Asientos: %d\n\n",salabusc+1,fila[salabusc],col[salabusc]);
				printf("Ingresa cantidad de filas: ");
				scanf("%d",&fila[salabusc]);
				printf("Ingresa cantidad de asientos por fila: ");
				scanf("%d",&col[salabusc]);	
				}else{
					printf("Adios.\n");
				}
				system("pause");
				break;
			case 6:
				system("cls");
				printf("Adios\n");
				system("pause");
				break;				
			default:
				system("cls");			
				
			
				system("pause");
		    	break; 	
		}
	}while(opc!=6);
	return 0;
}
