#include<stdio.h>

#define BUFSIZE 100

int getch(void);
void ungetch(int c);

int buf[BUFSIZE];
int bufp = 0;    

int main(void) 
{
    int c;
    c = '$';
    ungetch(c);
    while ((c = getch()) != EOF)
        putchar(c);
    return 0;
}

int getch(void) 
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) 
{
    if (bufp >= BUFSIZE)
        printf("Too many characters \n");
    else
        buf[bufp++] = c;
}
	
