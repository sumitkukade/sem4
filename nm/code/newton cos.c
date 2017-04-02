#include<stdio.h>
#include<math.h>
float e=2.7182;
float eq1(float x)
{
  return((pow(e,x)*cos(x))-1.4);
}
float eq2(float x)
{
  return((-pow(e,x)*sin(x))+(pow(e,x)*cos(x)));
}
void main()
{
  int i,n;
  float x1,x0,x2,x3,y1,y2,y3,s;
  printf("enter value of x1");
  scanf("%f",&x1);
  
  printf("enter no iteration");
  scanf("%d",&n);
  y1=eq1(x1);
  y2=eq2(x1);
  for(i=0;i<n;i++)
    {
      x2=x1-(y1/y2);
      y2=eq1(x2);
      y3=eq2(x2);
      
      x1=x2;
      y1=y2;
      y2=y3;
      
      
      
      
   		printf("the root is %f\n",x2);
		
    }
  
  
}


