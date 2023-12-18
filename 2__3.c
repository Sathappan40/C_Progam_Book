#include <stdio.h>
#include <string.h>
int htoi(const char *s);
int main()
{
  char *s = "0x4f";
  printf("integer value of hex %s is %d\n", s, htoi(s));
  return 0;
}
int htoi(const char *s)
{
   int i = 0;
   int res = 0;
   if(s[0] == '0' && (s[1] == 'x' || s[1] == 'X')) 
   {
      i = 2;
   }
   for(; i < strlen(s); i++)
  {
     res = res * 16;
      if(s[i] >= '0' && s[i] <= '9') 
      {
         res = res + s[i] - '0';
      }
      else if(s[i] >= 'a' && s[i] <= 'f') 
      {
         res = res + s[i] - 'a' + 10;
      }
      else if(s[i] >= 'A' && s[i] <= 'F') 
      {
         res = res + s[i] - 'A' + 10;
      }
   }
   return res;
}
