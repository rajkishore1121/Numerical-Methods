#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int main(){
	
		int i, j;
	FILE *fp1;
	int  m=0,n=1;
	char ch;
	fp1= fopen("augumented matrix.txt","r");               //reading rows and columns from file
          	while(!feof(fp1))
	{
	ch=fgetc(fp1);
		if(ch=='\t' && m==0)
		n++;
		else if(ch=='\n')
		m++;	
		
	}    
		
	printf("\nFor augumented matrix number of rows are: %d \nNumber of columns are: %d ",m,n);
	fclose(fp1);
	
       float m2[m][n];
	fp1= fopen("augumented matrix.txt","r");             // reading augumented matrix from file
	while(!feof(fp1))
	{
		for(i=0; i<m; i++)
		{
			for(j=0; j<n; j++)
			fscanf(fp1,"%f\t",&m2[i][j]);
				
		}
			}
				fclose(fp1);
			printf("\n\nInput Augumented Matrix from the file:\n\n\n");       // printing the augumented matrix after reading from the file
				for(i=0; i<m; i++)
		{
			for(j=0; j<n; j++)
			
				printf("%.4f\t", m2[i][j]);
				printf("\n");
		}
		
		printf("\nElimination phase:\n");
		
		int k; float c=0;
		for(j=0; j<(n-1);j++)
		{                                                    // Doing Gauss elimination
			for(i=0;i<m;i++)
			{
				if(i>j)
			{
					c= ((m2[i][j])/(m2[j][j]));
			
				
				for(k=0; k<n; k++)
				m2[i][k]=m2[i][k]-(c*m2[j][k]);
			
			} 
		}
		}
			printf("\n\nRows are %d and columns are %d\n\n", m,n);
			for(i=0; i<m; i++)
		{                                                              
			for(j=0; j<n; j++)                                 // printing matrix after Gauss elimination
			{
			
				printf("%.4f\t", m2[i][j]);
			}
				printf("\n");
			}
				float x[m-1], sum;
				x[m-1]=(m2[m-1][n-1]/m2[m-1][m-1]);                          
			//	printf("\nx%d is %f\n",m,x[m-1]);
				for(i=(m-1); i>=0; --i)
				{
					sum=0;
					for(j=(i+1); j<(n-1); j++)                              // Back substitution process
					{
						sum= sum + (m2[i][j]*x[j]);
										
				     	}
					x[i]=(m2[i][n-1] - sum)/ m2[i][i];
					
				}
				                                                               
				printf("\noutput solution after back substitution:\n");
				fp1= fopen("Gauss elimination output.txt","w");
		for(i=0; i<m; i++)
		{                                                              // printing the solution
			printf("\nx%d = %f\n",i+1,x[i]);
			fprintf(fp1,"\nx%d = %f\n",i+1,x[i]);
		}
		fclose(fp1);
		
	getch ();
	return 0;
           }
