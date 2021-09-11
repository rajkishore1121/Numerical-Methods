#include<stdio.h>
#include<conio.h>

int main()
{
	
	int m,n,i,j,sum=0;                      //    Naming and initialising the required variables
	printf("Enter the number of elements of first column vector: \n");
	scanf("%d",&m);
	printf("Enter the number of elements of second column vector: \n");         // taking input from user number of column vector
	scanf("%d",&n);
	int u[m], v[n];                                                       //   Naming and initialising array size as per requirement
	printf("Enter the elements of first column vector: \n");
	
		for(i=0;i<m;i++)                                                // using for loop for taking input coumn elements from user and storing inside array
	{
		
		scanf("%d", &u[i]);
	}
		//printf("\n");
		printf("Enter the elements of second column vector: \n");
	
		for(j=0;j<n;j++)                                                    // using for loop for taking input coumn elements from user and storing inside array
	{
		
		scanf("%d", &v[j]);
	}
		printf("\n");
		
			printf("Outer product of two vectors are:\n\n");
			for(i=0;i<m;i++)
		{                                                      // using nested for loop for calculating outer product
			for(j=0;j<n;j++)
			{
				
			printf("%d\t",u[i]*v[j]);                        // printing the result for outer product
			}
			printf("\n");
		
		}
			if(m!=n){
		
			printf("\n\nAs number of elements of first column vectors is not equal to the number of elements of second column vector, inner product cannot be evaluated\n ");
		
	}
		else if(m=n)
		{ 
			for(i=0;i<m;i++)                 //   using for loop for calculating outer product
			{
				sum= sum+u[i]*v[i];      //           multilying ith element of first array with ith element of second array and storing 
				                           // obatained valued in variable sum.
			}
		printf("\nInner product of two vectors are:\n %d\n",sum);            // printing the result for inner product
								
		}
	
	getch();
	return 0;
}
