#include<stdio.h>
#include<math.h>
void main()
{
  int i,j,eq[10],n,limit[2],power[10],approxi,cnt=1;
  float temp=0,positive,negative,ans=0,pans=0,nans=0,a,ans1=10;
      int deci=1,q1,q2;
  
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
      
      printf("Enter the how many decimal placimal placesy ou wants to Correct ");
	scanf("%d",&approxi);
	
	for(j=0;j<n;j++)
	  {
	    pans=((pow(positive,power[j]))*eq[j])+pans;
	    nans=((pow(negative,power[j]))*eq[j])+nans;
	  }
	//printf("pooo%f",pans);
	//printf("neeeeeee%f",nans);
	if(pans>0 && nans<0 || pans<0 && nans>0)
	  {
	    
	    if(pans<0 && nans>0) 
	      {
		temp=positive;
		positive=negative;
		negative=temp;

		/*temp=pans;
		pans=nans;
		nans=temp;
		*/
	      }
	    
	
	    for(i=0;i<approxi;i++)
	      {
		deci=deci*10;
	      }
	    while((q1=(ans1*deci))!=(q2=(ans*deci)))
	      {

		printf("Iteration.....%d.......\n",cnt);
		//printf("pans:%f\tnans:%f\n",pans,nans);
		ans1=ans;
		ans=((positive*pans)-(negative*nans))/(pans-nans);
		a=0;
		//printf("ans :%f\n",ans);
		for(j=0;j<n;j++)
		  {
		    
		    a=((pow(ans,power[j]))*eq[j])+a;
		    //  printf("a:%f\n",a);
		  }
		if(a>0)
		  {
		    positive=ans;
		    nans=a;
		  }
		else
		  {
		    negative=ans;
		    pans=a;
		  }
		cnt++;
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
