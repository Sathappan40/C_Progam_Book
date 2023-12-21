#include <stdio.h>

#define swap(t, x, y) {t tmp = x; x = y; y = tmp;}

int main()
{
    int x = 14, y =32;
    swap(int, x, y);
    printf("%d %d", x, y);
    return 0;
}
