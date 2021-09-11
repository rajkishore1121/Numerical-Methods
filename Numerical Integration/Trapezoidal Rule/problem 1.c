#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>

float I;

float function_evaluation(float x)       // Declaring the function for which integration is to be calculated
{
	float fn= pow(x,3)+1;
	
	return fn;
	
}
float analytical_solution(float x)        // declaring function for calculation of exact solution
{
	float as = ((pow(x,4))/4)+x;
	
	return as;
}

float trapezoidal(float x0, float x1)   
{
	float delx= (x1-x0);             // Solving using trapezoidal rule
	I =  (delx/2)*(function_evaluation(x0)+function_evaluation(x1));
	
	return I;
}
float error(float x0, float x1)   // Error calculation
{
	float exact= analytical_solution(x1)-analytical_solution(x0);
  float el= fabs(exact-I);

  return el;
	
}
float NI(float x0, float x1)           
{    
	
	float I1=trapezoidal(x0,x1);      // calling trapezoidal function
	float er=error(x0,x1);
	float ex= analytical_solution(x1)-analytical_solution(x0);

	printf("(%0.2f,%0.2f)\t%5.8f\t%5.8f\t%5.8f\n",x0,x1,ex,I1,er);   // printing the solution
}

int main()
{
	printf("Numerical integration using Trapezoidal rule:\n");
	printf("\n Interval\tExact(I)\tTrapezoidal(I)\tError\n\n");
	NI(1,2);
	NI(1,1.5);

	return 0;
}
