#include<stdio.h>
#include<conio.h>

int main()
{
	int m,n,p,q,i,j,k, sum=0;                                 //    Naming and initialising the required variables of integer data type
	int first[10][10], second[10][10], multiply[10][10];       //   initialising the 2D array size for input and output matrix
	printf("Enter the number of rows and columns of thr first matrix:\n");
	scanf("%d %d",&m,&n);                                       // taking input for size of first matrix from the user
	
		printf("Enter the number of rows and columns of the second matrix: \n");
		scanf("%d %d",&p,&q);                                            // taking input for size of second matrix from the user
		
		if(n!=p)                                                       // checking whether the matrix maultiplication of given two input order is possible
		printf("Matrices with entered orders can not be multiplied\n");
		else{
		
	
		printf("Enter the elements of the first matrix in terms of column vector:\n");     // if matrix multiplication is possible taking input of 
		for(i=0;i<n;i++)                                                                //first matrix in the form of column vector or in series of column elements
		{                                                                               // using for  and storing elements in 2D arrayloop for taking input
		if(i!=0)                                                                       //  of first matrix
		{
			printf("Enter next column elements:\n");
		}
			for(j=0;j<m;j++)
			{
				scanf("%d",&first[j][i]);
			}
			printf("\n");
		
		}
		
			
			printf("Enter the elements of the second matrix in terms of column vector:\n");
		for(i=0;i<q;i++)                                                    // using for  and storing elements in 2D arrayloop for taking input as column vector
		{                                                                   // for second matrix
			if(i!=0)
		{
			printf("Enter next column elements:\n");
		}
			for(j=0;j<p;j++)
		{
		scanf("%d",&second[j][i]);
		}
		
			printf("\n");
		}
		
		                          /*  we have matrix of order mxn and nxq, to calculate matrix multiplication, for each column of second matrix
		                        each row elements of first matrix is multiplied with each row element of second matrix and added.
								 Therefore for qth column of column of second matrix we have to multiply each m row 
								elements of first matrix with each n row elements of second matrix and
								 therefore we require three nested loops with sequence of q, m and n
								 to evaluate test condition  */
		for(i=0;i<q;i++)               
		{
			for(j=0;j<m;j++)
			{
				for(k=0;k<n;k++)
				{
					sum=sum+first[j][k]*second[k][i];       // for a particular column of second matrix and particular row of first matrix
					//                                                multiplying each row elements of first matrix with each row elements of second matrix
					//                                             and storing the value obtained in the variable sum.
				}
				
				multiply[j][i]=sum;                                 // storing the value of sum in the output 2D array 
				sum=0;
				
			}
			
		
		}
			printf("Resultant matrix after multiplicaton:\n\n");       // printing the resultant 2D array obatained after multiplicaton in matrix form
		for(i=0;i<m;i++)
		{
			for(j=0;j<q;j++){
				
			printf("%d\t",multiply[i][j]);
			}
			printf("\n");
		
		}
	}
		
	
		
	getch();
	return 0;
}
