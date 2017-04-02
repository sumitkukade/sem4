#include<stdio.h>
#include<math.h>
#include<stdlib.h>
struct answer
{
  float Q[50][50];
  float R[50][50];
  
};





struct answer *givan(int n,int p,int q,int k,float ** mat)
{

  int i=0,j=0,z=0;
  float r=0,cos=0,sin=0,a=0,b=0;
  float **I=NULL, **ans;

  struct answer *temp;

 
 I=(float **)malloc(sizeof(float *)*100);
 for(i=0;i<10;i++)
   I[i]=(float *)malloc(sizeof(float)*100);

 ans=(float **)malloc(sizeof(float *)*100);
 for(i=0;i<10;i++)
   ans[i]=(float *)malloc(sizeof(float)*100);
 

 



 //printf("n:%d\tq:%d\tk:%d\n",n,q,k);


 a=mat[k][k];
 b=mat[q][k];

 r=pow((pow(a,2)+pow(b,2)),0.5);

 // printf("a is:%f\tb is: %f\tr is:%f\n",a,b,r);

 cos=a/r;
 sin=-(b/r);

 //printf("cos:%f\tsin:%f\n",cos,sin);

  for(i=0;i<n;i++)
    {
      for(j=0;j<n;j++)
	{
	  if(i==j)
	    {
	      I[i][j]=1;
	    }
	  else
	    {
	      I[i][j]=0;
	    }
	}
    }


  I[q][k]=sin;
  I[q][q]=cos;
	
  I[k][q]=-sin;
  I[k][k]=cos;

  
  
 /* I[q][q-1]=sin;
  I[q][q]=cos;
  
  I[q-1][q-1]=cos;
  I[q-1][q]=-sin;

 */

  /*  printf("==================I======================\n");

for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
      {
	printf("%f\t",I[i][j]);
      }
    printf("\n");
  }

/*
 printf("==================mat======================\n"); 

for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
      {
	printf("%f\t",mat[i][j]);
      }
    printf("\n");
  }
*/

  




for(i=0;i<n;i++)
    {
      for(z=0;z<n;z++)
	{
	  for(j=0;j<n;j++)
	    {
	      ans[i][z]=(I[i][j]*mat[j][z])+ans[i][z];
	      
	    }
	}
    }




/*
  printf("\n======================Ans=============================\n");

for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
      {
	printf("%f\t",ans[i][j]);
      }
    printf("\n");
  }
*/


// printf("\n===========================C & C1========================\n");

for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
      {
	temp->R[i][j]=ans[i][j];
	temp->Q[i][j]=I[i][j];
	//printf("%f\t",temp->a[i][j]);
      }
    //printf("\n");
  }



 return temp;
}


int main()
{
  float **mat=NULL,**ans1=NULL,**temp=NULL,**tempQ=NULL,**Q=NULL,**ansQ;
  int i,j,k,p,q,n,b,x,y,z,ii,jj;
    struct answer *ans;
    int add;

    ans=(struct answer*)malloc(sizeof(struct answer)*50);

    ansQ=(float **)malloc(sizeof(float *)*50);
    for(i=0;i<10;i++)
      ansQ[i]=(float *)malloc(sizeof(float)*50);


    Q=(float **)malloc(sizeof(float *)*50);
    for(i=0;i<10;i++)
      Q[i]=(float *)malloc(sizeof(float)*50);

    tempQ=(float **)malloc(sizeof(float *)*50);
    for(i=0;i<10;i++)
      tempQ[i]=(float *)malloc(sizeof(float)*50);

	
    temp=(float **)malloc(sizeof(float *)*50);
    for(i=0;i<10;i++)
      temp[i]=(float *)malloc(sizeof(float)*50);
    
    
    ans1=(float **)malloc(sizeof(float *)*50);
    for(i=0;i<10;i++)
      ans1[i]=(float *)malloc(sizeof(float)*50);

mat=(float **)malloc(sizeof(float *)*100);
for(i=0;i<10;i++)
  mat[i]=(float *)malloc(sizeof(float)*100);


 printf("enter the how many elements in matrix\n");
 scanf("%d",&n);

printf("Enter Matrix\n");

for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
      {
	scanf("%f",&mat[i][j]);
      }
  }

