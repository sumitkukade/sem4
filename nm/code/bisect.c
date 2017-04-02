#include<stdio.h>
#include<stdlib.h>
#include<math.h>

float powr(float tmp,int i)
{
  if(i==0)
    {
      return 1;  
    }
  else
    return tmp*powr(tmp,i-1);
}
float f(float arrx[],float tmp,int n)
{
  int i;
  float sum=0;
  for(i=0;i<=n;i++)
    {
      sum+=arrx[i]*powr(tmp,i);  
    }
  return sum;
}
int main()
{
  int i,cnt,n;
  float x,arrx[10],lb,ub,tmp,tmp1;
  printf("Enter the max power of your polynomial\n");
  scanf("%d",&cnt);
  for(i=0;i<=cnt;i++)
    {
      printf("Enter the coeff for x^%d",i);
      scanf("%f",&arrx[i]);
    }
  printf("Enter the initial upper and lower bounds within which the root will lie:\n");
  scanf("%f",&ub);
  scanf("%f",&lb);
  //printf("lb is %f",tmp);
  printf("Enter the number of iterations\n");
  scanf("%d",&n);
  
  tmp=(ub+lb)/2;
      if(f(arrx,tmp,cnt)>0)
	{
          ub=tmp;
	  
	}
      else 
	{
          lb=tmp;  
	}
  tmp1=0;    
  while(n>0)
    {
      tmp1=tmp;
      tmp=(ub+lb)/2;
      if(f(arrx,tmp,cnt)>0)
	{
          ub=tmp;
	}
      else 
	{
          lb=tmp;  
	}
      printf("%f",tmp);
      n--;
    }
  printf("The root of the equation is %f",tmp);
}
