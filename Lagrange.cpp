#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<unistd.h>

int main (){
	float ejex[10],ejey[10],res=1,x0,temp,resfinal=0;
	int n,x,indice,y;
	printf("Ingresa el tama%co de la tabla: ",164);
	scanf("%d",&n);
	printf("Cual x quiere conocer: ");
	scanf("%f",&x0);
	system("cls");
	for(x=0;x<n;x++){
		printf("Ingresa primero x y despues y.\n");
		printf("%d (_,_): ",x+1);
		scanf("%f",&ejex[x]);
		printf("%d (%.2f,_): ",x+1,ejex[x]);
		scanf("%f",&ejey[x]);
		printf("%d (%.2f,%.2f): ",x+1,ejex[x],ejey[x]);
		sleep(.5);
		system("cls");
	}
	printf("\t x | y\n");
	for(x=0;x<n;x++){
		printf("\t%.1f  %.1f\n",ejex[x],ejey[x]);
		
	}
	indice=1;
	for(x=0;x<n;x++){
		for(y=1;y<n;y++){
			res=res*((x0-ejex[y])/(ejex[0]-ejex[y]));
			
		}
		res=res*ejey[x];
		resfinal=resfinal+res;
		res=1;
		temp=ejex[0];
		ejex[0]=ejex[indice];
		ejex[indice]=temp;
		indice++;
	}
	printf("Resultado x=%.2f y= %.2f\n",x0,resfinal);
	
	
	
	return 0;

}
