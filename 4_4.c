#include <stdio.h>
#include <stdlib.h> 
#include <math.h>
#include <ctype.h>

#define MAXOP 100 
#define NUMBER '0' 
#define MAXVAL 100
#define BUFSIZE 100 

int getop(char[]);
void push(double);
double pop(void);
double head(void);
void duplicate(void);
void swap(void);
void clear(void);
int getch(void);
void ungetch(int);


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
            case '^':
                printf("%f",head());
                break;
            case '@':
                duplicate();
                break;
            case '$' :
                swap();
                break;
            case '#' :
                clear();
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

double head(void)
{
    if(sp>0)
        return val[sp--];
    else
        printf("Stack empty");
}

void duplicate(void)
{
    push(head());
}

void swap(void)
{
    double temp;
    int i;
    if(sp<2)
         printf("Cannot be swapped");
     else
     {
         i=sp-1;
         temp=val[i-1];
         val[i-1]=val[i];
         val[i]=temp;
     }
}

void clear(void)
{
    while(--sp>=0)
         val[sp]=0.0;
    sp=0;
}

int getop(char s[])
{
    int i, c;
    while((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if(!isdigit(c) && c != '.' && c != '-')
        return c; 
    i = 0;
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
