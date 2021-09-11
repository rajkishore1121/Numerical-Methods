#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int main(){
	
		int i, j;
	FILE *fp1;
	int  m=0,n=1;
	char ch;
	fp1= fopen("augumented matrix.txt","r");                       //reading rows and columns from file
          	while(!feof(fp1))
	{
	ch=fgetc(fp1);
		if(ch=='\t' && m==0)
		n++;
		else if(ch=='\n')
		m++;	
		
	}    
		
	printf("Number of rows are %d \nNumber of columns are %d ",m,n);
	fclose(fp1);
	
       float m2[m][n];
	fp1= fopen("augumented matrix.txt","r");                     // reading augumented matrix from file
	while(!feof(fp1))
	{
		for(i=0; i<m; i++)
		{
			for(j=0; j<n; j++)
			fscanf(fp1,"%f\t",&m2[i][j]);
				
		}
			}
				fclose(fp1);
			printf("\n\nInput Augumented Matrix\n\n\n");                             // printing the augumented matrix after reading from the file
				for(i=0; i<m; i++)
		{
			for(j=0; j<n; j++)
			
				printf("%.4f\t", m2[i][j]);
				printf("\n");
		}
		
		printf("\n\nRows are %d and columns are %d", m,n);
		printf("\nElimination phase\n");
		
		float temp , c=0;
		int p,k,g,h; 
		for(j=0; j<(n-1);j++)
		{
		for(i=0;i<m;i++)
		{	
			if(m2[i][i]==0)                                // condition check for zero pivot elements
			{
				for(g=i+1; g<n-1; )
				{
					if(m2[g][i]!=0)
					{                                             	//exchange rows if zero pivot found	
		for(p=0; p<n; p++)
		{
			temp= m2[i][p];
			m2[i][p]=m2[g][p];
			m2[g][p]=temp;
		}
					break;
					}
					else if(m2[j][i]==0)
				{
					if(g<n-1)
					{
					g=g+1;
					}
					else
					{
						printf("Matrix is Singular");
						return;
					}
				
				}	
				}
			   }
			   
			   
			 for(h=(i+1); h<(m-1); )
			   {
			   	
			   	if(m2[i][i]<m2[h][i])                  // partial pivoting
			   {
			   		for(p=0; p<n; p++)
		{
			temp= m2[h][p];
			m2[h][p]=m2[i][p];
			m2[i][p]=temp;
		}
				
						   }
						   break;
						   	
			   }  
			   		
			
				if(i>j)                      // Gauss elimination phase
			{
					c= ((m2[i][j])/(m2[j][j]));
			
				
				for(k=0; k<n; k++)
				m2[i][k]=m2[i][k]-(c*m2[j][k]);
			
			} 
		}
		}
			printf("\n\nFor Augumented matrix Rows are %d and columns are %d\n\n", m,n);                       // printing matrix after Gauss elimination
			printf("\n\nAugumented matrix after partial pivoting and Gauss Elimination:\n\n");
			for(i=0; i<m; i++)
		{
			for(j=0; j<n; j++)
			{
			
				printf("%.4f\t", m2[i][j]);
			}
				printf("\n");
			}
			printf("\nBack substitution\n");                // Back substitution
			
				float x[m-1], sum;
				x[m-1]=(m2[m-1][n-1]/m2[m-1][m-1]);
			//	printf("\nx%d is %f\n",m,x[m-1]);
				for(i=(m-1); i>=0; --i)
				{
					sum=0;
					for(j=(i+1); j<(n-1); j++)
					{
						sum= sum + (m2[i][j]*x[j]);
										
				     	}
					x[i]=(m2[i][n-1] - sum)/ m2[i][i];
					
				}
				
				printf("\nSolution of the system of linear equations\n");
				fp1= fopen("Gauss elimination output.txt","w");
		for(i=0; i<m; i++)
		{
			printf("\nx%d = %f\n",i+1,x[i]);
			fprintf(fp1,"\nx%d = %f\n",i+1,x[i]);
		}
		fclose(fp1);
		
	getch ();
	return 0;
           }
