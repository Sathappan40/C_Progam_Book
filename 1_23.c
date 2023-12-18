#include <stdio.h>

int main() {
  char prev;
  char c;
  char next;
  while ((c = getchar()) != EOF) 
  {
    if (c == '"') 
    {
      putchar(prev = c); 
      while ((c = getchar()) != '"' || prev == '\\') 
      {
        putchar(prev = c);
      }
      putchar(prev = c);

    } 
    else if (c == '/') 
    {
      next = getchar();
      if (next == '/') 
      {
        while ((c = getchar()) != '\n')
          ;
        putchar('\n');
      } 
      else if (next == '*') 
      {
        prev = getchar();
        while ((c = getchar()) != '/' || prev != '*') 
        {
          prev = c;
        }
      } 
      else 
      {
        putchar(c);
        putchar(prev = next);
      }

    } 
    else 
    {
      putchar(prev = c);
    }
  }
}
