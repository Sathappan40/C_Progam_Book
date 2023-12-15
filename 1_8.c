#include<stdio.h>
int main() {
    int c, b, t, n;

    b=t=n=0;

    while ((c = getchar()) != EOF) {
        if (c == ' ')
            ++b;
        if (c == '\t')
            ++t;
        if (c == '\n')
            ++n;
    }

    printf("%d\n%d\n%d\n", b,t,n);
}
