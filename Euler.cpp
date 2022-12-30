#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
	double x,y=2,h=.1,Fxy;
	
	printf("x\t y\t F(x,y)\n");
	for(x=0;x<1;x+=h){
		printf("%.1lf\t",x);
		printf("%.3lf\t",y);
		Fxy=x-y+2;
		printf("%.3lf\n",Fxy);
		y=Fxy*h+y;
	}
	
	
	
	
	
	return 0;
}
