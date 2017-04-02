#include<stdio.h>
#include<math.h>
void main()
{
  int i,j,eq[10],n,limit[2],power[10],approxi,eq1[10],power1[10];
  float temp=0,positive,negative,ans=0,pans,nans,a,x0,b;
  
  
  printf("Enter the how many terms in eqvation");
  scanf("%d",&n);
  
  printf("Enter the terms in eqvaztion");
  for(i=0;i<n;i++)
    {
      scanf("%d",&eq[i]);
    }

  printf("Enter the terms power");
  for(i=0;i<n;i++)
    {
      scanf("%d",&power[i]);
    }


  
  printf("Enter the two numbers you wants to find in between");
      scanf("%f",&positive);
      scanf("%f",&negative);
      
      printf("Enter the how many itration you wants to perform ");
	scanf("%d",&approxi);


	for(i=0;i<n;i++)
	  {
	    eq1[i]=eq[i]*power[i];
	    power1[i]=power[i]-1;
	  }

	/*for(i=0;i<n;i++)
	  {
	    printf("eq is:%d\tpower :%d\n",eq1[i],power1[i]);
	    }*/
		


	
	for(j=0;j<n;j++)
	  {
	    pans=((pow(positive,power[j]))*eq[j])+pans;
	    nans=((pow(negative,power[j]))*eq[j])+nans;
	  }
	//printf("%f",pans);
	//printf("%f",nans);
	if(pans>0 && nans<0 || pans<0 && nans>0)
	  {
	    
	    if(pans<0) 
	      {
		x0=positive;
	      }
	    else
	      x0=negative;
		

	    //printf("x0:%f\n",x0);
		/*temp=positive;
		positive=negative;
		negative=temp;*/
	      
	    
	    for(i=0;i<approxi;i++)
	      {
		a=0;
		for(j=0;j<n;j++)
		  {
		    a=((pow(x0,power[j]))*eq[j])+a;
		    b=((pow(x0,power1[j]))*eq1[j])+b;
		  }

		//printf("a is:%f\t b is:%f\t x0:%f\n",a,b,x0);
		
		ans=x0-(a/b);
		//printf("ans is:%f\n",ans);

		/*x0=0;
		for(j=0;j<n;j++)
		  {
		    x0=((pow(ans,power[j]))*eq[j])+x0;
		    // printf("x0:%f\n",x0);
		    }*/
		x0=ans;
		a=0;
		b=0;
		printf("approximation to the roots are: %f\n",ans);
	      }
	    
	  }
	else
	  {
	    printf("Your limit is out of boundry");
	  }
	
}
