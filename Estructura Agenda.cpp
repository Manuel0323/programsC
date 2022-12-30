#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define TAM 100
#define YEAR 2019
struct CONTACTOS{
	int num;
	char nombre[30];
	int dia;
	int mes;
	int year;
	int edad;
	long long int tel;
	char correo[50];
	int indenc=0;
};

int main (){
	int opc,temp,num[TAM],indice=0,i,opc2,x,numbusc,band=0,mes,mes1,dia;
	CONTACTOS c[TAM];
	char resp,busq[3];
	
	printf("\tIntroduce la Fecha de Hoy\n");
	do{
		printf("Dame el mes(1:Enero, 2:Febrero,...,12:Diciembre): ");
		scanf("%d",&mes1);
		if(mes1>12 or mes1<1){
			printf("MES INVALIDO\n");
		}	
	}while(mes1>12 or mes1<1);
	do{
		printf("Dame el dia: ");
		scanf("%d",&dia);	
		if(dia>31 or dia<1){
			printf("DIA INVALIDO\n");
		}
	}while(dia>31 or dia<1);
	

	do{
		system("cls");
		printf("\tMENU\t\t %d/%d/%d\n",dia,mes1,YEAR);
		printf("1. Alta de Contacto\n");
		printf("2. Modificacion\n");
		printf("3. Cumplea%ceros del Mes\n",164);
		printf("4. Cumplea%ceros del Dia\n",164);
		printf("5. Edades \n");
		printf("6. Salir\n\n");
		printf("Ingresa una opcion: ");
		scanf("%d",&opc);
		
		switch(opc){
			case 1:
				if(indice<TAM){
					system("cls");
					printf("Seguro que desea dar de alta un contacto?(s/n)\n");
					fflush(stdin);
					scanf("%c",&resp);
					if(resp=='S'||resp=='s'){
						do{
							system("cls");
							band=0;
							printf("No. de Contacto: ");
							scanf("%d",&numbusc);
							for(x=0;x<indice;x++){
								if(numbusc==c[x].num){
									printf("Numero Ocupado.\n");
									band=1;								
								}
							}
							if(band!=1){
								c[indice].num=numbusc;
							}
						}while(band==1);
						
						
						printf("Nombre: ");
						fflush(stdin);
						gets(c[indice].nombre);
						
						do{
							printf("Dia de Nacimiento: ");
							scanf("%d",&c[indice].dia);
						}while(c[indice].dia>31 or c[indice].dia<1);
						
						do{
							printf("Mes de Nacimiento(1:Enero, 2:Febrero,...,12:Diciembre): ");
							scanf("%d",&c[indice].mes);
						}while(c[indice].mes>12 or c[indice].mes<1);			
						
						printf("A%co de Nacimiento: ",164);
						scanf("%d",&c[indice].year);
						
						printf("Telefono: ");
						scanf("%lli",&c[indice].tel);
						
						printf("Correo: ");
						fflush(stdin);
						gets(c[indice].correo);				
						
						indice++;
					}
				}else{
					printf("Ya no hay mas espacio.\n");
				}
					
				system("pause");	
				break;
			
			case 2:
				system("cls");
				band=0;
				printf("Ingresa las Primeras 3 Letras del Contacto que Desea Modificar:\n");
				fflush(stdin);
				gets(busq);
				
				for(i=0;i<indice;i++){
					for(x=0;x<3;x++){
						if(busq[x]==c[i].nombre[x]){
							c[i].indenc=c[i].indenc+1;
						}
					}
				}
				x=-1;
				for(i=0;i<indice;i++){
					if(c[i].indenc==3){
						printf("%d. %s\n",c[i].num,c[i].nombre);
						band=1;
					}
				}
				if(band==1){
					printf("Introduce el numero de contacto que desea modificar:\n");
					scanf("%d",&numbusc);
				}else{
					printf("No se encuentra ningun contacto.\n");
				}
				
				for(i=0;i<indice;i++){
					if(c[i].num==numbusc){
						printf("Seguro que desea modificar el contacto de: %s?(s/n)\n",c[i].nombre);
						fflush(stdin);
						scanf("%c",&resp);
						if(resp=='S'||resp=='s'){
							x=i;
						}
					}
				}
				if(x!=-1){
					do{
						system("cls");
						printf("1. Numero de Contacto: %d\n",c[x].num);
						printf("2. Nombre: %s\n",c[x].nombre);
						printf("3. Dia de Nacimiento: %d\n",c[x].dia);
						printf("4. Mes de Nacimiento: %d\n",c[x].mes);
						printf("5. A%co de Nacimiento: %d\n",164,c[x].year);
						printf("6. Telefono: %lli\n",c[x].tel);
						printf("7. Correo: %s\n",c[x].correo);
						printf("8. Salir\n");
						printf("Elija el dato que desea modificar: ");
						scanf("%d",&opc2);
						
						switch(opc2){
							case 1:
								system("cls");
								printf("1. Numero de Contacto: %d\n",c[x].num);
								do{
									band=0;
									printf("Nuevo: ");
									scanf("%d",&c[x].num);
									for(i=0;i<indice;i++){
										if(c[i].num==c[x].num and i!=x){
											band=1;
										}
									}
									if(band==1){
										printf("El numero %d ya existe en otro contacto.\n",c[x].num);
									}	
								}while(band==1);
								
								printf("Cambio Realizado.\n");
								system("pause");
								break;
							
							case 2:
								system("cls");
								printf("2. Nombre: %s\n",c[x].nombre);
								printf("Nuevo: ");
								fflush(stdin);
								gets(c[x].nombre);
								printf("Cambio Realizado.\n");
								
								system("pause");
								break;
								
							case 3:
								system("cls");
								printf("3. Dia de Nacimiento: %d\n",c[x].dia);
								printf("Nuevo: ");
								scanf("%d",&c[x].dia);
								printf("Cambio Realizado.\n");
								
								system("pause");
								break;
							case 4:
								system("cls");
								printf("4. Mes de Nacimiento: %d\n",c[x].mes);
								printf("Nuevo: ");
								scanf("%d",&c[x].mes);
								printf("Cambio Realizado.\n");
								system("pause");
								break;	
							case 5:
								system("cls");
								printf("5. A%co de Nacimiento: %d\n",164,c[x].year);
								printf("Nuevo: ");
								scanf("%d",&c[x].year);
								printf("Cambio Realizado.\n");
								system("pause");
								break;
								
							case 6:
								system("cls");
								printf("6. Telefono: %lli\n",c[x].tel);
								printf("Nuevo: ");
								scanf("%lli",&c[x].tel);
								printf("Cambio Realizado.\n");
								system("pause");

								break;
								
							case 7:
								system("cls");
								printf("7. Correo: %s\n",c[x].correo);
								printf("Nuevo: ");
								fflush(stdin);
								gets(c[x].correo);
								printf("Cambio Realizado.\n");
								system("pause");
								
								break;
							
							case 8:
								break;
							
							default:
								system("cls");
								printf("Opcion Invalida.\n");
								system("pause");
								break;
						}
					}while(opc2!=8);
				}
				for(i=0;i<indice;i++){
					c[i].indenc=0;	
				}
				
				system("pause");
				break;
			
			case 3:
				band=0;
				system("cls");
				do{
					printf("Dame el Mes(1:Enero,2:Febrero...): ");
					scanf("%d",&mes);	
					if(mes>12 or mes<1){
						printf("MES INVALIDO:");
						system("pause");
						system("cls");
					}
				}while(mes>12 or mes<1);
				system("cls");
				printf("\tCUMPLEA%cEROS MES: %d\n\n",165,mes);
				for(x=0;x<indice;x++){
					if(c[x].mes==mes){
						printf("Numero de Contacto: %d\n",c[x].num);
						printf("Nombre: %s\n",c[x].nombre);
						printf("Fecha de Nacimiento: %d/%d/%d\n",c[x].dia,c[x].mes,c[x].year);
						printf("Telefono: %lli\n",c[x].tel);
						printf("Correo: %s\n",c[x].correo);
						band=1;
					}
					printf("\n");
				}
				if(band!=1){
					printf("\tNo Hay Cumplea%ceros\n",164);
				}
				
				system("pause");
				break;
			case 4:
				band=0;
				system("cls");
				printf("\tCUMPLEA%cEROS DE HOY: %d/%d/%d\n\n",165,dia,mes1,YEAR);
				for(x=0;x<indice;x++){
					if(c[x].mes==mes1){
						if(c[x].dia==dia){
							printf("Numero de Contacto: %d\n",c[x].num);
							printf("Nombre: %s\n",c[x].nombre);
							printf("Fecha de Nacimiento: %d/%d/%d\n",c[x].dia,c[x].mes,c[x].year);
							printf("Telefono: %lli\n",c[x].tel);
							printf("Correo: %s\n",c[x].correo);
							band=1;	
						}
						
					}
					printf("\n");
				}
				if(band!=1){
					printf("\tNo Hay Cumplea%ceros el Dia de Hoy\n",164);
				}
				
				system("pause");
				break;
				
			case 5:
				system("cls");
				 for(x=0;x<indice;x++){
				 	if(mes1>c[x].mes){
				 		c[x].edad=YEAR-c[x].year;
				 	}else if(mes1==c[x].mes){
				 			if(dia>=c[x].dia){
				 				c[x].edad=YEAR-c[x].year;
							}else{
								c[x].edad=YEAR-c[x].year-1;
						 	}
					 }else{
					 	c[x].edad=YEAR-c[x].year-1;
					  } 	
				}
				 for(x=0;x<indice;x++){
				 	printf("%d. %s Edad: %d\n",c[x].num,c[x].nombre,c[x].edad);	
				 }
				 
				
				system("pause");
				break;
				
			case 6:
				system("cls");
				printf("Adios.\n");
				break;
				
			default:
				
				printf("Opcion Invalida.\n");
				
				break;
	 }
	}while(opc!=6);	
	return 0;
}
