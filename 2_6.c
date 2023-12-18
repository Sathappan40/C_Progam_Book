#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);

int main(void)
{
       	printf("%u", setbits((unsigned) 82, 3,2, (unsigned)97));
}

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    return x & ~(~(~0 << n) << (p + 1 - n)) | (y & (~(~0 << n)) << (p + 1 - n));
}
