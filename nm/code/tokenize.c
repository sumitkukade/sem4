#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
  char expr[30]="x+y*z",*exp[10],tmp[30];
  char *op[5]={"*","/","+","-"};
  int i;
  for(i=0;i<4;i++)
    {
      strcpy(tmp,expr); 
      exp[i]=strtok(tmp,op[i]);
      printf("%s\n",exp[i]);
    }
}
