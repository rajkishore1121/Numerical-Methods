#include<stdio.h>
#include<stdlib.h>
#include<math.h>
float x[3];
                             // setting number of independent variable in the system of equation

float function_1 ()
{
float f1;
f1 = pow(x[1],2) + pow(x[2],2) -1;        // setting first function for the equation of circle
return f1;
}


float function_2 ()
{
float f2;
f2 = pow(x[1],2) -x[2];                         // setting second function for the equation of parabola
return f2;
}

                                               // setting partial derivative of first fuction for jacobian matrix
float der1_x1 ()
{
float d11;
d11 = 2*x[1];
return d11;
}


float der1_x2 ()
{
float d12;
d12 = 2*x[2];
return d12;
}

                                                 // setting partial derivative of second function for jacobian matrix
float der2_x1 ()
{
float d21;
d21 = 2*x[1];
return d21;
}


float der2_x2 ()
{
float d22;
d22 = -1;
return d22;
}

int main()
{

float F[10],J[10][10],det_J,I[10][10],y[3],error[3],max,tolerance;          // initialing the required variable
int i,j,k,n;


x[1]=2;                                  // setting initial guess value to the independent variable
x[2]=1;
FILE *fp;
fp= fopen("output_problem5.txt","w");       // opening the output file for printing the solution
for(i=1;i<=2;i++)
{
printf("\nInitial guess of x[%d]: %f\n",i,x[i]);
fprintf(fp,"\nInitial guess of x[%d]: %f\n",i,x[i]);
printf("\n");
}
n=100;                                       // setting maximum number of permissible iterations
tolerance=pow(10,-10);                   // setting the tolerance limit
printf("\n\nMaximum numberof iterations: %d",n);


printf("\nTolerance= %0.10f\n\n",tolerance);
fprintf(fp,"\n\nMaximum number of iterations: %d",n);
fprintf(fp,"\nTolerance= %0.10f\n\n",tolerance);




/*for(i=1;i<=2;i++)
{
printf("Enter the value of x[%d]:",i);
scanf("%f",&x[i]);
printf("\n");
}

printf("Number of iterations:");
scanf("%d",&n);

printf("\nTolerance= ");
scanf("%f",&tolerance);

*/
for(k=1;k<=n;k++)
{                                             // using for loop for iteratition conditioned to maximum tolerance limit
	for(i=1;i<=3;i++)
	{
	y[i]=x[i];
	}
                                             // calling all the functions                         
	F[1] = function_1(x[1],x[2]);
	F[2] = function_2(x[1],x[2]);

	J[1][1] = der1_x1(x[1],x[2]);               // calling all the derivative functions and putting in the jacobian matrix
	J[1][2] = der1_x2(x[1],x[2]);

	J[2][1] = der2_x1(x[1],x[2]);
	J[2][2] = der2_x2(x[1],x[2]);



                                                                   // calculating determinant of the jacobian matrix

	det_J = (J[1][1]*J[2][2])-(J[1][2]*J[2][1]);
                                                                      // calculating inverse of jacobian matrix
	I[1][1]=J[2][2]/det_J;
	I[1][2]=-J[1][2]/det_J;

	I[2][1]=-J[2][1]/det_J;
	I[2][2]=J[1][1]/det_J;

	


	for(i=1;i<=2;i++)
	{
		for(j=1;j<=2;j++)
		{                                                        // calculating the solution of k(x)u= -f(x) and updating x
		x[i] += -I[i][j]*F[j];
		}
	}

	/*printf("\nThe solution after %d th iteration is:\n",k);
	for(i=1;i<=2;i++)
	{
	printf("x[%d] = %f\n",i,x[i]);
	}*/



	for(i=1;i<=2;i++)
	{
	error[i]=fabs(x[i]-y[i]);                           // calculating absolute error corresponding to each variable
	}

	max=error[1];

		if(max<error[2])
		{
		max=error[2];                              //  getting maximum error 
		}                                    // printing each iterative steps
	 printf("\nNR ns: %d, x[1]: %15.10f, x[2]: %15.10f, Error : %20.15f",k,x[1],x[2],max);  // printing ith iteration values
    fprintf(fp,"\nNR ns: %d, x[1]: %15.10f, x[2]: %15.10f, Error : %20.15f",k,x[1],x[2],max);
	

	if(max<tolerance)
	{                        // printing the solution
		printf("\n\n\nThe solution converges after %d iterations.",k);
	printf("\nThe final solution is:\n");
		fprintf(fp,"\n\n\nThe solution converges after %d iterations.",k);
	fprintf(fp,"\nThe final solution is:\n");
		for(i=1;i<=2;i++)
		{
		printf("x[%d]= %f\n",i,x[i]);
		fprintf(fp,"x[%d]= %f\n",i,x[i]);
		}
	
	exit(0);
	}

}

printf("No Solution!\nMaximum number of iterations exceeded!");
return 0;
}
