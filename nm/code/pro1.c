#include<stdio.h>
#include<math.h>




void main()
{
  int nr,i,j;
  float temp[20][20],AA[20][20],AAA[20][20];
  
  printf("Enter the how may rows & coumes to enter");
  scanf("\t%d",&nr);
  
//  printf("Enter the how many columns to enter");
  //scanf("%d",&ncol);
  
  printf("Enter the Matrix");

  for(i=0;i<nr;i++)
    {
      for(j=0;j<nr;j++)
	{
	  scanf("%f",&AA[i][j]);
	}
    }


  H_A(nr,AA,AA,0);







}
int cnt=0;

int H_A(int n,float A[20][20],float newmat[20][20],int cnt1)
{

  int k,z,j,i,nrow,ncol,rno,cno,p=0,q=0;
  float UTRANCE_U=0,TEMP,l[20][20],ans[20][20],U[20][20],E[20][20],alpha[20],ans1[20][20],DIV[20][20],U_UTRANCE[20][20],I[20][20],newans[20][20],newans1[20][20],new[20][20];

  //int nrow,ncol;
  nrow=n;
  ncol=nrow;
  rno=n;
  cno=n;

	printf("\nmatrix is\n");
   for(i=0;i<ncol;i++)
    {
      for(j=0;j<nrow;j++)
	{
	 printf("%f\t",A[i][j]);

	}
	printf("\n");
    }

	
	printf("\nmatrix newmat is\n");
	for(i=0;i<ncol;i++)
    {
      for(j=0;j<nrow;j++)
	{
	 printf("%f\t",newmat[i][j]);

	}
	printf("\n");
    }


  //-----------------------------L--------- 

  for(i=0;i<ncol;i++)
    {
      for(j=0;j<nrow;j++)
	{
	  l[i][j]=A[j][i];
	}
    }

  for(i=0;i<ncol;i++)
    {
      for(j=0;j<nrow;j++)
	{
	  printf("L%d  :value %f:\t",i,l[i][j]);
	}
      printf("\n");
    }
  printf("\n-----------------------------------------------------\n");
  //--------------------------alpha----------------------

  alpha[0]=0;
  
  for(i=0;i<ncol;i++)
    {
      for(j=0;j<nrow;j++)
	{
	  alpha[i]=(l[i][j]*l[i][j])+alpha[i];
	  //alpha[i]=pow(TEMP,0.5);
	}
      //alpha[i]=pow(TEMP,0.5);

    }
  
  for(i=0;i<ncol;i++)
    {
     alpha[i]=pow(alpha[i],0.5);
      printf("squr(alpha) is:%f\n",alpha[i]);
    }
   printf("\n-----------------------------------------------------\n");
  //-------------------------E-------------------------
  for(i=0;i<nrow;i++)
    {
      for(j=0;j<ncol;j++)
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

  for(i=0;i<nrow;i++)
    {    
      for(j=0;j<ncol;j++)
	{
	  printf("E Matrix:-%d,%d:=%f\t",i,j,I[i][j]);
	}
      printf("\n");
    }

 printf("\n-----------------------------------------------------\n");

  //-------------------------------U---------------

  for(i=0;i<ncol;i++)
    {
      for(j=0;j<nrow;j++)
	{
	  E[i][j]=I[j][i];
	}
    }
  
  for(i=0;i<nrow;i++)
    {    
      for(j=0;j<ncol;j++)
	{
	  if(E[i][j]==1)
	    {
	      U[i][j]=l[i][j]+alpha[i]*E[i][j];
	    }
	  else
	  {
	  U[i][j]=l[i][j]-alpha[i]*E[i][j];
	  }
	}

    }


  for(i=0;i<nrow;i++)
    {
      for(j=0;j<ncol;j++)
	{
	  printf("U of %d,%d value is:%f\n",i,j,U[i][j]);
	}
      printf("\n");
    }

 printf("\n-----------------------------------------------------\n");
  //-------------------------------U tranpos * U--------

  
  
 i=0;
   
  
     
    
      for(z=0;z<nrow;z++)
  	{
  	  for(j=0;j<ncol;j++)
  	    {
	      U_UTRANCE[z][j]=U[i][z]*U[i][j];
	      //xo  printf("U_utrance %d,%d;=%f\tU %d,%d=%f\t U %d,%d=%f\n",z,j,U_UTRANCE[i][j],i,z,U[i][z],i,j,U[i][j]);
	    }
	}
   
     //-------------------------------U * U tranpos---------------
      UTRANCE_U=0;
      for(j=0;j<ncol;j++)
	{
	  UTRANCE_U=(U[i][j]*U[i][j])+UTRANCE_U;
	}


      





  for(z=0;z<nrow;z++)
    {
      for(j=0;j<ncol;j++)
	{
	  printf("value of U_UTRACE: %d,%d:%f:\n",z,j,U_UTRANCE[z][j]);
	}
      printf("\n");
    }
    printf("\n-----------------------------------------------------\n");
  printf("UTRANCE_U:=%f\n",UTRANCE_U);
 printf("\n-----------------------------------------------------\n");
  //---------------------------U*U tranpos/U tranpos *U-------


      for(z=0;z<ncol;z++)
	{
	  for(j=0;j<ncol;j++)
	    {
	      DIV[z][j]=(U_UTRANCE[z][j]/UTRANCE_U)*2;
	      //   printf("value of DIV: %d,%d:%f:\n",i,j,DIV[z][j]);
	    }
	 
	}

      //------------------------subtract by identy matrix-------

      for(z=0;z<ncol;z++)
	{
	  for(j=0;j<nrow;j++)
	    {
	      ans1[z][j]=E[z][j]-DIV[z][j];
	      //  printf("value of %d,%d: E:%f ::  DIV:%f \n",z,j,E[z][j],DIV[z][j]);
	    }
	}





  for(z=0;z<nrow;z++)
    {
      for(j=0;j<ncol;j++)
	{
	  printf("value of DIV: %d,%d:%f:\n",z,j,DIV[z][j]);
	}
      printf("\n");
    }

    printf("\n-----------------------------------------------------\n");
  for(z=0;z<nrow;z++)
    {
      for(j=0;j<ncol;j++)
	{
	  printf("value of ans1: %d,%d:%f:\n",z,j,ans1[z][j]);
	}
      printf("\n");
    }
    printf("\n-----------------------------------------------------\n");
  //------------------------------multiply by input matrix------

      
    for(k=0;k<nrow;k++)
      {
	for(z=0;z<nrow;z++)
	  {
	    for(j=0;j<nrow;j++)
	      {
		ans[k][z]=(ans1[k][j]*l[z][j])+ans[k][z];
	      }
	  }
      }


    /*for(k=0;k<ncol;k++)
      {
      for(z=0;z<nrow;z++)
      {
      for(j=0;j<nrow;j++)
      {
      ans[k][z]=(ans1[z][j]*l[k][j])+ans[k][z];
      }
      }
      }*/




 for(k=0;k<nrow;k++)
    {
      printf("value of ans:");
      for(j=0;j<ncol;j++)
	{
	  printf(" %d,%d:%f:\t",k,j,ans[k][j]);
	}
      printf("\n");
    }
    printf("\n-----------------------------------------------------\n");
    printf("\n-----------------------------------------------------\n");
    z=0;
    p=0;



    
    float H[20][20];
    
    //printf("CNT : %d",cnt);
   /* if(cnt!=0)
      {
	k=0;
	p=0;
	for(j=0;j<ncol+1;j++)
	  {
	    for(z=0;z<ncol+1;z++)
	      {
		if(j==0 && z==0)
		  {
		    // printf("%d:%d",j,z);
		    newans[j][z]=1.0;
		  }
		if(j==0 &&  ((ncol+1)>z  && z>0))
		  {
		    newans[j][z]=0;
		  }
		  if(j==1 && z==0)
		    {
		      newans[j][z]=0;
		    }
		  if(j>0 && z>0)
		    {
		      newans[j][z]=ans[k][p];
		      //k++;
		      p++;
		      if(p==ncol)
			{
			  k++;
			  p=0;
			  if(k==ncol)
			    {
			      k=0;
			    }
			}
		    
		    }
		  
		  
	      }
	    
		
	  }
     */   




	//----------calculate 2 by 2 matrix---------------
	for(i=1;i<rno;i++)
	  {
	    for(j=1;j<cno;j++)
	      {
		new[i-1][j-1]=ans[i][j];
	      }
	  }
		  
//---------display matrix new ------------------
	
	printf("\n****new matrix is: ****\n");
	for(i=0;i<rno-1;i++)
	  {
	    for(j=0;j<cno-1;j++)
	      {
		printf("%f\t",new[i][j]);
	      }
	    printf("\n");
	  }

	if(cnt1>0)
	{
	for(i=cnt1;i<=rno+cnt1;i++)
	{
		q=0;	
		for(j=cnt1;j<=cno+cnt1;j++)
		{
			newmat[i][j]=ans[p][q];
			
			q++;
			//printf("cnt=%d\tht1=%f\n",j,new1[i][j]);
		}
		p++;
	}
	}
	else
	{
	
	for(i=0;i<rno;i++)
	{
	  for(j=0;j<cno;j++)
	    newmat[i][j]=ans[i][j];
	}
	}
	printf("\n****new1 ans matrix is: ****\n");
	for(i=0;i<rno+cnt1;i++)
	  {
	    for(j=0;j<cno+cnt1;j++)
	      {
		printf("%f\t",newmat[i][j]);
	      }
	    printf("\n");
	  }
	
	
	
	if(rno==2)
	  return 0;
	else
	{
	printf("\n=========================================================\n");
	printf("****\n\nRecursive call\n\n****");
	cnt1=cnt1+1;
	H_A((rno-1),new,newmat,cnt1);	  
	}








/*




	
	for(j=0;j<ncol+1;j++)
	  {
	    printf("newans :");
	    for(z=0;z<ncol+1;z++)
	      {
		printf("%f\t",newans[j][z]);
	      }
	    printf("\n");
	  }

    		      
      



    for(j=0;j<ncol+1;j++)
      {
	printf("matrix is:");
	for(z=0;z<ncol+1;z++)
	  {
	    printf("%f\t",newmat[j][z]);
	  }
	printf("\n");
      }
    
    
    //  for(k=0;k<ncol+1;k++)
    //{
	for(p=0;p<ncol+1;p++)
	  {
	    for(j=0;j<ncol+1;j++)
	      {
		for(z=0;z<ncol+1;z++)
		  {
		    newans1[p][j]=(newans[p][z]*newmat[z][j])+newans1[p][j];
		    //printf("newans:%f \n newmat:%f \n newans1:%f \n",newans[j][z],newmat[z][j],newans1[p][j]);
	

		  }
		printf("\n");

	      }
	    printf("\n");
	  }

	//}


    for(j=0;j<ncol+1;j++)
      {
	printf("\nnew matrix is:");
	for(z=0;z<ncol+1;z++)
	  {
	    printf("%f\t",newans1[j][z]);
	  }
	printf("\n");
      }

      }

    if(nrow==2)
      {
	
	return 0;
      }
    else
      {
	  
	    for(k=1;k<nrow;k++)
	      {
		printf("value of H1:");
		for(j=1;j<ncol;j++)
		  {
		    if(p==(nrow-1))
		      {
			p=0;
		      }
		    
		    H[z][p]=ans[k][j];
		    
		    //printf(" %d,%d:%f:\t",k,j,ans[k][j]);
		    printf(" %d,%d:%f:\t",z,p,H[z][p]);
		    p++;
		  }
		z++;
		printf("\n");
	      }
	    printf("\n-----------------------------------------------------\n");
	    printf("\n-----------------------------------------------------\n");
	    
	    cnt++;

	    H_A((nrow-1),H,ans);
	    
      }
    
    return (0);
 */   

  
}
