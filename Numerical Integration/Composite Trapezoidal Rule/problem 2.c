#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>

float I, x0=0,x1=10;

float function_evaluation(float x)    // Declaring the function for which integration is to be calculated
{
	float fn= 1-exp((-x)/2);
	
	return fn;
		
}
float analytical_solution(float x)    // declaring function for calculation of exact solution
{
	float as = x+(2*exp((-x)/2));
	
	return as;
}
float trapezoidalC(float delx)
{
	float n=(x1-x0)/delx;                 // Solving using trapezoidal rule
	I =  (function_evaluation(x0)+function_evaluation(x1));
	int i;
	for(i=1; i<n;i++)
	{
		float xi= x0 + (i*delx);
		I= I+(2*function_evaluation(xi));
		
	}
	
	I=(delx*I)/2;
	
	return I;
}
float error()
{                                                                // Error calculation
	float sol= analytical_solution(x1)-analytical_solution(x0);
  float el= fabs(sol-I);

  return el;
	
}
float NI( float dx){
	
	float I1=trapezoidalC(dx);              // calling trapezoidal function
	float er=error();
	float ex= analytical_solution(x1)-analytical_solution(x0);             // printing the solution

	printf(" %f\t%5.8f\t%5.8f\t%5.10f\n",dx,ex,I1,er);
}

int main()
{
	printf("Numerical integration using Composite Trapezoidal rule:\n");
		printf("\n Del(X)\t\tExact(I)\tTrapezoidalC(I)\tError\n\n");
        NI(5);            // calling the NI function for different values of n
	    NI(4);
	    NI(2);
	    NI(1);
	    NI(0.5);
	    NI(0.4);
        NI(0.2);
        NI(0.1);
        NI(0.08);
        NI(0.05);
        NI(0.01);
          printf("\nAs The Del(X) value decreases, trapezoidal solution converges to the exact solution.\n\n");
	return 0;
}
