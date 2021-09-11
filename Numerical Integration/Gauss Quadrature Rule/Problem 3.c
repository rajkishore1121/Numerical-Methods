#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>

float I;

float function_evaluation1(float x)     // Declaring the function for which integration is to be calculated
{
	float fn1= pow(x,2);
	
	return fn1;
	
}

float function_evaluation2(float x)             // Declaring the function for which integration is to be calculated
{
	float fn2=pow((x),2)-1;
	return fn2 ;
	}
	
float function_evaluation3(float x)              // Declaring the function for which integration is to be calculated
{
	float fn2=pow((x),4)-2;
	return fn2 ;
	}
	
float analytical_solution()
{
		return 3.2;         // returning exact solution values
}
float gauss1D(int n)            // implementing Gauss integration method for numerical integration
{
	float wi[10],wj[10],xi[10],xj[10],wk[10],xk[10];
	
	if(n==2)                            // for 2 gauss points
	{
		wi[1]=1.00;
		wi[2]=1.00;
		xi[1]=-0.577350269;
		xi[2]=0.577350269;
		
			int i;
		float I1=0,I2=0,I3=0;

		for(i=1;i<=n;i++)
	{
		I1+=(wi[i]*function_evaluation1(xi[i]));
	}
	for(i=1;i<=n;i++)
	{
		I2+=(wi[i]*function_evaluation2(xi[i]));
	}
		for(i=1;i<=n;i++)
	{
		I3+=(wi[i]*function_evaluation3(xi[i]));
	}
	float I= I1*I2*I3;
	printf("\nValue of Integral using %d Gauss points: \nI=%5.10f\n",n,I);   // printing the solution values
	float exact=analytical_solution();
	float error=fabs(exact-I);
	printf("Error=%5.10f\n",error);
	
	}
		
		else if(n==3)             // for 3 gauss points
		{
		wj[1]=0.8888888888;
		wj[2]=0.55555555556;
		wj[3]=0.55555555556;
		xj[1]=0.00000;
		xj[2]=-0.7745966692;
		xj[3]=0.77459666924;
				float I1=0,I2=0,I3=0;

			int i;
		for(i=1;i<=n;i++)
	{
		I1+=(wj[i]*function_evaluation1(xj[i]));
	}
	for(i=1;i<=n;i++)
	{
		I2+=(wj[i]*function_evaluation2(xj[i]));
	}	for(i=1;i<=n;i++)
	{
		I3+=(wj[i]*function_evaluation3(xj[i]));
	}
	float I= I1*I2*I3;

	printf("\nValue of Integral using %d Gauss points: \nI=%5.10f\n",n,I);   // printing the solution values
		float exact=analytical_solution();
	float error=fabs(exact-I);
	printf("Error=%5.10f\n",error);
					}			
		
		else if(n==4)                      // for 4 gauss points
		{
			wk[1]=0.65214515486;
		wk[2]=0.65214515486;
		wk[3]=0.347854845137;
		wk[4]=0.347854845137;
		xk[1]=-0.33998104358;
		xk[2]=0.33998104358;
		xk[3]=-0.86113631159;
		xk[4]=0.86113631159;
				float I1=0,I2=0,I3=0;

			int i;
		for(i=1;i<=n;i++)
	{
		I1+=(wk[i]*function_evaluation1(xk[i]));
	}
	for(i=1;i<=n;i++)
	{
		I2+=(wk[i]*function_evaluation2(xk[i]));
	}
		for(i=1;i<=n;i++)
	{
		I3+=(wk[i]*function_evaluation3(xk[i]));
	}
	float I= I1*I2*I3;
	printf("\nValue of Integral using %d Gauss points: \nI=%5.10f\n",n,I); // printing the solution values
	float exact=analytical_solution();
	float error=fabs(exact-I);
	printf("Error=%5.10f\n",error);
		}

}

int main()
{
	gauss1D(2);              // calling the gauss1D function for different gauss points
	gauss1D(3);
	gauss1D(4);
	return 0;
}


