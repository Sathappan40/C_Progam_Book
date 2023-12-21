#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define MAX 100
#define NUMBER '0'
#define MAXVAL 100
#define MAXLINE 100

int gettop(char[]);
void push(double);
double pop(void);
int _getline(char line[],int lim);

int main()
{
	int type;
	double op2;
	char s[MAX];

	while ((type = getop(s)) != EOF) {
        switch (type)
       	{
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                break;
            case '\n':
                printf("\t%.9g\n", pop());
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}

int sp = 0;
double val[MAXVAL];

void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf(" Stack full %g\n", f);
}

double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else
    {
        printf(" Stack empty \n");
        return 0.0;
    }
}

int li=0;
char line[MAXLINE];

int getop(char s[])
{
	int c,i;
	if(line[li]=='\0')
		if(_getline(line,MAXLINE)==0)
			return EOF;
	        else
			li=0;
	while((s[0]=c=line[li++])==' ' ||c=='\t')
		;
	s[1]='\0';
	if(!(isdigit(c)) && c!='.')
		return c;
	i=0;
	if(isdigit(c))
		while(isdigit(s[++i]=c=line[li++]))
			;
	if(c='.')
		while(isdigit(s[++i]=c=line[li++]))
				;
	s[i]='\0';
	li--;
	return NUMBER;
}

int _getline(char s[],int lim)
{
        int i,c;
	for(i=0;i<lim-1 && (c=getchar())!=EOF && c!='\n';++i)
	        s[i]=c;
	if(c=='\n')
	        s[++i]=c;
	s[i]='\0';
	return i;
}