/*printf("Enter the p and position q and k value\n");
 scanf("%d%d",&q,&k);

 givan(n,(q-1),q,k,mat);
*/
/*ans1=givan(n,0,1,0,mat);
   ans1=givan(n,1,2,0,ans1);
 
 givan(n,1,2,1,ans1);


*/
 


 for(i=0;i<n;i++)
   {
     for(j=0;j<n;j++)
       {
	 if(i==j)
	   {
	     Q[i][j]=1;
	   }
	 else
	   {
	     Q[i][j]=0;
	   }
       }
   }




 x=1;
 z=0;
 for(j=0;j<(n-1);j++)
   {
     
     for(i=x;i<n;i++)
       {
	  ans=givan(n,(i-1),i,j,mat);
	 
        for(b=0;b<n;b++)
	   {
	     for(y=0;y<n;y++)
	       {
		 mat[b][y]=ans->R[b][y];
	       }
	   }
	/*printf("--------------------------------------------------\n");

	for(b=0;b<n;b++)
	  {
	    for(y=0;y<n;y++)
	      {
		
		printf("ANS Q is:%f\t",ans->Q[b][y]);
	      }
	    printf("\n");
	  }
	*/
	for(b=0;b<n;b++)
	  {
	    for(y=0;y<n;y++)
	      {
		tempQ[b][y]=ans->Q[y][b];
	      }
	    
	  }
	/*
	printf("--------------------------------------------------\n");

	for(b=0;b<n;b++)
	  {
	    for(y=0;y<n;y++)
	      {
		//Q[b][y]=ans->Q[b][y];
		printf("temp Q is:%f\t",tempQ[b][y]);
	      }
	    printf("\n");
	  }
	

	for(b=0;b<n;b++)
	  {
	    for(y=0;y<n;y++)
	      {
		//Q[b][y]=ans->Q[b][y];
		printf("Q is:%f\t",Q[b][y]);
	      }
	    printf("\n");
	  }
	*/

	for(b=0;b<n;b++)
	  {
	    for(y=0;y<n;y++)
	      {
		ansQ[b][y]=0;
	      }
	    
	  }

	



	
	
	for(ii=0;ii<n;ii++)
	  {
	    for(z=0;z<n;z++)
	      {
		for(jj=0;jj<n;jj++)
		  {
		    ansQ[ii][z]=(Q[ii][jj]*tempQ[jj][z])+ansQ[ii][z];
		    
		  }
	      }
	  }

	
	

	for(b=0;b<n;b++)
	  {
	    for(y=0;y<n;y++)
	      {
		Q[b][y]=ansQ[b][y];
		//printf("main Q is:%f\t",Q[b][y]);
	      }
	    //printf("\n");
	  }
	

	


	/*
	for(b=0;b<n;b++)
	  {
	    for(y=0;y<n;y++)
	      {
		//Q[b][y]=ans->Q[b][y];
		printf("main Q is:%f\t",Q[b][y]);
	      }
	    printf("\n");
	  }
	*/
	

       }
     x++;
     z++;
     if(x==n)
       break;

   }


 
 	



	
 for(b=0;b<n;b++)
   {
     for(y=0;y<n;y++)
       {
	 //Q[b][y]=ans->Q[b][y];
	 printf(" Q is:%f\t",Q[b][y]);
       }
     printf("\n");
   }

printf("========================================================\n");

 for(b=0;b<n;b++)
   {
     for(y=0;y<n;y++)
       {
	 //Q[b][y]=ans->Q[b][y];
	 printf(" R is:%f\t",ans->R[b][y]);
       }
     printf("\n");
   }

printf("========================================================\n");
 




}
