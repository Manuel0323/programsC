#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main (){
	float ejex[3],ejey[3],res;
	int band=0;
	char opc;	
	do{
		system("cls");
		band=0;
		printf("Dentro de cual eje buscara el valor?(x o y)\n");
		fflush(stdin);
		scanf("%c",&opc);
		switch(opc){
			case 'x':
				printf("Dame el primer punto: \n");
				printf("P(x,_):");
				scanf("%f",&ejey[0]);
				printf("P(x,%.1f)\n",ejey[0]);
				printf("P1(_,_): ");
				scanf("%f",&ejex[0]);
				printf("P1(%.1f,_):",ejex[0]);
				scanf("%f",&ejey[1]);
				printf("P1(%.1f,%.1f)\n",ejex[0],ejey[1]);
				printf("P2(_,_): ");
				scanf("%f",&ejex[1]);
				printf("P1(%.1f,_):",ejex[1]);
				scanf("%f",&ejey[2]);
				system("cls");
				printf("P(x,%.1f)\n",ejey[0]);
				printf("P1(%.1f,%.1f)\n",ejex[0],ejey[1]);
				printf("P1(%.1f,%.1f)\n",ejex[1],ejey[2]);
				res=(ejey[0]-ejey[1])*(ejex[1]-ejex[0])/(ejey[2]-ejey[1])+ejex[0];
				printf("Resultado: P(%.1f,%.1f)\n",res,ejey[0]);				
				break;
			case 'y':
				printf("Dame el primer punto: \n");
				printf("P(_,y):");
				scanf("%f",&ejex[0]);
				printf("P(%.1f,y)\n",ejex[0]);
				printf("P1(_,_): ");
				scanf("%f",&ejex[1]);
				printf("P1(%.1f,_):",ejex[1]);
				scanf("%f",&ejey[0]);
				printf("P1(%.1f,%.1f)\n",ejex[1],ejey[0]);
				printf("P2(_,_): ");
				scanf("%f",&ejex[2]);
				printf("P1(%.1f,_):",ejex[2]);
				scanf("%f",&ejey[1]);
				system("cls");
				printf("P(%.1f,y)\n",ejex[0]);
				printf("P1(%.1f,%.1f)\n",ejex[1],ejey[0]);
				printf("P1(%.1f,%.1f)\n",ejex[2],ejey[1]);
				res=(ejex[0]-ejex[1])*(ejey[1]-ejey[0])/(ejex[2]-ejex[1])+ejey[0];
				printf("Resultado: P(%.1f,%.1f)\n",ejex[0],res);
				break;
			default:
				printf("OPCION INVALIDA\n");
				band=1;
				system("pause");
				break;
		}	
	}while(band!=0);
	return 0;
}
