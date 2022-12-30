#include<stdio.h>
#include<stdlib.h>
#include<math.h>
double funcion(double x,double y);
int main(){
	double x,y=5,h=.01,k1,k2,k3,k4,xi,yi;
	
	printf("x\t y\t k1\t x+h/2\t y+(k*h)/2\t k2\t y+(k2*h)/2\t k3\t x+h\t y+k3*h\t k4\n");
	for(x=0;x<.1;x+=h){
		xi=x;
		yi=y;
		k1=funcion(xi,yi);
		printf("%.2lf\t",x);
		printf("%.2lf\t",y);
		printf("%.2lf\t",k1);
		xi=x+(h/2);
		yi=y+(k1*h)/2;
		k2=funcion(xi,yi);
		printf("%.3lf\t",xi);
		printf(" %.2lf\t\t",yi);
		printf("%.2lf\t",k2);
		yi=y+(k2*h)/2;
		k3=funcion(xi,yi);
		
		printf(" %.2lf\t\t",yi);
		printf("%.2lf\t",k3);
		xi=x+h;
		yi=y+k3*h;
		k4=funcion(xi,yi);
		printf("%.2lf\t",xi);
		printf("%.2lf\t",yi);
		printf("%.2lf\n",k4);
		y=y+(h/6)*(k1+2*k2+2*k3+k4);
	}

	return 0;
}

double funcion(double x,double y){
	double resp;
	resp=-20*y+7*exp(-.5*x);
	return resp;
	
	
}
