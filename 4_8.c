#include<stdio.h>
char buf=0;

int getch(void)
{
   int c;
   if(buf!=0)
   {
       c=buf;
   }
   else
   {
       c=getchar();
   }
   buf=0;
   return c;
}

void ungetch(int c)
{
   if(buf!=0)
       printf("Too many characters");
   else
       buf=c;
}

int main()
{
   int c;
   c='$';
   ungetch(c);
   while((c=getch())!=EOF)
   {
       putchar(c);
   }
   return 0;
}
