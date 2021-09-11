#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#define PI 3.14159

float I;

float function_evaluation1(float x)    // Declaring the function for which integration is to be calculated
{
	float fn1= pow(x,3)+1;
	
	return fn1;
	
}
float analytical_solution(float x)           // declaring function for calculation of exact solution
{
	float as = ((pow(x,4))/4)+x;
	
	return as;
}
float function_evaluation2(float x)       // Declaring the function for which integration is to be calculated
{
	float fn2= sqrt(sin(x));
	
	return fn2;
		
}
float simpson13(float x0, float x1)               // solving using simpson 1/3 rule
{
	float xmid=(x0+x1)/2;                     
	float delx=(x1-x0)/2;
	I= (delx/3)*(function_evaluation1(x0)+(4*function_evaluation1(xmid))+function_evaluation1(x1));
	printf("\nIntegral using Simpson 1/3 rule for interval (%.2f,%.2f) is %5.10f\n",x0,x1,I);
	
	return 0;
}
float simpson38(float x0, float x1)      // solving using simpson 2/3 rule
{
	float delx=(x1-x0)/3;
	float xm=x0+delx;
	float xn= x0+(2*delx);
I= (delx*3/8)*(function_evaluation1(x0)+(3*function_evaluation1(xm))+(3*function_evaluation1(xn))+function_evaluation1(x1));
	printf("\nIntegral using Simpson 3/8 rule for interval (%.2f,%.2f) is %5.10f\n",x0,x1,I);
	return 0;
}
float simpson13C(float x0, float x1, int n)              // solving using composite simpson 1/3 rule
{
		float delx= ((x1-x0)/n);
	float I =  (function_evaluation2(x0)+function_evaluation2(x1));
	int i;
	float xi;
	for(i=1; i<n;i++)
	{
	  xi= x0 + (i*delx);
		if(i%2==0)
		{
			I= I+(2*function_evaluation2(xi));
		}
		else if(i%2!=0)
		{
			I= I+(4*function_evaluation2(xi));
		}
			}
	
	I=(delx*I)/3;
	
	return I;
	
}
float error(float x0, float x1)            //    calculating absolute error
{
	float sol= analytical_solution(x1)-analytical_solution(x0);
  float el= fabs(sol-I);
  printf("\nError corresponding to interval (%.2f,%.2f) is %5.10f\n",x0,x1,el);
  return 0;
	
}
float NI( int n){
	
	float I1=simpson13C(0,PI,n);              // calling simpsons13C function
	       
	printf("\n %d\t%5.10f",n,I1);      // printing the solution
}

int main()
{
	simpson13(1,2);            // calling functions for solution for required interval
	error(1,2);
	simpson38(1,2);
	error(1,2);
	simpson13(1,1.5);
	error(1,1.5);
	simpson38(1,1.5);
	error(1,1.5);
	
	printf("\nSolution of Integral of sqrt(sinx) using Composite Simpson's 1/3 rule:\n");
    printf("\n N\tI\n");
    NI(5);           // calling NI function for printing the solution in table form
    NI(10);
    NI(15);
    NI(20);
    NI(25);
    NI(30);
    NI(35);
    NI(40);
    NI(45);
    NI(50);
    NI(55);
     printf("\n\nAs The number of interval increases, Composite Simpson's 1/3 solution converges to the exact solution.\n\n");
			
	return 0;
}
