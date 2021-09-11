#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int main(){
	
	int i, j;
	FILE *fp1;
	int  m=0,n=1, p=1;
	char ch;
	fp1= fopen("matrix1.txt","r");          //reading rows and columns from file
          	while(!feof(fp1))
	{
	ch=fgetc(fp1);
		if(ch=='\t' && m==0)
		n++;
		else if(ch=='\n')
		m++;	
		
	}    
		
	printf("Number of rows are: %d \nNumber of columns are: %d ",m,n);
	fclose(fp1);
	
       int m2[m][n];
	fp1= fopen("matrix1.txt","r");         // reading matrix from file
	while(!feof(fp1))
	{
		for(i=0; i<m; i++)
		{
			for(j=0; j<n; j++)
			fscanf(fp1,"%d\t",&m2[i][j]);
				
		}
			}
				fclose(fp1);
			printf("\nInput Matrix from the file:\n");          // printing the input matrix taken from file
				for(i=0; i<m; i++)
		{
			for(j=0; j<n; j++)
			
				printf("%d\t", m2[i][j]);
				printf("\n");
		}
		
		
		
		
		
		fp1= fopen("matrix2.txt","r");            // reading number of elements in vector from file
          	while(!feof(fp1))
	{
	ch=fgetc(fp1);
		if(ch=='\n')
		p++;	
		
	}    
		
	printf("Number of elements in vector %d",p);         
	fclose(fp1);
	
       int m1[p];
	fp1= fopen("matrix2.txt","r");                   // reading vector element from the file
	while(!feof(fp1))
	{
		for(i=0; i<p; i++)
		{
			fscanf(fp1,"%d",&m1[i]);
				
		}
			}
				fclose(fp1);
			printf("\nInput vector from the file:\n");
				for(i=0; i<p; i++)
		{
			
				printf("%d\t", m1[i]);
				printf("\n");
		}
		
	if(n!=p)
	
	{
		printf("Matrix vector multiplication not allowed as number of column of matrix is not equal to number of elements in vector.\n");
		
		}	
	else if(n=p)
	{
		int r[m], c=0;
		for(i=0; i<m; i++)
		{
			for(j=0; j<n; j++)
			{
				c= c+ m2[i][j]*m1[j];                 // multiplying matrix with vector 
			}
			
			r[i]= c;
			c=0;
		}
		printf("\nResultant matrix after matrix-vector multiplication: \n");             // printing output
			fp1= fopen("output.txt","w");
			for(i=0; i<p;i++)
			{
				printf("%d\n",r[i]);
				fprintf(fp1,"%d\n",r[i]);
			}
			
			
			
			fclose(fp1);
	}
	
	getch();
	return 0;
}
