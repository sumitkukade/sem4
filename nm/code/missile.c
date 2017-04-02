#include<stdio.h>
#include<math.h>



   float findacceleration(float v , float t)
   {

     return(v/t);

   }



   float findmass(float F , float a)
   {

     return(F/a);

   }


   float finddisplacement(float a , float t)
   {

     return((a*(t*t))/2);

   }


   float findweight(float m , float g)
   {

     return(m*g);

   }

   float findheight(float s,int thita)
   {

     return(s*(sin (thita)));

   }


  float findlength(int thita,float s)
  {

    return(s*(cos(thita)));

    // return(((cos (thita))*(sin (thita)))/h);
  }

 int main()

 {

   float F,v,a,u,m,t,w,s,h,d,r;

   float g = 9.8;

   int thita;

   t = (rand()%60+1);

   printf("\n Enter The Force In Newton:=  ");

   scanf("%f",&F);

   printf("\n Enter The Velocity In m/s :=  ");

   scanf("%f",&v);

   printf("\n Enter The Angle Thita:= ");

   scanf("%d",&thita);
   
   a =  findacceleration(v,t);

   m = findmass(F,a);

   s = finddisplacement(a,t);

   w =  findweight(m,g);

   h = findheight(s,thita);

   r = findlength(thita,s);

   d = (2*r);
   
   if(d<0)
     {
       d = d*-1;
     }
   
   if(thita == 90)

     {
       d = 0;
     }

   printf("\n The Initial Point At Which Misaeil Is Start (x,y) = (0,0)");
 
   printf("\n\n");

   printf("\n The Acceleration Of Object := %f m/s^2",a);

   printf("\n\n");

   printf("\n The Mass Of Object:= %f g",m);

   printf("\n\n");

   printf("\n The Displacement Of Object:= %f m",s);

   printf("\n\n");
  
   printf("\n The Weight Of Object:= %f g",w);

   printf("\n\n");
 
   printf("\n The Height Of Object:= %f m",a);

   printf("\n\n");
 
   printf("\n The Final Point Or Position At Which Misaeil Is Move := (%f,0)",d);

   printf("\n\n");
 
   return 0;

 }
