#include<stdio.h>
#include<stdlib.h>
#include<math.h>

float subs(float xis[],float arrexp[][10],int cntun,int n)
{
  int i,j,y,k;
  float tmp;
  for(k=0;k<n;k++)
    {
  for(i=0;i<cntun;i++)
    {
      for(j=0,y=0;j<cntun;j++)
	{
          if(i==j)
	    {
              tmp=1/arrexp[i][j];
              printf("tmp=%f",tmp);
              y++;  
	    }
          if(i!=j)
	    {
              xis[i]+=(-1)*arrexp[i][j]*xis[y];
              y++;
	    }
	}
          xis[i]+=arrexp[i][cntun];
          xis[i]=xis[i]*tmp; 
      printf("\nthe value of x%d is %f\n",i,xis[i]);
    }
    }
}

int main()
{
  int cntun,i,j,n;
  float xis[10]={0};
  float arrexp[10][10];

  printf("Enter the number of unknowns\n");
  scanf("%d",&cntun);

  printf("Enter the number of iteraations\n");
  scanf("%d",&n);

  for(i=0;i<cntun;i++)
    {
      printf("Enter the coefficients of the %d expr:\n",i);
      for(j=0;j<cntun+1;j++)
	{
          scanf("%f",&arrexp[i][j]);  
	}
    }
  subs(xis,arrexp,cntun,n);  
}
