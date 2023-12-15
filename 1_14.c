#include <stdio.h>

#define TOTAL 128 /* Total Number of characters is 128: 0 - 127 */

int main(void) {
    int c, i, j;

    int arr[TOTAL];

    for (i = 0; i < TOTAL; ++i) 
    {
        arr[i] = 0;
    }

    while ((c = getchar()) != EOF) 
    {
        arr[c]++;
    }

    for (i = 0; i < TOTAL; ++i) 
   {
        putchar(i);
        putchar('\t');

        for (j = 0; j < arr[i]; ++j)
            putchar('*');

        putchar('\n');
    }
    return 0;
}
