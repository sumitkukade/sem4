#include<stdio.h>
#include<math.h>


  float f(float x)
   {

     return(((x*x*x)-2*x-3));

   }

   float df(float x)
   {

     return((3*(x*x))-2);

   }

int main()

   {

     float x1,x2,x3,y1,y2,y3,a,b,c;

     int i,n;

     printf("\n Enter The Number Of Iteration n:= ");

     scanf("%d",&n);

     for(i=1;i<n;i++)

       {

	 a = f(i);
	 b = f(i+1);
	 c = i+1;

	 if(a < 0 && b > 0 || a > 0 && b < 0)

	   { 
     
	     break;
	   }


       }

     x1 = c;

     y1 = f(x1);

     y2 = df(x1);
     
  for(i=0;i<n;i++)

	{

               x2 = x1 - (y1/y2);

               y2 = f(x2);
    
               y3 = df(x2);

	       x1 = x2;

	       y1 = y2;

	       y2 = y3;

	  
	}

      printf("\n The Root Is x2:= %f",x2);

  return 0;

}

