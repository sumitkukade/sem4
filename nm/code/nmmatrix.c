#include<stdio.h>
#include<math.h>

int m[10][10],col[10][10],iden[10][10],r,c; 

void matrixmul(int a[10][10],int b[10][10])
{
  int i,j,k,ml[10][10];
  for(i=0;i<r;i++)
    {
      for(j=0;j<c;j++)
	{
	  ml[i][j]=0;
	  for(k=0;k<r;k++)
	    ml[i][j]=ml[i][j]+a[i][k]*b[k][j];
	}
    }
}

void matranspose(int a[10][10])
{
  int b[10][10],i,j;
  for(i=0;i<r;i++)
    {
      for(j=0;j<c;j++)
	b[j][i]=a[i][j];
    }
}

void colret(int cl)
{
  int i,j;
  for(i=0;i<r;i++)
    {
      for(j=0;j<1;j++)
	col[i][j]=m[i][cl-1];
    }
}

void geniden()
{
  int i,j;
  for(i=0;i<r;i++)
      iden[i][i]=1;
}

void display(int mat[10][10])
{
  int i,j;
  printf("the array elements are:\n");
  for(i=0;i<r;i++)
    {
      for(j=0;j<c;j++)
	printf("%d\t",mat[i][j]);
      printf("\n");
    }
}

int calalpha()
{
  float alpha=0;
  int i;
  for(i=0;i<r;i++)
    alpha=alpha+(col[i][0]*col[i][0]);
  printf("\nalpha=%f\n",sqrt(alpha));
  return (sqrt(alpha));
}



main()
{
  float alph;
  int i,j;
  printf("Enter number of rows and columns:\n");
  scanf("%d %d",&r,&c);
  printf("Enter array elements:\n");
  for(i=0;i<r;i++)
    {
      for(j=0;j<c;j++)
	scanf("%d",&m[i][j]);
    }
  display(m);
  colret(3);
  display(col);
  geniden();
  display(iden);
  alph=calalpha();
}

