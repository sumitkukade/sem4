#include<stdio.h>
#include<math.h>
#include<stdlib.h>
struct answer
{
  float c[20];
  float c1[20];
  float a[50][50];
  
};



float **givan(int n,int p,int q,int k,float ** mat)
{

  int i=0,j=0,z=0;
  float r=0,cos=0,sin=0,a=0,b=0;
  float **I=NULL, **ans;

 //  struct answer *temp;

 
 I=(float **)malloc(sizeof(float *)*100);
 for(i=0;i<10;i++)
   I[i]=(float *)malloc(sizeof(float)*100);

 ans=(float **)malloc(sizeof(float *)*100);
 for(i=0;i<10;i++)
   ans[i]=(float *)malloc(sizeof(float)*100);
 

 



 printf("n:%d\tq:%d\tk:%d\n",n,q,k);


 a=mat[p][k];
 b=mat[q][k];

 r=pow((pow(a,2)+pow(b,2)),0.5);

 printf("a is:%f\tb is: %f\tr is:%f\n",a,b,r);

 cos=a/r;
 sin=-(b/r);

 printf("cos:%f\tsin:%f\n",cos,sin);

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


  I[q][p]=sin;
  I[q][q]=cos;
	
  /*I[p][q]=-sin;
   I[p][p]=cos;

 /* I[q][q-1]=sin;
  I[q][q]=cos;
  
  I[q-1][q-1]=cos;
  I[q-1][q]=-sin;
*/


  printf("==================I======================\n");

for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
      {
	printf("%f\t",I[i][j]);
      }
    printf("\n");
  }


 printf("==================mat======================\n"); 

for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
      {
	printf("%f\t",mat[i][j]);
      }
    printf("\n");
  }







/*
  for(i=0;i<n;i++)
    {
      for(z=0;z<n;z++)
	{
	  for(j=0;j<n;j++)
	    {
	      ans[i][z]=(I[i][j]*mat[z][j])+ans[i][z];
	    }
	}
    }

*/


for(i=0;i<n;i++)
    {
      for(z=0;z<n;z++)
	{
	  for(j=0;j<n;j++)
	    {
		//printf("aaaaaaaaaaaaa:ans:%d\tI:%d\tmat:%d\n",ans[i][z],I[i][j],mat[j][z]);
	      ans[i][z]=(I[i][j]*mat[j][z])+ans[i][z];
		//printf("bbbbbbbbbbbbbbbbbb:ans:%d\tI:%d\tmat:%d\n",ans[i][z],I[i][j],mat[j][z]);
	    }
	}
    }





  printf("\n======================Ans=============================\n");

for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
      {
	printf("%f\t",ans[i][j]);
      }
    printf("\n");
  }

//printf("Element:%f\n",ans[1][3]);

 printf("\n===========================C & C1========================\n");

/*
 for(i=0;i<n;i++)
   {
     // printf("c:%f\t",I[i][p]);
     //printf("c1:%f\n",I[i][q]);
      temp->c[i]=I[i][p];
      temp->c1[i]=I[i][q];
   }

for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
      {
	temp->a[i][j]=ans[i][j];
	//printf("%f\t",I[i][j]);
      }
    // printf("\n");
  }

  printf("\n======================Ans=============================\n");

/*for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
      {
	printf("%f\t",temp->a[i][j]);
      }
    printf("\n");
  }

*/

 return ans;
}


int main()
{
    float **mat=NULL,**ans1=NULL,**temp=NULL;
    int i,j,k,p,q,n,b,x,y,z;
    //struct answer *ans;
    int add;

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

/* printf("Enter the p and position q and k value\n");
 scanf("%d%d%d",&p,&q,&k);

 a=givan(n,p,q,k,mat);
*/






      



 x=2;
 z=0;
 for(j=0;j<(n-2);j++)
   {
     
     for(i=x;i<n;i++)
       {
       ans1=givan(n,(i-1),i,j,mat);
	 
        for(b=0;b<n;b++)
	   {
	     for(y=0;y<n;y++)
	       {
		 mat[b][y]=ans1[b][y];
	       }
	   }
       }
     x++;
     z++;
     if(x==n)
       break;

   }







 

  /* ans1=givan(n,0,2,0,mat);
	 
 for(b=0;b<n;b++)
   {
     for(y=0;y<n;y++)
       {
	 temp[b][y]=ans1[b][y];
		 //printf("elt:%f\t",ans->a[b][y]);
       }
	     //printf("\n");
     }

	ans1=givan(n,0,3,0,temp);
*/
/*
 for(b=0;b<n;b++)
   {
     for(y=0;y<n;y++)
       {
	 temp[y][b]=ans1[b][y];
		 //printf("elt:%f\t",ans->a[b][y]);
       }
	     //printf("\n");
     }

	ans1=givan(n,0,3,0,temp);



    /*  	  for(b=0;b<n;b++)
	   {
	     for(y=0;y<n;y++)
	       {
		 mat[b][y]=ans->a[b][y];
		 //printf("elt:%f\t",ans->a[b][y]);
	       }
	     //printf("\n");
	     }
	 //printf("element:%f\n",ans->a[1][3]);   

    //printf("add=%d\n",(int)(ans->a));
    
    
 	 for(b=0;b<n;b++)
	   {
	     for(y=0;y<n;y++)
	       {
		 printf("orignal:%f\t",mat[b][y]);
	       }
	     printf("\n");
	     }




	 ans=givan(n,0,3,0,mat);
	 
	 for(b=0;b<n;b++)
	   {
	     for(y=0;y<n;y++)
	       {
		 mat[y][b]=ans->a[b][y];
	       }
	   }
	 
	 ans=givan(n,1,3,1,mat);

 
    */


 for(b=0;b<n;b++)
   {
     for(y=0;y<n;y++)
       {
	 printf("ans:%f\t",ans1[b][y]);
       }
     printf("\n");
   }





	 
 // ans=givan(n,0,3,0,mat);



/*
for(i=0;i<n;i++)
   {
      printf("c:%f\t",ans->c[i]);
     printf("c1:%f\n",ans->c1[i]);
     //   temp->c[i]=I[i][p];
     // temp->c1[i]=I[i][q];
   }
 */

}
