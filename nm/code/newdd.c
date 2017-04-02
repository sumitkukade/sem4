#include<stdio.h>
#include<stdlib.h>
#include<math.h>

float fact(int cntr)
{
  int i,fact=1;
  for(i=1;i<=cntr;i++)
    {
      fact*=i;
    }
   
  return (fact); 
}

float powr(float x,int n)
{
  if(n==1)
    return x;
  return powr(x*x,n-1);
}

float calculate(float x[],float val,int cnt)
{
  int i;
  float tmp=val;
  for(i=0;i<cnt;i++)
    {
      tmp-=x[i];
    }
  return tmp;
} 
int main()
{
  float x[10],fx[10],dd[20],value,result;
  int n,i,tmp,j,cnt=0,cntr=1;
  printf("Enter the number of values for x & fx\n");
  scanf("%d",&n);
  printf("\nEnter the values for x & fx:");
  for(i=0;i<n;i++)
    {
      scanf("%f",&x[i]);
      scanf("%f",&fx[i]);
    }
  for(i=0;i<n;i++)
    {
      dd[i]=fx[i];
    }
  tmp=n;
  while(tmp/2>0)
    {
      for(i=0,j=1;j<tmp;i++,j++)
       {
	 dd[cnt]=(1/fact(cntr))*(dd[j]-dd[i])*(1/powr((x[j]-x[i]),cntr));
              cnt++;
       }
      cntr++;
      tmp--;
    }
  /*for(i=0;i<cnt;i++)
    printf("%f\n",dd[i]);*/
  printf("\nEnter the value for which you want to find fx");
  scanf("%f",&value);   
  result=fx[0]; 
  for(i=0;i<cnt;i++)
    {
      result+=calculate(x,value,i)*dd[i];
    }   
  printf("%f",result);
}
