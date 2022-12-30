#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<unistd.h>

int main(){
	int n,x;
	float ejex[20],ejey[20],x2[20],xy[20],sumax=0,sumay=0,sumaxy=0,sumax2=0,m,b;
	printf("MINIMOS CUADRADOS\n");
	
	printf("De cuantas filas sera la tabla: ");
	scanf("%d",&n);
	system("cls");
	for(x=0;x<n;x++){
		printf("Ingresa primero x y despues y.\n");
		printf("%d (_,_): ",x+1);
		scanf("%f",&ejex[x]);
		printf("%d (%.2f,_): ",x+1,ejex[x]);
		scanf("%f",&ejey[x]);
		printf("%d (%.2f,%.2f): ",x+1,ejex[x],ejey[x]);
		sleep(.5);
		sumax=sumax+ejex[x];
		sumay=sumay+ejey[x];
		x2[x]=ejex[x]*ejex[x];
		xy[x]=ejex[x]*ejey[x];
		sumaxy=sumaxy+xy[x];
		sumax2=sumax2+x2[x];
		system("cls");
	}
	m=(n*sumaxy-sumax*sumay)/(n*sumax2-sumax*sumax);
	b=(sumay*sumax2-sumax*sumaxy)/(n*sumax2-sumax*sumax);
	printf("\t|x\t|y\t|x*y\t|x^2\n");
	for(x=0;x<n;x++){
		printf("%d\t%.2f\t%.2f\t%.2f\t%.2f\n",x+1,ejex[x],ejey[x],xy[x],x2[x]);
	}
	printf("m=%.2f  b=%.2f\n",m,b);
	
	return 0;
}
