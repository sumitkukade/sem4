#include<stdio.h>
#include<stdlib.h>
#include<math.h>


int main()
{
  float x[10],fx[10],result,value,tmp,tmp1;
  int cnt,i,j,k;
  printf("Enter the number of values for x\n");
  scanf("%d",&cnt);
  printf("\nEnter the values for x and fx:\n");
  for(i=0;i<cnt;i++)
    {
      scanf("%f",&x[i]);
      scanf("%f",&fx[i]);
    }
  printf("\nEnter the value of x for which you want fx?");
  scanf("%f",&value);
  
  result=0;
  for(i=0;i<cnt;i++)
    {
      tmp=tmp1=1; 
      for(j=0;j<cnt;j++)
	{
	  k=j;  
	  if(i!=j)
            tmp*=(value-x[j]);
          if(i==j)
	    {
	      for(k=0;k<cnt;k++)
	      {
                if(i!=k)
		  {
                    tmp1*=x[i]-x[k];
                    //printf("\n%f\n",tmp1);
		  }
	      }
            }  
          
	}
      result+=(tmp/tmp1)*fx[i];
      //printf("\nthe result is %f",result);
    }
  
  printf("\nthe result is %f",result);  
 
}
