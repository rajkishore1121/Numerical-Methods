#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>

float I, x0=-1,x1=1;

float function_evaluation(float x)       // Declaring the function for which integration is to be calculated
{
	float fn= exp(x);
	
	return fn;
		
}
float analytical_solution(float x)      // declaring function for calculation of exact solution
{
	float as = exp(x);
	
	return as;
}

float trapezoidalC(int n)
{
	float delx= ((x1-x0)/n);                    // Solving using trapezoidal rule
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
float error(int n)
{                                    // Error calculation
	float sol= analytical_solution(x1)-analytical_solution(x0);
  float el= fabs(sol-I);
 
  return el;
	
}
float NI( int n){
	
	float I1=trapezoidalC(n);              // calling trapezoidal function
	float er=error(n);                            
	float ex= analytical_solution(x1)-analytical_solution(x0);        // printing the solution

	printf(" %d\t%5.8f\t%5.8f\t%5.8f\n",n,ex,I1,er);
}

int main()
{
	printf("Numerical integration using Composite Trapezoidal rule:\n");
		printf("\n N\tExact(I)\tTrapezoidalC(I)\tError\n\n");
        NI(2);                // calling the NI function for different values of n
	    NI(4);
	    NI(6);
	    NI(8);
	    NI(10);
	    NI(15);
        NI(20);
          printf("\nAs The number of interval increases, trapezoidal solution converges to the exact solution.\n\n");
	return 0;
}
