#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct COMPRA{
	int ndc;
	char nom[30];
	float compras[10];
	int cindice=0;
};

int main(){
	int x,nbusc,indice=0,opc,indenc=-1,i,j,band=0;
	COMPRA c[20];
	char op;

	do{
		system("cls");
		printf("MENU\n");
		printf("1.Alta de Cliente\n");
		printf("2.Alta de Compra\n");
		printf("3.Mostrar Tabla\n");
		printf("4. Salir\n");
		printf("Dame la opcion: ");
		scanf("%d",&opc);
		
		switch(opc){
			case 1:
				system("cls");	
				printf("Ingresa el num. de cliente: ");
				scanf("%d",&c[indice].ndc);
				printf("Ingresa el nombre del cliente: ");
				fflush(stdin);
				gets(c[indice].nom);
				indice++;
				system("pause");
				break;
			case 2:
				system("cls");
				printf("Ingresa el num. del cliente que desea encontrar: ");
				scanf("%d",&nbusc);
				for(x=0;x<indice;x++){
					if(nbusc==c[x].ndc){
						indenc=x;
					}
				}
				if(indenc!=-1){
					printf("%s, Seguro?(s/n): ",c[indenc].nom);
					fflush(stdin);
					scanf("%c",&op);
					if(op=='s' or op=='S'){
						printf("Ingrese la Compra\n");
						if(c[indenc].cindice==10){
							for(i=0;i<9;i++){
								c[indenc].compras[i]=c[indenc].compras[i+1];
							}
							c[indenc].cindice--;
						}
						scanf("%f",&c[indenc].compras[c[indenc].cindice]);
						c[indenc].cindice++;
					}
				}else{
					printf("Cliente No Encontrado\n");
				}
				indenc=-1;
				system("pause");
				break;
			case 3:
				system("cls");
				for(i=0;i<indice;i++){
					printf("\n %d\t %s",c[i].ndc,c[i].nom);
					for(j=0;j<c[i].cindice;j++){
						printf("\t %.2f",c[i].compras[j]);
					}
					printf("\n");
				}
				system("pause");	
				break;
			case 4:
				break;
		
		}
	}while(opc!=4);
	return 0;	
}
