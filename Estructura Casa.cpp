#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct CASA{
	int ventanas,puertas,ndc;
	char color[30],direccion[30];
};

int main(){
	CASA casa;
	
	printf("Numero de puertas: ");
	scanf("%d",&casa.puertas);
	printf("Numero de ventanas: ");
	scanf("%d",&casa.ventanas);
	printf("Color de casa: ");
	fflush(stdin);
	gets(casa.color);
	printf("Calle: ");
	fflush(stdin);
	gets(casa.direccion);
	printf("Numero de Casa: ");
	scanf("%d",&casa.ndc);
	
	printf("\nVentanas: %d\n",casa.ventanas);
	printf("Puertas: %d\n",casa.puertas);
	printf("Color: %s\n",casa.color);
	printf("Direccion: %s %d\n",casa.direccion,casa.ndc);
	
	return 0;
	
}
