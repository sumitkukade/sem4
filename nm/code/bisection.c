#include<stdio.h>
#include<math.h>
void main()
{
  int i,j,eq[10],n,limit[2],power[10],approxi;
  float temp=0,positive,negative,ans=0,pans,nans,a;
  
  
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
	
	for(j=0;j<n;j++)
	  {
	    pans=((pow(positive,power[j]))*eq[j])+pans;
	    nans=((pow(negative,power[j]))*eq[j])+nans;
	  }
	//printf("%f",pans);
	//printf("%f",nans);
	if(pans>0 && nans<0 || pans<0 && nans>0)
	  {
	    
	    if(pans<0 && nans>0) 
	      {
		temp=positive;
		positive=negative;
		negative=temp;
	      }
	    
	    for(i=0;i<approxi;i++)
	      {
		ans=(positive+negative)/2;
		a=0;
		for(j=0;j<n;j++)
		  {
		    
		    a=((pow(ans,power[j]))*eq[j])+a;
		  }
		if(a>0)
		  {
		    positive=ans;
		  }
		else
		  {
		    negative=ans;
		  }
		
		printf("%f\n",positive);
		printf("%f\n",negative);
		printf("approximation to the roots are: %f\n",ans);
	      }
	    
	  }
	else
	  {
	    printf("Your limit is out of boundry");
	  }
	
}
