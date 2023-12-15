#include <stdio.h>
#define MAXLINE 1000
int main(void) 
{
  int len,i,j;
  char line[MAXLINE],rev[MAXLINE];
  char c;
  for(i=0;(c=getchar())!=EOF && c!='\n' && i<MAXLINE-1;i++) 
  {
    line[i]=c;
  }
  if(c=='\n')
  {  
     i--;
     for(j=0;i>=0;)
     {
      rev[j++]=line[i--];
     }
  }
  printf("%s",rev);
}
   
