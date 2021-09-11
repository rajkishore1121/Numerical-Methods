#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>

float function_evaluation(float x)         // Declaring the function for which integration is to be calculated
{
	float fn= pow(x,2)-(3*x)+7;
	
	return fn;
	
}
float analytical_solution(float x)       // declaring function for calculation of exact solution
{
	float as = ((pow(x,3))/3)-(3*(pow(x,2))/2)+(7*x);
	
	return as;
}
float gauss1D(int n)              // implementing Gauss integration method for numerical integration
{
	float wi[10],xi[10];
	if(n==2)                 // for 2 gauss points
	{                            
		wi[1]=1.00;
		wi[2]=1.00;
		xi[1]=-0.577350269;
		xi[2]=0.577350269;
				
	}
	else if(n==3)         // for 3 gauss points
	{
		wi[1]=0.8888888888;
		wi[2]=0.55555555556;
		wi[3]=0.55555555556;
		xi[1]=0.00000;
		xi[2]=-0.7745966692;
		xi[3]=0.77459666924;
		
		}	
	float I=0;
	int i;            
	for(i=1;i<=n;i++)
	{
		I+=(wi[i]*function_evaluation(xi[i]));
	}
	printf("\nValue of Integral using %d Gauss points: \nI=%5.10f\n",n,I);  // printing the solution
	float exact=(analytical_solution(1)-analytical_solution(-1));
	float error=fabs(exact-I);
	printf("Error=%5.6f\n",error);
}

int main()
{
	printf("Numerical integration using Gauss quadrature rule:\n");
	gauss1D(2);
	gauss1D(3);
	return 0;
}


