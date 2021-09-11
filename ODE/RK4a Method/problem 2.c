#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>

#define e 2.718

#define x0 1.0             // defining all given input values from the given problem
#define u0 1.0
#define v0 1.0
#define L 5.0

 float uvalrk4[100];         // initialising all required Global variables for output
 float vvalrk4[100];
 float yx[100];
 float zx[100];
 float eul2;
 float evl2;
float function1 (float x, float y, float z)      //  defining the first function
{
	float f1= (2*x*z*z)/y;
	return f1 ;
}

float function2 (float x, float y, float z)  // defining the second function
{
	float f2= (y)/(z*z) ;
	return f2 ;
}
float analytical_solution1(float x)       // defining the analytical solution for the first function
{
	float g1= (x*x);
	
	return g1 ;
}
 float analytical_solution2(float x)    // defining the analytical solution for the second function
{
	float g2= x;
	
	return g2 ;
}
float RK4(int n)            // defining the RK4 method and writing detailed algorithm of RK4 method
{
	float h= (L-x0)/n;
	
	uvalrk4[0]=u0;      // initialising all the required variables
	vvalrk4[0]=v0;
	
	float esumu =0;
	float esumv =0;
	float un=u0,vn=v0, xn=x0;
	int i;
	for(i=1; i<=n;i++)
	{
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
		 uvalrk4[i]=un1;
		 vvalrk4[i]=vn1;
		esumu=esumu+pow(un1-analytical_solution1(xn+h),2);
		esumv=esumv+pow(vn1-analytical_solution2(xn+h),2);
			xn+=h;
			un=un1;
			vn=vn1;
		
	}
		eul2= sqrt(esumu)/n;             // storing the final error norms
       evl2= sqrt(esumv)/n;
	return 0 ;         
}


float analytical_1(int n)         // defining analytical function for calculating Y(x)
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

float analytical_2(int n)   // defining analytical function for calculating Z(x)
{
	
	float h= (L-x0)/n;
	float xn=x0;
	int i;
	for(i=0;i<=n;i++)
	{
		zx[i]= analytical_solution2(xn);
		xn+=h;
	}
	return 0;
}
int SODE(int N)         // defining function SODE and calling the RK4 methods 
{
	FILE *fp1= fopen("output1_problem2.txt","a");          // opening the first output file in append mode
	printf("Values of Yn and Zn for RK4 method for N=%d\n\n",N);
	fprintf(fp1,"Values of Yn and Zn for RK4 method for N=%d\n\n",N);
	 
	 RK4(N);
	 analytical_1(N);
	analytical_2(N);
	                                 // printing the solution in the output file
	printf("X\t\tAnalytical,Y(x)\t  Yn (RK4)\tAnalytical,Z(x)\t  Zn (RK4)\n\n");
	fprintf(fp1,"X\t\tAnalytical,Y(x)\t  Yn (RK4)\tAnalytical,Z(x)\t  Zn (RK4)\n\n");
	float h= (L-x0)/N;
	float xn=x0;
	int i;
	for(i=0;i<=N;i++)
	{
		printf("%f\t%10.5f\t%10.5f\t%10.5f\t%10.5f\n",xn,yx[i],uvalrk4[i],zx[i],vvalrk4[i]);
				fprintf(fp1,"%f\t%10.5f\t%10.5f\t%10.5f\t%10.5f\n",xn,yx[i],uvalrk4[i],zx[i],vvalrk4[i]);

		xn+=h;
	}
printf("\n\n");
fprintf(fp1,"\n\n");
	fclose(fp1);
	return 0;
}

float enorm(int N)             // defining the enorm function
{
	FILE *fp2= fopen("output2_problem2.txt","a"); // opening the second output file in append mode
 if(N==0)              
       {
	fprintf(fp2,"\n\n\n\n\n\n\n\n");
     }
		else if(N!=0)
		{
			RK4(N);		                    // printing the enorm values in the output file
	printf("%d\t%10.18f\t%10.18f\n",N,eul2,evl2);
	fprintf(fp2,"\n%d\t%10.18f\t%10.18f\n",N,eul2,evl2);
}
	fclose(fp2);          // closing the output file
	
	
		return 0;
	}
	
int main()

            {
			   	FILE *fp1= fopen("output1_problem2.txt","w");  // opening the first output file in writing mode
        	
        	SODE(5);                                     // calling the SODE function for different values of N
	       SODE(10);
	        SODE(20);
	        fclose(fp1);
	        FILE *fp2= fopen("output2_problem2.txt","w");  // opening the second output file in writing mode
	        printf("Error norms for RK4 method:\n");
	        printf("\nN\t\teyL2\t\t  eZL2\n\n");
	        fprintf(fp2,"N\teyL2\t\t\t\teZL2");
	        enorm(0);                           // calling the enorm function for different values of N
	        enorm(2);
	        enorm(5);
	        enorm(10);
	        enorm(15);
	        enorm(20);
	        enorm(25);
	        
            fclose(fp2);        // closing the second output file
        		
        		return 0;

}
	



