#include<stdio.h>
#include<math.h>
float pi= 3.14,u=1;

float findangularvilocity(float u)
{
  return(2*pi*(u*u));//u=mue
}

float findspringconstant(float m,float w)
{
  return(m*(w*w));//m=mass,w=frequecy of oscillation
}

float findforce(float k,float x)
{
  return(k*x);//k=spring constant,x=stretches ruber 
}
float findacceleration(float f,float m)
{
  return (f/m);
}

int main()
{
  float x,thita,m,k,w,f,a;
  printf("enter length of strech rubber band(in cm)\n");
  scanf("%f",&x);
  printf("enter angle(in degree)\n");
  scanf("%f",&thita);
  printf("enter mass of the object(in kg)\n");
  scanf("%f",&m);
  w=findangularvilocity(u);
  k=findspringconstant(m,w);
  f=findforce(k,x);
  a=findaccleleration(f,m);
  printf("Force(in N)=%f\n",f);
  printf("Angular Vilocity(in m)=%f\n",w);
  printf("Spring constant=%f\n",k);
  printf("acceleration =%f\n",a);

}
