#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>

#define e 2.718

#define x0 0.0                      // defining all given input values from the given problem
#define y0 1.0
#define L 5.0
 
 float yvale[100];                       // initialising all required Global variables for output
 float yvalm[100];
 float yvalrk2[100];
 float yvalrk4[100];
 float yx[100];
float function (float x, float y)         //  defining the function
{
	float f= y+(2*x)-pow(x,2);
	return f ;
}
float analytical_solution(float x)           // defining the analytical solution
{
	float g= pow(x,2)+pow(e,x);
	
	return g ;
}

float Euler(int n)                       // defining the Euler method and writing detailed algorithm of Euler method
{
		float h= (L-x0)/n;
	
	yvale[0]=y0;                         // initialising all the required variables
	float esum =0;    
		
	float yn=y0;
	float xn= x0;
	int i;
	for(i=1;i<=n; i++)
	{
		float yn1= yn+(h*function(xn,yn));
		yvale[i]=yn1;
			esum=esum+pow(yn1-analytical_solution(xn+h),2);
        xn+=h;
        yn=yn1;
		
	}
	float eLE2= sqrt(esum)/n;
	
	return eLE2 ;              // returning the final error norm
}

float Mid(int n)                      // defining the Mid point method and writing detailed algorithm of Mid point method
{
	float h= (L-x0)/n;
	
	yvalm[0]=y0;             // initialising all the required variables
	float esum =0;
	float y1= y0+(h*function(x0,y0));
	
	esum=esum+pow(y1-analytical_solution(x0+h),2);
	yvalm[1]=y1;
	float yn_1=y0, xn_1=x0;
	float yn=y1, xn= x0+h;
	int i;
	for(i=2;i<=n; i++)
	{
		float yn1= yn_1+2*(h*function(xn,yn));
		yvalm[i]=yn1;
			esum=esum+pow(yn1-analytical_solution(xn+h),2);
        xn+=h;
        yn_1=yn;
        yn=yn1;
		
	}
	float eLm2= sqrt(esum)/n;
	return eLm2 ;                             // returning the final error norm
}

float RK2(int n)                    // defining the RK2 method and writing detailed algorithm of RK2 method
{
		float h= (L-x0)/n;
	
	yvalrk2[0]=y0;                      // initialising all the required variables
	float esum =0;
	float yn=y0, xn=x0;
	int i;
	for(i=1; i<=n;i++)
	{
		float k1= h*function(xn,yn);
		float k2= h*function(xn+h,yn+k1);
		
		float yn1= yn+((k1+k2)/2);
		 yvalrk2[i]=yn1;
			esum=esum+pow(yn1-analytical_solution(xn+h),2);
			xn+=h;
			yn=yn1;
		
	}
		float eLrk2= sqrt(esum)/n;
	
	return eLrk2 ;                       // returning the final error norm
}
float RK4(int n)                          // defining the RK4 method and writing detailed algorithm of RK4 method
{
	float h= (L-x0)/n;
	
	yvalrk4[0]=y0;                           // initialising all the required variables
	float esum =0;
	float yn=y0, xn=x0;
	int i;
	for(i=1; i<=n;i++)
	{
		float k1= h*function(xn,yn);
		float k2= h*function(xn+(h/2),yn+(k1/2));
		float k3= h*function(xn+(h/2),yn+(k2/2));
		float k4= h*function(xn+h,yn+k3);
		float yn1= yn+((k1+(2*k2)+(2*k3)+k4)/6);
		 yvalrk4[i]=yn1;
			esum=esum+pow(yn1-analytical_solution(xn+h),2);
			xn+=h;
			yn=yn1;
		
	}
		float eLrk4= sqrt(esum)/n;

	return eLrk4 ;                             // returning the final error norm
}


float analytical(int n)              // defining analytical function for calculating Y(x)
{
	
	float h= (L-x0)/n;
	float xn=x0;
	int i;
	for(i=0;i<=n;i++)
	{
		yx[i]= analytical_solution(xn);
		xn+=h;
	}
	
	return 0;
}

int ODE(int N)                       // defining function ODE and calling all the methods 
{
		FILE *fp1= fopen("output1_problem1.txt","a");         // opening the first output file in append mode

	printf("Yval[N] for N=%d\n\n",N);
	fprintf(fp1,"Yval[N] for N=%d\n\n",N);
	float el5[4];
	analytical(N);
	el5[0]= Euler(N);
	el5[1]= Mid(N);
    el5[2]= RK2(N);
    el5[3]= RK4(N);
	
	                               // printing the solution in the first output file
	printf("\nX\t\tAnalytical,y(x)\t  Euler,Yn\tMidPoint,Yn\t  RK2,Yn\t RK4,Yn\n\n");
		fprintf(fp1,"\nX\t\tAnalytical,y(x)\t  Euler,Yn\tMidPoint,Yn\t  RK2,Yn\t RK4,Yn\n\n");
		float h= (L-x0)/N;
	float xn=x0;
	int i;
	for(i=0;i<=N;i++)
	{
		printf("%f\t%10.5f\t%10.5f\t%10.5f\t%10.5f\t%10.5f\n",xn,yx[i],yvale[i],yvalm[i],yvalrk2[i],yvalrk4[i]);
				fprintf(fp1,"%f\t%10.5f\t%10.5f\t%10.5f\t%10.5f\t%10.5f\n",xn,yx[i],yvale[i],yvalm[i],yvalrk2[i],yvalrk4[i]);

		xn+=h;
	}
printf("\n\n");
fprintf(fp1,"\n\n");
	fclose(fp1);
	return 0;
}
int enorm(int N)                          // defining the enorm function
{
FILE *fp2= fopen("output2_problem1.txt","a");              // opening the second output file in append mode

	analytical(N);
	float el2[4];
	el2[0]= Euler(N);
	el2[1]= Mid(N);
    el2[2]= RK2(N);
    el2[3]= RK4(N);
	if(N==0)             // printing the enorm values in the second output file
	fprintf(fp2,"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	else if(N!=0)
		{
		printf("%d\t%10.10f\t%10.10f\t%10.10f\t%10.10f\n",N,el2[0],el2[1],el2[2],el2[3]);
fprintf(fp2,"\n%d\t%10.10f\t%10.10f\t%10.10f\t%10.10f\n",N,el2[0],el2[1],el2[2],el2[3]);

}
	fclose(fp2);                 // closing the second output file
	return 0;
}
int main ()
{
	   	FILE *fp1= fopen("output1_problem1.txt","w");        // opening the first output file in writing mode
	   	

	ODE(5);                         // calling the ODE function for different values of N
	ODE(10);
	ODE(20);
		fclose(fp1);
		
		printf("eL2 error norms for different methods:\n");
	FILE *fp2= fopen("output2_problem1.txt","w");             // opening the second output file in writing mode
	printf("\nN\tEuler\t\t MidPoint\t RK2\t\t RK4\n\n");
		fprintf(fp2,"N\tEuler\t\t MidPoint\t RK2\t\t RK4");
		
		enorm(0);                    // calling the enorm function for different values of N
	    enorm(2);
	    enorm(5);
		enorm(10);
		enorm(15);
		enorm(20);
		enorm(25);

	fclose(fp2);                 // closing the second output file
	
	return 0;
}
