#include <stdio.h>

void escape(char s[], char t[]);

int main()
{
  char s[] = "jcfn\tejqi\nyedhjk\n";
  char t[1000];
  escape(s, t);
  printf("%s\n", t);
}

void escape(char s[], char t[])
{
  char c;
  int i = 0;
  int j = 0;
  while ((c = s[i]) != '\0')
  {
    switch (c)
    {
      case '\n':
        t[j++] = '\\';
        t[j] = 'n';
        break;
      case '\t':
        t[j++] = '\\';
        t[j] = 't';
        break;
      default:
        t[j] = s[i];
        break;
    }
    i++;
    j++;
  }
  t[j] = '\0';
}
