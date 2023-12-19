#include <stdio.h>
#include <string.h>
#define MAX 1000


void itoa(int n, char s[],int w);
void reverse(char s[]);

int main(void) 
{
    int number,w;
    char str[MAX];
    number = 5673;
    w=10;
    itoa(number, str,w);
    printf("%s", str);
    return 0;
}

void itoa(int n, char s[],int w) 
{
    int i, sign;
    sign = n;
    i = 0;
    do 
    {
        s[i++] = abs(n % 10) + '0';
    } 
    while ((n /= 10) != 0);
    if (sign < 0)
        s[i++] = '-';
    while(i<w)
    {
        s[i++]=' ';
    }
    s[i] = '\0';
    reverse(s);
}

void reverse(char s[]) 
{
    int c, i, j;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
        c = s[i];
        s[i] = s[j];
        s[j] = c;
}
