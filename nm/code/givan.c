#include<stdio.h>
#include<math.h>
#include<stdlib.h>

struct asnwer
{
  float c[10];
  float c2[10];
};


int main()
{
  int *mat=NULL;
  float *I=NULL, *ans;

  int a,b,i,j,n,p,q,z;
 float r,cos,sin;

 
 mat=(int *)malloc(sizeof(int)*10);
 
 printf("Enter how many element in matrix\n");
 scanf("%d",&n);

printf("Enter Matrix\n");

 for(i=0;i<(n*n);i++)
  {
    scanf("%d",&mat[i]);
  }

 printf("Enter the p and q value\n");
 scanf("%d%d",&p,&q);

 givan(n,p,q,mat);
}





int givan(int n,int p,int q,float *mat)
 {

   int a,b,i,j,z;
 float r,cos,sin;
 float *I=NULL,*ans;
 I=(float *)malloc(sizeof(float)*10);
 ans=(float *)malloc(sizeof(float)*10);
   
   struct answer * temp;



   for(i=0;i<n*n;i++)
     printf("mat is:%f\n",*mat[i]);
   
 a=mat[(p*n)+q];
 b=mat[(q*n)+q];

 r=pow((pow(a,2)+pow(b,2)),0.5);

 printf("a is:%d\tb is: %d\tr is:%f\n",a,b,r);
 
 cos=a/r;
 sin=-(b/r);

 printf("cos:%f\tsin:%f\n",cos,sin);

 for(i=0;i<(n*n);i++)
    {
      	  I[i]=0;
    }

  for(i=0;i<n;i++)
    {
      I[(i*n)+i]=1;
    }




  I[(q*n)+p]=sin;
  I[(q*n)+q]=cos;


  for(i=0;i<(n*n);i++)
  {
    printf("%f\t",I[i]);
    

  }



 int x;
 z=0; 
 i=0;
     for(x=0;x<n;x++)
       {
	 while(z!=(n*n))
	   {
	     for(j=(x*n);j<(n*(x+1));j++)
	       {
		 ans[i]=(I[z]*mat[j])+ans[i];
		 z++;
	       }
	     // printf("\nans :%f\t iiii:%d\t zzzz:%d\n",ans[i],i,z);
	     i++;
	   }
	 z=0;
	 
	 
       }

     printf("\n----------------\n");



     for(i=0;i<(n*n);i++)
       {
	 printf("%f\t",ans[i]);
	 
       }
     
     /* for(i=0;i<n;i++)
   {
     temp.c[i]=I[(i*n)+p];
     temp.c1[i]=I[(i*n)+q];
   }
   return temp;*/

}
