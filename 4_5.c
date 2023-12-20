#include <stdio.h>
#include <stdlib.h> 
#include <math.h>
#include <ctype.h>
#include<math.h>

#define MAXOP 100 
#define NUMBER '0' 
#define MAXVAL 100
#define BUFSIZE 100 
#define NAME 'n'

int getop(char[]);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);
void mathfn(char[]);

int main()
{
    int type;
    double op2;
    char s[MAXOP];
    
    while((type = getop(s)) != EOF)
    {
        switch(type)
        {
            case NUMBER:
                push(atof(s));
                break;
            case NAME :
                mathfn(s);
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() + pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if(op2 != 0)
                    push(pop() / op2);
                else
                    printf("Zero devisior\n");
                break;
            case '%':
                op2 = pop();
                if(op2 != 0.0)
                    push(fmod(pop(), op2));
                else
                    printf("Zero devisor\n");
                break;
            case '\n':
                op2 =pop();
                if(op2>0)
                    printf("\t%.8g\n", op2);
                else
                    printf("\t%d\n", ~(int)op2);
                break;
            default:
                printf("Unknown command %s\n", s);
                break;
        }
    }
    return 0;
} 

int sp;
double val[MAXVAL]; 
int sp = 0; 

void push(double f)
{
    if(sp < MAXVAL)
        val[sp++] = f;
    else
        printf("Stack is full %g\n", f);
}

double pop(void)
{
    if(sp > 0)
        return val[--sp];
    else
    {
        printf("Stack empty\n");
        return 0.0;
    }
}

int getop(char s[])
{
    int i, c;
    while((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    i=0;
    if(islower(c))
    {
         while(islower(s[i++]=c=getchar()))
                ;
         s[i] ='\0';
         if(c!=EOF)
             ungetchar(c);
         if(strlen(s)>1)
             return NAME;
         else
             return s[0];
     }
    if(!isdigit(c) && c != '.' && c != '-')
        return c; 
    if (c == '-')
    {
        if(isdigit(c = getch()) || c == '.')
            s[++i] = c; 
        else
            {
                if(c != EOF)
                    ungetch(c);
                return '-';
            }
    }
    if(isdigit(c)) 
        while(isdigit(s[++i] = c = getch()))
            ;
    if(c == '.')
        while(isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if(c != EOF)
        ungetch(c);
    return NUMBER;
}

char buf[BUFSIZE];
int bufp = 0;

int getch(void) 
{
   return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) 
{
    if(bufp >= BUFSIZE)
        printf("Too many characnters\n");
    else
        buf[bufp++] = c;
}

void mathfn(char s[])
{
    double p;
    if(strcmp(s,"sin")==0)
        push(sin(pop()));
    else if(strcmp(s,"cos")==0)
        push(cos(pop()));
    else if(strcmp(s,"exp")==0)
        push(exp(pop()));
    else if(strcmp(s,"pow")==0)
    {
        p=pop();
        push(pow(pop(),p));
    }
    else
        printf("It is not valid input");
}
