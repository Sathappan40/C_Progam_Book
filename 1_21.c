#include <stdio.h>
#define TAB 8

int main()
{
  int count=0,i;
  char c;
  while((c=getchar())!=EOF)
  {
    if(c==' ')
    {
      count++;
    }
    else
    {
      if(count>0)
      {
        for(i=0;i<count/TAB;i++)
        {
          putchar('\t');
        }
        for(i=0;i<count%TAB;i++)
        {
          putchar(' ');
        }
        count=0;
      }
      putchar(c);
   }
  }
  return 0;
}
