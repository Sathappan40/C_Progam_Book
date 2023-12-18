#include <stdio.h>
int rightrot(int x, int n);

int main(void)
{
  int x, n; 
  x=56;
  n=2;
  printf("%d\n", rightrot(x, n));
  return 0;
}

int rightrot(int x, int n)
{
  int last = 0;
  last = ~(~last << n);
  last = x & last;
  last = last << (8 * sizeof(x) - n);
  return ((x >> n) | last);
}
