#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
	FILE *fp= fopen("outputproblem1.txt","w");
	double tol= pow(10,-15);           // setting tolerance limit
	printf("Tolerance: %0.20f",tol);
	fprintf(fp,"Tolerance: %0.20f",tol);
	int nsmax=2000;                    // setting max number of iteration permissible
	int error =0;                       // initialising the initial error
	double xold=3.1;                      //    setting initial guess
	double xnew= xold;
	double fx= pow(xold,2)-10;           //    setting the given function
	double en=1;
	int ns=1;
	
	while(en>tol && ns<= nsmax)                        // using while loop for iteration with conditoned to 
	//                                                specified tolerance limit and maximum numbet of iteration
	
	{
		
		xold=xnew;
		fx= pow(xold,2)-10;
		float derfx= 2*xold;
		printf("\nNR ns: %d, x(%d): %20.15f, f(x): %20.15f, Error : %20.15f",ns,ns-1,xold,fx,en);
    fprintf(fp,"\nNR ns: %d, x(%d): %20.15f, f(x): %20.15f, Error : %20.15f",ns,ns-1,xold,fx,en);
    
    if(derfx<0.0000000000000000001 && derfx>-0.0000000000000000001)             // checking whether derivative is very very small
    error=1;                                                                     // or slope at that point is tending parallel to x axis
    
    
    else
    	xnew=xold-((fx)/derfx);
    	en= fabs(xnew-xold);                                          // calculating absolute error
    	ns=ns+1;
	    
	}
	printf("\n\n\nNR itr number: %d, x(%d): %30.25f, x(%d): %30.25f, Error : %30.25f",ns-1,ns-2,xold,ns-1,xnew,en);
   fprintf(fp,"\n\n\nNR itr number: %d, x(%d): %30.25f, x(%d): %30.25f, Error : %30.25f",ns-1,ns-2,xold,ns-1,xnew,en);
     
     
if (ns >= nsmax)
{
	error = 2 ;
}
    


if (error == 0)
     {                                        //  printing the solution if no error occur
	 
	 printf("\n\n Newton-Raphon method converged in %d iterations ....",ns-1) ;  
    printf("\n\nThe solution is : %20.15f",xnew);
     fprintf(fp,"\n\n Newton-Raphon method converged in %d iterations ....",ns-1) ;  
    fprintf(fp,"\n\nThe solution is : %20.15f",xnew);  
}
else
    if (error == 1)
        {
		printf("\n\n Newton-Raphon method could not find solution since derivative of f(x) became very small  ....") ;
        fprintf(fp,"\n\n Newton-Raphon method could not find solution since derivative of f(x) became very small  ....") ;
    }
    else if (error == 2)
    {
        printf("\n\n Newton-Raphon method exceeded maximum number of iterations .... \n\n") ;  
        fprintf(fp,"\n\n Newton-Raphon method exceeded maximum number of iterations .... \n\n") ;
}

	
	fclose(fp);
	getch ();
	return 0;
}
