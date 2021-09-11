#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>

float x[4];                 // setting number of independent variable in the system of equation

float function_1 ()              
{
float f1;                   //           setting first function from the system of given equation
f1 = pow(x[1],2)+pow(x[2],2)+pow(x[3],2)-1;
return f1;
}


float function_2 ()                 //     setting second function
{
float f2;
f2 = pow(x[1],2)+pow(x[3],2)-0.25;
return f2;
}


float function_3 ()                   //   setting third function
{
float f3;
f3 = pow(x[1],2)+pow(x[2],2)+(4*x[3]);
return f3;
}
                               // setting partial derivative of first fuction for jacobian matrix

float der1_x1 ()
{
float d11;
d11 = (2*x[1]);
return d11;
}


float der1_x2 ()
{
float d12;
d12 = (2*x[2]);
return d12;
}


float der1_x3 ()
{
float d13;
d13 = (2*x[3]);
return d13;
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
d22 = 0;
return d22;
}


float der2_x3 ()
{
float d23;
d23 = (2*x[3]);
return d23;
}


float der3_x1 ()
{
float d31;
d31 = (2*x[1]);
return d31;
}


float der3_x2 ()
{
float d32;
d32 = (2*x[2]);
return d32;
}


float der3_x3 ()
{
float d33;
d33 = 4;
return d33;
}

int main()
{

float F[10],J[10][10],det_J,I[10][10],y[3],error[3],max,tolerance;   // initialing the required variable
int i,j,k,n;
                                           // setting initial guess value to the independent variable
x[1]=1;
x[2]=1;
x[3]=1;
FILE *fp;
fp= fopen("output_problem4.txt","w");                 // opening the output file for printing the solution
for(i=1;i<=3;i++)
{
printf("\nInitial guess of x[%d]: %f\n",i,x[i]);
fprintf(fp,"\nInitial guess of x[%d]: %f\n",i,x[i]);
printf("\n");
}
n=100;                                         // setting maximum number of permissible iterations      
tolerance=pow(10,-10);                           // setting the tolerance limit
printf("\n\nMaximum number of iterations: %d",n);


printf("\nTolerance= %0.10f\n\n",tolerance);
fprintf(fp,"\n\nMaximum number of iterations: %d",n);
fprintf(fp,"\nTolerance= %0.10f\n\n",tolerance);


for(k=1;k<=n;k++)                                // using for loop for iteratition conditioned to maximum tolerance limit
{
	for(i=1;i<=3;i++)
	{
	y[i]=x[i];
	}


                                               // calling all the functions 
	F[1] = function_1(x[1],x[2],x[3]);
	F[2] = function_2(x[1],x[2],x[3]);
	F[3] = function_3(x[1],x[2],x[3]);
                                            // calling all the derivative functions and putting in the jacobian matrix
	J[1][1] = der1_x1(x[1],x[2],x[3]);
	J[1][2] = der1_x2(x[1],x[2],x[3]);
	J[1][3] = der1_x3(x[1],x[2],x[3]);

	J[2][1] = der2_x1(x[1],x[2],x[3]);
	J[2][2] = der2_x2(x[1],x[2],x[3]);
	J[2][3] = der2_x3(x[1],x[2],x[3]);

	J[3][1] = der3_x1(x[1],x[2],x[3]);
	J[3][2] = der3_x2(x[1],x[2],x[3]);
	J[3][3] = der3_x3(x[1],x[2],x[3]);

/*printf("\nThe function matrix F(x) is:\n");
for(i=1;i<=3;i++)
{                                                               // printing the function
printf("%f\n",F[i]);
}
printf("\n\n");


printf("The Jacobian matrix J(x) is:\n");
for (i=1;i<=3;i++)
{                                                          // printing the jacobian matrix
for(j=1;j<=3;j++)
{
printf("%f\t",J[i][j]);
}
printf("\n");
}

printf("\n\n");*/

                            // calculating determinant of the jacobian matrix
	det_J = J[1][1]*(J[2][2]*J[3][3]-J[2][3]*J[3][2])-J[1][2]*(J[2][1]*J[3][3]-J[3][1]*J[2][3])+J[1][3]*(J[2][1]*J[3][2]-J[3][1]*J[2][2]);
                                                         // calculating inverse of jacobian matrix
	I[1][1]=(J[2][2]*J[3][3]-J[2][3]*J[3][2])/det_J;
	I[1][2]=(J[3][2]*J[1][3]-J[3][3]*J[1][2])/det_J;
	I[1][3]=(J[1][2]*J[2][3]-J[1][3]*J[2][2])/det_J;
	I[2][1]=(J[2][3]*J[3][1]-J[2][1]*J[3][3])/det_J;
	I[2][2]=(J[3][3]*J[1][1]-J[3][1]*J[1][3])/det_J;
	I[2][3]=(J[1][3]*J[2][1]-J[1][1]*J[2][3])/det_J;
	I[3][1]=(J[2][1]*J[3][2]-J[2][2]*J[3][1])/det_J;
	I[3][2]=(J[3][1]*J[1][2]-J[1][1]*J[3][2])/det_J;
	I[3][3]=(J[1][1]*J[2][2]-J[2][1]*J[1][2])/det_J;

/*for(i=1;i<=3;i++)
{
for(j=1;j<=3;j++)
{
printf("%f\t",I[i][j]);             // printing the inverse of jacobian matrix
}
printf("\n");
}
printf("\n");*/
	
	for(i=1;i<=3;i++)
	{
		for(j=1;j<=3;j++)
		{
		x[i] += -I[i][j]*F[j];                  // calculating the solution of k(x)u= -f(x) and updating x
		}
	}

/*	printf("\nThe solution after %d th iteration is:\n",k);
	for(i=1;i<=3;i++)
	{
	printf("x[%d] = %f\n",i,x[i]);
	}
*/


	for(i=1;i<=3;i++)
	{
	error[i]=fabs(x[i]-y[i]);                   // calculating absolute error corresponding to each variable
	}
	max=error[1];

	for(i=2;i<=3;i++)
	{
		if(max<error[i])
		{
		max=error[i];                                     //  getting maximum error 
		}
	}                 // printing ith iteration values
     printf("\nNR ns: %d, x[1]: %15.10f, x[2]: %15.10f,x[3]: %15.10f Error : %20.15f",k,x[1],x[2],x[3],max);
    fprintf(fp,"\nNR ns: %d, x[1]: %15.10f, x[2]: %15.10f, x[3]: %15.10f Error : %20.15f",k,x[1],x[2],x[3],max);
	
    
	if(max<tolerance)
	{                               // printing the solution
	printf("\n\n\nThe solution converges after %d iterations.",k);
	printf("\nThe final solution is:\n");
		fprintf(fp,"\n\n\nThe solution converges after %d iterations.",k);
	fprintf(fp,"\nThe final solution is:\n");
		for(i=1;i<=3;i++)
		{
		printf("x[%d]=%0.10f\n",i,x[i]);
		fprintf(fp,"x[%d]=%0.10f\n",i,x[i]);
		}
	fclose(fp);
	exit(0);
	}

}

printf("No Solution!\nMaximum number of iterations exceeded!");


return 0;
}
