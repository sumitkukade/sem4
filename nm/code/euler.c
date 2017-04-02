#include<stdio.h>
#include<stdlib.h>

int main()
{
  int i,cnt;
  float h,y0,fy0,y1;
  
  printf("Enter the value of h\n");
  scanf("%f",&h);
  printf("Enter the value of y0\n");
  scanf("%f",&y0);
  fy0=(-1)*y0;
  printf("Enter the number of iterations\n");
  scanf("%d",&cnt);
  for(i=0;i<cnt;i++)
    {
      y1=y0+h*fy0;
      printf("\nThe value of y %d is %f\n",i,y1); 
      y0=y1;
      fy0=(-1)*y0;
    }
}
