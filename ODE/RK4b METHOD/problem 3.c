#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>

#define pi 3.1416

#define x0 0.0       // defining all given input values from the given problem
#define y0 4.0
#define u0 (-3.1416)
#define L 3.1416

float yvalrk4[100];            // initialising all required Global variables for output
 float uvalrk4[100];
 float yx[100];
 float ux[100];
 float eyl2;
 float eul2;

float function1 (float x, float y,float u)          //  defining the first function for Y'
{
	float f1= u;
	return f1 ;
}

float function2 (float x, float y,float u)       //  defining the second function for Y''
{
	float f2= (6*cos(x))+2-y ;
	return f2 ;
}

float analytical_solution1(float x)              // defining the analytical solution for Y'
{
	float g1= (2*cos(x))-(pi*sin(x))+(3*x*sin(x))+2;
	
	return g1 ;
}
 float analytical_solution2(float x)             // defining the analytical solution for Y''
{
	float g2= (sin(x))-(pi*cos(x))+(3*x*cos(x));
	
	return g2 ;
}

float RK4(int n)        // defining the RK4 method and writing detailed algorithm of RK4 method
{
	float h= (L-x0)/n;
	
	yvalrk4[0]=y0;     // initialising all the required variables
	uvalrk4[0]=u0;
	
	float esumu =0;
	float esumv =0;
	float un=y0,vn=u0, xn=x0;
	int i;
	for(i=1; i<=n;i++)
	{                                  // calling all the function and calculating required values
		float k1= h*function1(xn,un,vn);
		float l1= h*function2(xn,un,vn);
		float k2= h*function1(xn+(h/2),un+(k1/2),vn+(l1/2));
		float l2= h*function2(xn+(h/2),un+(k1/2),vn+(l1/2));
		float k3= h*function1(xn+(h/2),un+(k2/2),vn+(l2/2));
		float l3= h*function2(xn+(h/2),un+(k2/2),vn+(l2/2));
		float k4= h*function1(xn+h,un+k3,vn+l3);
		float l4= h*function2(xn+h,un+k3,vn+l3);
		float un1= un+((k1+(2*k2)+(2*k3)+k4)/6);
		float vn1= vn+((l1+(2*l2)+(2*l3)+l4)/6);
		 yvalrk4[i]=un1;
		 uvalrk4[i]=vn1;
		esumu=esumu+pow(un1-analytical_solution1(xn+h),2);
		esumv=esumv+pow(vn1-analytical_solution2(xn+h),2);
			xn+=h;
			un=un1;
			vn=vn1;
		
	}
		eyl2= sqrt(esumu)/n;    // storing the final error norms
       eul2= sqrt(esumv)/n;
	return 0 ;
}
float analytical_1(int n)       // defining analytical function for calculating Y(x)
{
	
	float h= (L-x0)/n;
	float xn=x0;
	int i;
	for(i=0;i<=n;i++)
	{
		yx[i]= analytical_solution1(xn);    
		xn+=h;
	}
	return 0;
}

float analytical_2(int n)    // defining analytical function for calculating Y'(x)
{
	
	float h= (L-x0)/n;
	float xn=x0;
	int i;
	for(i=0;i<=n;i++)
	{
		ux[i]= analytical_solution2(xn);
		xn+=h;
	}
	return 0;
}

int SODE(int N)               // defining function SODE and calling the RK4 methods 
{
	FILE *fp1= fopen("output1_problem3.txt","a");       // opening the first output file in append mode
	printf("Values of Yn and Y'n for RK4 method for N=%d\n\n",N);
	fprintf(fp1,"Values of Yn and Y'n for RK4 method for N=%d\n\n",N);
	 
	 RK4(N);
	 analytical_1(N);
	analytical_2(N);
	                                 // printing the solution in the first output file
	printf("X\t\tAnalytical,Y(x)\t  Yn (RK4)\tAnalytical,Y'(x)\tY'n (RK4)\n\n");
	fprintf(fp1,"X\t\tAnalytical,Y(x)\t  Yn (RK4)\tAnalytical,Y'(x)\t  Y'n (RK4)\n\n");
	float h= (L-x0)/N;
	float xn=x0;
	int i;
	for(i=0;i<=N;i++)
	{
		printf("%f\t%10.8f\t%10.8f\t%10.8f\t\t%10.8f\n",xn,yx[i],yvalrk4[i],ux[i],uvalrk4[i]);
	fprintf(fp1,"%f\t%10.8f\t%10.8f\t%10.8f\t\t%10.8f\n",xn,yx[i],yvalrk4[i],ux[i],uvalrk4[i]);

		xn+=h;
	}
printf("\n\n");
fprintf(fp1,"\n\n");
	fclose(fp1);         // closing the first output file
	return 0;
}

float enorm(int N)        // defining the enorm function
{
	FILE *fp2= fopen("output2_problem3.txt","a");   // opening the second output file in append mode
      if(N==0)
       {
	fprintf(fp2,"\n\n\n\n\n\n\n\n");
     }
		else if(N!=0)
		{
				RK4(N);		              // printing the enorm values in the output file
	printf("%d\t%10.18f\t%10.18f\n",N,eyl2,eul2);
	fprintf(fp2,"\n%d\t%10.18f\t%10.18f\n",N,eyl2,eul2);
}


	fclose(fp2);      // closing the output file
			return 0;
	}
	
int main()

            {                          // opening the first output file in writing mode
			   	FILE *fp1= fopen("output1_problem3.txt","w");
        	
        	SODE(5);                                   // calling the SODE function for different values of N
	       SODE(10);
	        SODE(20);
	        fclose(fp1);
	        FILE *fp2= fopen("output2_problem3.txt","w");  // opening the second output file in writing mode
	        printf("Error norms from RK4 method:\n");

	        printf("\nN\t\teyL2\t\t  ey'L2\n\n");
	        fprintf(fp2,"N\teyL2\t\t\t\tey'L2");
	        enorm(0);                                // calling the enorm function for different values of N
	        enorm(2);
	        enorm(5);
	        enorm(10);
	        enorm(15);
	        enorm(20);
	        enorm(25);
	        
            fclose(fp2);                      // closing the second output file
        		
        		return 0;

}
	










