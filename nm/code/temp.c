#include<stdio.h>
int main()
{

  int i,j,k,nrow,ncol,l[20][20],ans1[20][20];
double ans[20][20];
  printf("Enter the how may rows to enter");
  scanf("%d",&nrow);
  //  printf("Enter the how many columns to enter");
  //scanf("%d",&ncol);
  ncol=nrow;
  printf("Enter the Matrix");

  for(i=0;i<nrow;i++)
    {
      for(j=0;j<ncol;j++)
	{
	  scanf("%d",&l[i][j]);
	}
    }

 for(i=0;i<nrow;i++)
    {
      for(j=0;j<ncol;j++)
	{
	  scanf("%d",&ans1[i][j]);
	}
    }

      
  for(k=0;k<nrow;k++)
    {
      for(i=0;i<nrow;i++)
	{
	  for(j=0;j<nrow;j++)
	    {
	      ans[k][i]=(ans1[k][j]*l[i][j])+ans[k][i];
	    }
	}
    }



 for(i=0;i<nrow;i++)
    {
      for(j=0;j<ncol;j++)
	{
	  printf("ans:%d,%d::%f\t",i,j,ans[i][j]);
	}
	printf("\n");
    }

}
