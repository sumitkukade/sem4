#include<stdio.h>
#include<math.h>
float f(float x)
{
  return(-0.9*(x*x)+1.7*x+2.5);
  
}
void main()
{
  int i,n;
  float x1,x2,x3,y1,y2,y3;
  printf("Enter the value of x1:");
  scanf("%f",&x1);
  printf("Enter the value of x2:");
  scanf("%f",&x2);
  printf("Enter the no of iteration n:");
  scanf("%d",&n);
  y1=f(x1);
  y2=f(x2);
  while(y1*y2>0)
    {
      printf("\n\n entered values for x1 & x2 are not have opposite sign\n\n");
      printf(" Again enter the value of x1:");
      scanf("%f",&x1);
      printf(" Again enter the value of x2:");
      scanf("%f",&x2);
      y1=f(x1);
      y2=f(x2);
      
    }
  for(i=1;i<=n;i++)
    {
      x3=((x1+x2)/2);
      y3=f(x3);
      if((y1*y3)<0)
	{
	  x2=x3;
	  y2=y3;
	}
      else
    	    	   {
		     x1=x3;
		     y1=y3;
		     
    	    	   }
    }
  printf("The root of x3 %f",x3);
  
}




