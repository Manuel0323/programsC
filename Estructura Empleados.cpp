#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct EMPLEADO{
	int num;
	float sueldo;
	char nom[30];
};

int main(){
	EMPLEADO emp[5];
	int x;
	
	for(x=0;x<5;x++){
		printf("Dame el nombre: ");
		fflush(stdin);
		gets(emp[x].nom);
		printf("Dame el sueldo: ");
		scanf("%f",&emp[x].sueldo);
		printf("Dame el numero de empleado: ");
		scanf("%d",&emp[x].num);
		system("cls");
	}
	for(x=0;x<5;x++){
		printf("Empleado: %d\n",emp[x].num);
		printf("Nombre: %s\n",emp[x].nom);
		printf("Sueldo: %.2f\n\n",emp[x].sueldo);
	}
	return 0;	
}
