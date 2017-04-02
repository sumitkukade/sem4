#include<stdio.h>

void add(int[][10],int b[][10],int c[][10],int,int);
void mul(int[][10],int b[][10],int c[][10],int,int);
void read(int[][10],int,int);
void print(int[][10],int,int);

int main()
{
  int a[10][10],b[10][10],c[10][10];
  int m,n;
  printf("enter the of row & column\n");
  scanf("%d%d",&m,&n);
  printf(" enter first matrics element \n");
  read(a,m,n);
  printf("enter second matrics element \n");
  read(b,m,n);
  printf("first matrics  is\n");
  print(a,m,n);
  printf("second matrics  is\n");
  print(b,m,n);
  printf("addition of matrics is\n");
  add(a,b,c,m,n);
  print(c,m,n);
  printf("multiplication of matrics is\n");
  mul(a,b,c,m,n);
  print(c,m,n);
}

void add(int a[][10],int b[][10],int c[][10],int m,int n)
{
  int i,j;
  for(i=0;i<m;i++)
    {
      for(j=0;j<n;j++)
	{
	  c[i][j]=a[i][j]+b[i][j];
	 }
      printf("\n");
    }
}

void mul(int a[][10],int b[][10],int c[][10],int m,int n)
{
  int i,j,k;
  for(i=0;i<m;i++)
    {
      for(j=0;j<n;j++)
	{
	  c[i][j]=0;
	  for(k=0;k<m;k++)
	    {

	      c[i][j]=c[i][j]+a[i][k]*b[k][j];
	    }
	  printf("\n");
	}
    }
void read(int a[][10],int m,int n)
{
  int i,j;
  for(i=0;i<m;i++)
    {
      for(j=0;j<n;j++)
	{
	  scanf("%d",&a[i][j]);
	}
    }
}
void print(int b[][10],int m,int n)
{
  int i,j;
  for(i=0;i<m;i++)
    {
      for(j=0;j<n;j++)
	{
	  printf("%d\t",b[i][j]);
	}
      printf("\n");
    }
}
