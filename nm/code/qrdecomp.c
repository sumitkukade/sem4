#include<stdio.h>
#include<stdlib.h>
#include<math.h>

float g1t[10][10];
float g2t[10][10];

float* transpose(float g1[][10],int row,int col,float g1t[][10])
{
  int i,j;
  //float g1t[10][10];
  for(i=0;i<row;i++)
    for(j=0;j<col;j++)
      g1t[i][j]=g1[j][i];
  return *g1t;
  
}

int main()
{
  float array[10][10],Q[10][10],R[10][10],g1[10][10],g2[10][10],r,c,a,b,s,A1[10][10];
  float A2[10][10],sum=0;
  //float *gt,*gt1;
  int i,j,row,col,cnt,k=0,arrindex[10],l,m;
  
  printf("Enter number of rows\n");
  scanf("%d",&row);  

  printf("Enter number of cols\n");
  scanf("%d",&col);

  printf("Enter the elements of the matrix X:\n");
  for(i=0;i<row;i++)
    {
      for(j=0;j<col;j++)
	scanf("%f",&array[i][j]);
    }

  
  for(i=0;i<row;i++)
    {
      for(j=0;j<col;j++)
	{
	  if(i>j)
	    {
              if(array[i][j]!=0)
		{
		  cnt++;
                  arrindex[k]=i;
                  k++;
                  arrindex[k]=j;
                  k++;
		}
	    }
	}
    }
  for(i=0;i<k;i++)
    {
      printf("%d::",arrindex[i]);
    }
  b=array[arrindex[0]][arrindex[1]];
  a=array[arrindex[0]-1][arrindex[1]];
  r=sqrt((a*a)+(b*b));
  //printf("a is %f: b is %f r is %f\n",a,b,r);

  c=a/r;
  s=-b/r;
  printf("c is %f s is %f\n",c,s);
  
  for(i=0;i<row;i++)
    {
      for(j=0;j<col;j++)
	{
          if(i==arrindex[0] && j==arrindex[1])
	    {
              g1[i][j]=s;
              g1[i-1][j]=c;
              g1[i][j+1]=c;
              g1[i-1][j+1]=-s;
	      k=j+1;
              l=i;
	    }
	  else if(i==j && j!=k)
	    {
              g1[i][j]=1;
	    }
          else
	    {
              if(j!=k && l!=i)
                g1[i][j]=0;
	    }
	}
    }  

   for(i=0;i<row;i++)
    {
      for(j=0;j<col;j++)
	{
	  printf("%f\t",g1[i][j]);
	}
      printf("\n");
    }
   
   for(i=0;i<row;i++)
     {
       for(j=0;j<col;j++)
	 {          
           A1[i][j]=0;
           for(m=0;m<col;m++)
	     {
               A1[i][j]+=g1[i][m]*array[m][j];
	     }
           
	 }
     }

   printf("A1=\n");
    for(i=0;i<row;i++)
    {
      for(j=0;j<col;j++)
	{
	  printf("%f\t",A1[i][j]);
	}
      printf("\n");
    }
    printf("\n"); 

  b=A1[arrindex[2]][arrindex[3]];
  a=A1[arrindex[2]-1][arrindex[3]];
  r=sqrt((a*a)+(b*b));
  c=a/r;
  s=-b/r;
  printf("r is %f c is %f s is %f\n",r,c,s);

  for(i=0;i<row;i++)
    {
      for(j=0;j<col;j++)
	{
          if(i==arrindex[2] && j==arrindex[3])
	    {
              g2[i][j]=s;
              g2[i-1][j]=c;
              g2[i][j+1]=c;
              g2[i-1][j+1]=-s;
	      k=j+1;
              l=i;
	    }
	  else if(i==j && j!=k)
	    {
              g2[i][j]=1;
	    }
          else
	    {
              if(j!=k && l!=i)
                g2[i][j]=0;
	    }
	}
    }  


  for(i=0;i<row;i++)
    {
      for(j=0;j<col;j++)
	{
	  printf("%f\t",g2[i][j]);
	}
      printf("\n");
    }
   
   for(i=0;i<row;i++)
     {
       for(j=0;j<col;j++)
	 {          
           A2[i][j]=0;
           for(m=0;m<col;m++)
	     {
               A2[i][j]+=g2[i][m]*A1[m][j];
	     }
           
	 }
     }

   printf("A2=\n");
    for(i=0;i<row;i++)
    {
      for(j=0;j<col;j++)
	{
	  printf("%f\t",A2[i][j]);
	}
      printf("\n");
    }
  
    transpose(g1,row,col,g1t);
    for(i=0;i<row;i++)
      {
        for(j=0;j<col;j++)
	  printf("%f\t",g1t[i][j]);
	printf("\n");
      }
  transpose(g2,row,col,g2t);

   for(i=0;i<row;i++)
     {
       for(j=0;j<col;j++)
	 {          
           Q[i][j]=0;
           for(m=0;m<col;m++)
	     {
               Q[i][j]+=g1t[i][m]*g2t[m][j];
	     }
           
	 }
     }

   printf("Q=\n");
    for(i=0;i<row;i++)
    {
      for(j=0;j<col;j++)
	{
	  printf("%f\t",Q[i][j]);
	}
      printf("\n");
    }
  
    
}
