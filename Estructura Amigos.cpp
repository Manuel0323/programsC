#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define TAM 5
struct AMIGOS{
	char nombre[30];
	int edad;
	char direccion[40];
};
int main (){
	int num[TAM],x,temp,y,tempedad[TAM];
	AMIGOS a[TAM];
	for(x=0;x<TAM;x++){
		printf("AMIGO %d\n\n",x+1);
		printf("Nombre: ");
		fflush(stdin);
		gets(a[x].nombre);
		printf("Edad: ");
		scanf("%d",&a[x].edad);
		printf("Direccion (Calle y Numero): ");
		fflush(stdin);
		gets(a[x].direccion);
		num[x]=x;
		tempedad[x]=a[x].edad;
		system("cls");
	}
	
	for(x=0;x<TAM-1;x++){
		for(y=0;y<TAM-1;y++){
			if(tempedad[y]<tempedad[y+1]){
				temp=tempedad[y];
				tempedad[y]=tempedad[y+1];
				tempedad[y+1]=temp;
				temp=num[y];
				num[y]=num[y+1];
				num[y+1]=temp;
			}		
		}
	}
	for(x=0;x<TAM;x++){
		printf("AMIGO %d\n",num[x]+1);
		printf("Nombre: %s\n",a[num[x]].nombre);
		printf("Edad: %d\n",a[num[x]].edad);
		printf("Direccion (Calle y Numero): %s\n\n",a[num[x]].direccion);
		
	}
	
	return 0;
}
