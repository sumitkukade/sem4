#include<stdio.h>
#include<math.h>

   float f(float x)

   {

     return((x*x*x)-(2*x)-5);

   }

   float A(float x1,float x2,float x3,float y1,float y2,float y3)

   {

     return (((y2-y3)/((x2-x1)*(x2-x3)))+((y1-y3)/((x1-x3)*(x1-x2))));
   }

   float B(float x2,float x3,float y2,float y3,float a)

   {


     return(((y2-y3)/(x2-x3))-a*(x2-x3));

   }



  int main()

   {


      float x1,x2,x3,x4,y1,y2,y3,y4,a,b;

      int i,n,r1,r2,r3,d;

      printf("\n Enter The Number Of Itreation:= ");
 
      scanf("%d",&n);

  for(i=1;i<=n;i++)

    {

      r1= f(i);
      r2= f(i+1);
      r3 =f(i+2);

      d = i;

      if(r1 < 0 && r2 < 0 && r3 >0 ||r1 < 0 && r2 > 0 && r3 <0 ||r1 > 0 && r2 < 0 && r3 <0  )

       { 
     
           break;
       }


    }

  x1 = d+2;

  x2 = d+1;

  x3 = d;



      for(i=1;i<n;i++)

	{

           y1 = f(x1);

           y2 = f(x2);

           y3 = f(x3);


           a = A(x1,x2,x3,y1,y2,y3);

           b = B(x2,x3,y2,y3,a);

          x4 = x3 -((2*y3)/((b)+sqrt((b*b)-(4*a*y3))));

          y4 = f(x4);

          x3 = x4;

          y3 = y4;

	}

      printf("\n Root:= %f",x4);


      return 0;

   }
