#include <stdio.h>
#include <ctype.h>

#define MAXLINE 1000

int get_line(char line[], int max);
void expand(const char s1[], char s2[]);
int match(int p, int q);

int main(void)
{
    char s1[MAXLINE];
    char s2[MAXLINE];

    while (get_line(s1, MAXLINE) > 0)
    {
        expand(s1, s2);
        printf("%s", s2);
    }
    return (0);
}
int get_line(char s[], int max)
{
       int c, i;

       i = 0;
       while (--max > 0) 
       {
          c = getchar();
          if (c == EOF)
             break;
          if (c == '\n')
             break;
          s[i++] = c;
       }
       if (c == '\n')
          s[i++] = c;
       s[i] = '\0';
       return (i);
}


void expand(const char s1[], char s2[])
{
    int i, j, ch;

    for (i = j = 0; (ch = s1[i++]) != '\0'; ) {
        if (s1[i] == '-' && match(s1[i-1], s1[i+1])) {
            for (i++; ch < s1[i]; ) {
                s2[j++] = ch++;
            }
        } else
            s2[j++] = ch;
    }
    s2[j] = '\0';
}


int
match(int start, int end)
{
    return ((isdigit(start) && isdigit(end)) ||
        (islower(start) && islower(end)) ||
        (isupper(start) && isupper(end)));
}
