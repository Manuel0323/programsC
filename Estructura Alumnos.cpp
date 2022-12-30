#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct ALUMNO{
	int mat;
	char nom[30];
	float calif[6]={-1,-1,-1,-1,-1,-1};
};

int main(){
	ALUMNO a[10];
	int x,indice=0,opc,indenc,matbusc,i;
	char op;
	float suma=0;
	do{
		system("cls");
		printf("Menu:\n");
		printf("1.Alta de Alumno\n");
		printf("2.Captura de Calificaciones\n");
		printf("3.Promedios\n");
		printf("4.Tabla\n");
		printf("5.Salir\n");
		printf("Elije una opcion: ");
		scanf("%d",&opc);
		switch(opc){
			case 1:
				system("cls");
				printf("Dame el nombre del alumno: ");
				fflush(stdin);
				gets(a[indice].nom);
				printf("Ingrese la matricula: ");
				scanf("%d",&a[indice].mat);
				indice++;
				system("pause");
				break;
			case 2:
				system("cls");
				printf("Ingrese la matricula que desea encontrar: ");
				scanf("%d",&matbusc);
				for(x=0;x<indice;x++){
					if(matbusc==a[x].mat){
						indenc=x;
					}
				}
				if(indenc!=-1){
					printf("Seguro que quiere capturar calificaciones de: %s?(s/n)\n",a[indenc].nom);	
					fflush(stdin);
					scanf("%c",&op);
					if(op=='s'||op=='S'){
						for(x=0;x<5;x++){
						printf("Ingresa la calificacion:\n");
							scanf("%f",&a[indenc].calif[x]);
						}
					}	
				}else{
					printf("Alumno no se encuentra en el sistema.\n");
				}
				indenc=-1;
				system("pause");
				break;
			case 3:
				system("cls");
				for(x=0;x<indice;x++){
					if(a[x].calif[0]!=-1){
						suma=0;
						for(i=0;i<5;i++){
							suma=suma+a[x].calif[i];
						}
						a[x].calif[5]=suma/5;
					}
				}
				printf("Promedios Calculados.\n");
				system("pause");
				break;
			case 4:
				system("cls");
				
				for(x=0;x<indice;x++){
					printf("%d\t%s\t",a[x].mat,a[x].nom);
					if(a[x].calif[0]!=-1){
						for(i=0;i<5;i++){
							printf("C%d:%.2f ",i+1,a[x].calif[i]);
						}
					}
					if(a[x].calif[5]!=-1){
						printf("Prom:%.2f ",a[x].calif[5]);
					}
					printf("\n");
				}
				system("pause");
				break;
			case 5:
				break;				
		}
	}while(opc!=5);
	return 0;	
}
