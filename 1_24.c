#include <stdio.h>
int main()
{
  int ch = 0, pch = 0;
  int r = 0;
  int s = 0;
  int c = 0;
  int cmnt = 0;

  while((ch = getchar()) != EOF) 
{
    if(ch == '(') 
    {
      r++;
    }
    else if(ch == '[') 
    {
      s++;
    }
    else if(ch == '{') 
    {
      c++;
    }
    else if(ch == '*' && pch == '/') 
    {
      cmnt++;
    }
    else if(ch == ')') 
    {
      r--;
    }
    else if(ch == ']') 
    {
      s--;
    }
    else if(ch == '}') 
    {
      c--;
    }
    else if(ch == '/' && pch == '*') 
    {
      cmnt--;
    }
    pch = ch;
  }
  if(r != 0 || s!=0 || c!=0 || cmnt!=0) 
  {
    printf("Syntax Error\n");
  }
  return 0;
}
