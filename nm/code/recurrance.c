#include<stdio.h>
#include<stdlib.h>
#include<math.h>

float** recurrance(int num,float* coeff)
{
  float *f2,**fis,*q,*rem;
  int i=0,flag=0,j=0;
  f2=derivative(num,coeff);
  *fis[i]=calc(coeff,f2,num,rem);
  i++;
  f2=derivative(num-i,f2);
  *fis[i]=calc(f2,*fis[i],num-i,rem);
  for(j=0;j<num-i;j++)
    {
      if(f2[j]!=0)
	{
          flag=1;
          break;
	}
    }
  if(flag==0)
    {
      retutn **fis;
    }
  i++;
  while(1)
    {
      f2=derivative(num-i,*fis[i]);
    }
}
