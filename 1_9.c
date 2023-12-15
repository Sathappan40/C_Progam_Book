#include <stdio.h>


int main(void) 
{
    int c, p;
    while ((c = getchar()) != EOF) {
        if (c == ' ') 
        {
            if (p != ' ')
                putchar(c);
        } 
        else
            putchar(c);
        p = c;
    }
    return 0;
}
