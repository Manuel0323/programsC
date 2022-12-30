 #include<stdio.h>
 #include<stdlib.h>
 #include<math.h>
 double funcion(double);
 void imprimirfuncion(void);
 int main (){
 	double b, a;
 	double suma=0,h,N,res,x0,xn,dato;
 	double i;
 	char resp;
 	
 	printf("\tINTEGRACION NUMERICA\n");
 	printf("(a=0,b=10) Funcion: ");
 	imprimirfuncion();
 	printf("Ingresa a: ");
 	scanf("%lf",&a);
	printf("Ingresa b: ");
 	scanf("%lf",&b);
	do{
	system("cls");
	printf("\tINTEGRACION NUMERICA\n");
 	printf("(a=%.2lf,b=%.2lf) Funcion: ",a,b);
 	imprimirfuncion();
	printf("Cual es el numero de Trapecios: ");
 	scanf("%lf",&N);
 	h=(b-a)/N;
	x0=funcion(a);
 	printf("x    |   y\n");
 	printf("%.2lf\t%.2lf\n",a,x0);
 	for(i=a+h;i<=b-h;i=i+h){
 		dato=funcion(i);
 		printf("%.2lf\t%.2lf\n",i,dato);
 			suma=suma+dato;
 		
	 }
	xn=funcion(b);
 	printf("%.2lf\t%.2lf\n",b,xn); 
	res=h/2*(x0+2*suma+xn);
 	printf("Resultado: %.2lf\n",res);
 	printf("Volver a intentar con diferente numero de trapecios?(S/N): ");
 	fflush(stdin);
 	scanf("%c",&resp);
 	system("cls");
 	suma=0;
	}while(resp=='s' or resp=='S');
	printf("Fin de Programa\n");
	return 0;
 }
 double funcion(double dato){
 	double valor;
 	valor=pow(dato,2)+2;
 	return valor;
 	
 }
 void imprimirfuncion(void){
 	 printf("(x^2+2)\n");
 }
