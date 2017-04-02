#include<stdio.h>
#include<math.h>

   float fx1(float x2,float x3)

   {

      return((32-(4*x2)+x3)/28);
 
   }

   float fx2(float x1,float x3)

   {

     return((35-(2*x1)-(4*x3))/17);

   }

   float fx3(float x1,float x2)

   {

     return((24-(x1)-(3*x2))/10);

   }


  int main()

   {

      float x1=0,x2=0,x3=0,y1,y2,y3;

      int i,n;

      printf("\n Enter The Number Of Iteration:= ");

      scanf("%d",&n);

      for(i=1;i<=n;i++)

       {
     
           y1 = fx1(x2,x3);

           y2 = fx2(y1,x3);

           y3 = fx3(y1,y2);

           x1 = y1;

           x2 = y2;

           x3 = y3;



     }

      printf("\n Roots Are:= \n");

      printf("\n x1:=%f\n x2:=%f\n x3:=%f\n",x1,x2,x3);
      
     return 0;

    
    }


