#include<stdio.h>
#define MAXI 1000
#define N 8

int main(void)
{
  char c;
  int i,j,k=0,l;
  char li[MAXI];
  while((c=getchar()) != EOF)
  {
    if(c!='\t')
      putchar(c);
      k++;
    if(c=='\n')
      putchar(c);
      k=0;
    if(c=='\t')
    {
      if (li[i--]=='\n')
      {
         for(j=0;j<N;j++)
         {
            putchar(' ');
         }
      }
      else 
      {
        l=k%N;
        for(j=0;j<N-l;j++)
        {
           putchar(' ');
           k++;
        }
      }
     }
  }
  printf("%s",li);
return 0;
}
