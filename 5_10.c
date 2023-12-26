#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

#define MAX 100
#define NUMBER '0'
#define MAXVAL 100
#define BUFSIZE 100

int sp=0;
int bufp=0;
int val[MAXVAL];
int buf[BUFSIZE];

int getop(char[]);
void ungets(char[]);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);

int main(int argc, char* argv[])
{
	char s[MAX];
	double op2;
	while(--argc>0)
	{
		ungets(" ");
		ungets(*++argv);
	        
		switch(getop(s))
		{
			case NUMBER:
				push(atof(s));
				break;
			case '+':
				push(pop()+pop());
				break;
			case '-':
				op2=pop();
				push(pop()-op2);
                                break;
			case '*':
				push(pop()*pop());
				break;
			case '/':
				op2=pop();
				push(pop()/op2);
                                break;
			default:
				printf("unkown command");
				argc=1;
				break;
		}
	}
	printf("%8g\n",pop());
	return 0;
}

int getop(char s[])
{
	int i,c;
	while(s[0]=c=getchar() == ' ' || c=='\t')
		;
	s[1]='\0';
	if(!isdigit(c) && c!='.')
		return c;
	i=0;
	if(isdigit(c))
		while(isdigit(s[++i]=c=getchar()));
	if(c=='.')
	        while(isdigit(s[++i]=c=getchar()));
	s[i]='\0';
	if(c!=EOF)
	        ungetch(c);
	return NUMBER;
}

int getch(void)
{
        return (bufp>0)?buf[--bufp]:getchar();
}

void ungetch(int c)
{
        if(bufp>BUFSIZE)
	        printf("Too many characters");
	else
	        buf[bufp++]=c;
}

void push(double f)
{
	if(sp<MAXVAL)
		val[++sp]=f;
	else
		printf("stack is full");
}

double pop(void)
{
	if(sp>0)
		return val[--sp];
	else
		printf("satck is empty");
                return 0.0;
}

void ungets(char s[])
{
	int len=strlen(s);
	void ungetch(int);
	while(len>0)
		ungetch(s[--len]);
}



                         


