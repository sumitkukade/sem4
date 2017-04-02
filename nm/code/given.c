#include<stdio.h>
#include<math.h>
float a[10][10],b[10][10],id[10][10],g1[10][10],A[10][10];
int read(int row,int col,float a[][10])
{
  int i,j;
  printf("enter matrics elements\n");
  for(i=0;i<row;i++)
    {
      for(j=0;j<col;j++)
	{
	  scanf("%f",&a[i][j]);
	}
    }
}

int print(int row,int col,float a[][10])
{
  int i,j;
  for(i=0;i<row;i++)
    {
      for(j=0;j<col;j++)
	{
	  printf("\t%f",a[i][j]);
	}
      printf("\n");
    }
}
int iden(int row,int col)
{
  int i,j;
  
    {
      for(i=0;i<row;i++)
	{
	  for(j=0;j<col;j++)
	    {
	      if(i==j)
		{
		  id[i][j]=1; 
		}
	      else
		id[i][j]=0;
	    }
	}
    }
}


int findj(int row,int col,float a[10][10])
{
  int i,j;
  
  {
    for(i=0;i<row;i++)
      {
	for(j=0;j<col;j++)
	  {
	    if(i>j && i!=j)
	      {
		if(abs(a[i][j])!=0 )
		    printf("%f\n",a[i][j]);
		  return j;
		
		}
	  }
      }
  }
}




int findi(int row,int col,float a[][10])
{
  int i,j;
  
  {
    for(i=0;i<row;i++)
      {
	for(j=0;j<col;j++)
	  {
	    if(i>j)
	    {
	      if(abs(a[i][j])!=0)
		printf("%f\n",a[i][j]);
	         return i;
		
	      }
	  }
      }
  }
}
float G1(int row,int col,int i1,int j1)
{
  int i,j,c,s,r;
 
  for(i=0;i<row;i++)
      {
	for(j=0;j<col;j++)
	  {
	    if(i==i1 && j==j1)
	      {
		id[i][j]=-a[i][j]/(sqrt(pow(a[i-1][j],2)+pow(a[i][j],2)));//-s
		id[i-1][j]=a[i-1][j]/(sqrt(pow(a[i-1][j],2)+pow(a[i][j],2)));//c
		id[i-1][j+1]=a[i][j]/(sqrt(pow(a[i-1][j],2)+pow(a[i][j],2)));//--s
		id[i][j+1]=a[i-1][j]/(sqrt(pow(a[i-1][j],2)+pow(a[i][j],2)));//c
				
	      }
	  }
      }
 
}
float G11(int row,int col)
{

  int i,j,k;
  for(i=0;i<row;i++)
    {
      for(j=0;j<col;j++)
	{
	  b[i][j]=0;
	  {
	    for(k=0;k<row;k++)
	      {
		b[i][j]=b[i][j]+id[i][k]*a[k][j];
	      }
	  }
	}
    }
 

}  

int main()
{
  int row,col,i1,j1,i2,j2;
  printf("enter how many row & columns\n");
  scanf("%d%d",&row,&col);
  read(row,col,a);
  printf("\nmatrics element is\n");
  print(row,col,a);
  iden(row,col);
  printf("\nidentity element is\n");
  print(row,col,id);
  i1=findi(row,col,a);
  j1=findj(row,col,a);
  printf("\ni=%d\n",i1);
  printf("j=%d\n",j1);
  G1(row,col,i1,j1);
  print(row,col,id);
  printf("First given rotation\n");
  G11(row,col); 
  print(row,col,b);
  printf("**************\n");  
i2=findi(row,col,b);
j2=findi(row,col,b);
printf("\ni=%d\n",i2);
printf("\nj=%d\n",j2);
}

