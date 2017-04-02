#include<stdio.h>
void read(int[][10],int,int);
void print(int[][10],int,int);
void transpose(int[][10],int,int);
void sumdiagelement(int[][10],int,int);
void  uppertrangular(int[][10],int,int);
void house(int[][10],int,int);
int main()
{
  int a[10][10],row,col;
  printf("enter row &column\n");
  scanf("%d%d",&row,&col);
  printf("enter matrics value\n");  
  read(a,row,col);
  printf("\n");
  printf("matrics elements are\n");
  print(a,row,col);
  printf("\n");
  printf("transpose of a matrics is\n");
  transpose(a,row,col);
  printf("\n");
  printf("sum of diagonal elements is\n");
  sumdiagelement(a,row,col);
  printf("\n");
  printf("upper trangular matrics is\n");
  uppertrangular(a,row,col);
  printf("\n");
  house(a,row,col);
  printf("\n");
}
void read(int a[][10],int row,int col)
{
  int i,j;
  for(i=0;i<row;i++)
    {
      for(j=0;j<col;j++)
	{
	  scanf("%d",&a[i][j]);
	}
    }
}
void print(int t[][10],int row,int col)
{
  int i,j;
  for(i=0;i<row;i++)
    {
      for(j=0;j<col;j++)
	{
	  printf("\t%d",t[i][j]);
	}
      printf("\n");
    }
}
void transpose(int a[][10],int row,int col)
{
  int i,j;
  int t[10][10];
  for(i=0;i<row;i++)
    {
      for(j=0;j<col;j++)
	{
	  t[i][j]=a[j][i];
	  printf("\t%d",t[i][j]);
	 }
      printf("\n");
    }
  }
void sumdiagelement(int a[][10],int row,int col)
{
  int sum=0;
  int i,j;
  for(i=0;i<row;i++)
    sum=sum+a[i][i];
  printf("\t%d",sum);
  printf("\n");
}
void uppertrangular(int a[][10],int row,int col)
{
  int i,j;
  int t[10][10];
  for(i=0;i<row;i++)
    for(j=0;j<col;j++)
      if(i<=j)
	t[i][j]=a[j][i];
      else
	t[i][j]=0;
  for(i=0;i<row;i++)
    {
      for(j=0;j<col;j++)
	{
	  printf("\t%d",t[i][j]);
	}
  printf("\n");
    }
}
  
void house(int a[][10],int row,int col)
{
  int k,l,m;
  for(m=0;m<row;m++)
    {
   for(k=0;k<col;k++)
       { 
         for(l=k;l<=k;l++)
          {
             printf("%d",a[k][l]);
          }
         printf("\n");
      }
 printf("\n");
    }
  printf("\n");
}
