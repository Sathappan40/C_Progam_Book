#include<stdio.h>
#include<ctype.h>

#define SIZE 10
#define BUFSIZE 100

int getch(void);
void ungetch(int c);
int getint(int* pn);

char buf[BUFSIZE];
int bufp=0;

int getch(void)
{
	return (bufp>0)?buf[--bufp]:getchar();
}
void ungetch(int c)
{
	if(bufp>=BUFSIZE)
		printf("Too many characters");
	else
		buf[bufp++]=c;
}

int getint(int* pn)
{
	int c,sign;
	while(isspace(c=getch()))
		;
	if(!isdigit(c) && c!=EOF && c!='+' && c!='-')
	{
		ungetch(c);
                return -1;
	}
	sign = (c=='-')?-1:1;
	if(c=='+'||c=='-')
		c=getch();
	if(!isdigit(c))
		return 0;
	for(*pn=0;isdigit(c);c=getch())
		*pn= *pn*10+(c-'0');
	*pn= *pn*sign;
	if(c!=EOF)
		ungetch(c);
	return c;
}
int main(void)
{
	int n, r, array[SIZE];
        for(int i = 0; i < SIZE; i++)
        {
                array[i] = 15;
        }
        for(n = 0; n < SIZE; n++)
        {
                if ((r =getint(&array[n])) == 0) {
                      getch();
        }
        if (r == EOF) 
        {
                continue;
        }
    }
    for(int i = 0; i < SIZE; i++)
    {
                printf("array[%d] = %d\n", i, array[i]);
    }
    return 0;
}
