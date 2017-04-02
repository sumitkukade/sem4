#include<stdio.h>
#include<math.h>
#include<stdlib.h>

struct answer
{
  float c[20];
  float c1[20];
  float a[50];
};

struct answer * givan(int n,int p,int q,int k,float * mat)
 {

  
   int a,b,i,j,z;
   float r,cos,sin;

   struct answer *temp;

   temp=(struct answer *)malloc(sizeof(struct answer)*10);
  
  



    float *I=NULL,*ans;
    I=(float *)malloc(sizeof(float)*100);
    ans=(float *)malloc(sizeof(float)*100);
   

    printf("p:%d\tq:%d\tk:%d\n",p,q,k);
   
 a=mat[(p*n)+k];
 b=mat[(q*n)+k];

 r=pow((pow(a,2)+pow(b,2)),0.5);

 printf("a is:%d\tb is: %d\tr is:%f\n",a,b,r);
 
 cos=a;///r;
 sin=-(b);///r);

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


  for(i=1;i<=(n*n);i++)
  {
    printf("%f\t",I[i-1]);
    if(i%n==0)
      printf("\n");

  }



 int x;
 z=0; 
 i=0;
     for(x=0;x<n;x++)
       {
	 z=0;
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
	 
	 
	 
       }

     printf("\n----------------\n");


     /*j=0;
     for(i=1;i<=(n*n);i++)
       {
	 if(j%n==0)
	   {
	 printf("\n");
	   printf("%f\t",ans[i-1]);
	   }
	 if(j%n!=0)
	   {
	     printf("%f\t",ans[i-1]);
	   }
	 j++;
	
	 }*/


     
     for(i=0;i<(n*n);i++)
       {

	 temp->a[i]=ans[i];
	 printf("%f\n",ans[i-1]);
	 if(i%n==0)
	  printf("\n\n");
       }


     
   for(i=0;i<n;i++)
   {
     //printf("C :%f\t c1:%f\n",I[(i*n)+p],I[(i*n)+q]);
     temp->c[i]=I[(i*n)+p];
     temp->c1[i]=I[(i*n)+q];
   }
    return temp;

}



int main()
{
  
  
 float *mat=NULL;
 int a,b,i,j,n,p,q,z,k;
 float r,cos,sin;
 struct answer *ans;
printf("Enter how many element in matrix\n");
 scanf("%d",&n);
 
 mat=(float *)malloc(sizeof(float)*100);
 
 
   printf("Enter Matrix\n");
   
 for(i=0;i<(n*n);i++)
   {
     scanf("%f",&mat[i]);
   }
 


 
  printf("Enter the p and position q and k value\n");
 scanf("%d%d%d",&p,&q,&k);

 ans=givan(n,p,q,k,mat);
 

 /*

 a=2;
 for(j=0;j<(n-2);j++)
   {
     
     for(i=a;i<n;i++)
       {
	 ans=givan(n,0,i,j,mat);
	 for(b=0;b<n*n;b++)
	   {
	     mat[b]=ans->a[b];
	   }
       }
     a++;
     
     if(a==n)
       break;

   }
 */
 
 printf("------------------------------\n");  
  for(i=1;i<=(n*n);i++)
       {

	 // temp->a[i]=ans[i];
	  printf("%f\n",ans->a[i-1]);
	 if(i%n==0)
	  printf("\n\n");
       }



  /*printf("\n");
 for(i=0;i<n;i++)
   {
           
	 printf("c is:%f\t c1 is:%f\n",ans->c[i],ans->c1[i]);
	 }*/

}




