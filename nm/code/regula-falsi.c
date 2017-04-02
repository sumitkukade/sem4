#include<stdio.h>
#include<math.h>

float f(float x)
{
  return ((x*x*x)-(2*x)-5);
}

int main()
{

  float x1,x2,x3,y1,y2,y3;

  int i,n,a,b,c;

  printf("\n Enter The Number Of Iteration:= ");

  scanf("%d",&n);

  for(i=0;i<=n;i++)

    {

      a = f(i);
      b = f(i+1);
      c = i;

      if(a < 0 && b > 0 || a > 0 && b < 0)

       { 
     
           break;
       }


    }

  x1 = c;

  x2 = c+1;

  for(i=0;i<n;i++)

    {

      y1 = f(x1);

      y2 = f(x2);

      x3 = (((x1*y2)-(x2*y1))/(y2-y1));

      y3 = f(x3);

	    if(y1*y3<0)
	      {

		x2 = x3;

	      }

	    else
	      {

		x1 = x3;
		
	      }
	    }

	printf("\n The Root c := %f",x3);


  return 0;

}


