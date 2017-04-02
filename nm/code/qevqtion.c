#include<stdio.h>
#include<string.h>
char *str(char string[20])
{
  int i=0,j=0;
  char str1[20];
  printf("str is:%s\t%d\n",string,strlen(string));

  for(i=0;i<strlen(string);i++)
    {
      if(string[i]==' ')
	{
	  //string[i]=string[i+1];
	  i++;
	}
      else
	{
	  str1[j]=string[i];
	  j++;
	}
    }
  str1[j]='\0';
  printf("str is:%s\n",str1);

}


void main()
{
  str("aa    mo  l");
}
