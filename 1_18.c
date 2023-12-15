#include <stdio.h>
#define MAXLINE 1000
int main(void) 
{
    int len;
    char line[MAXLINE];

    while ((len = _getline(line, MAXLINE)) > 0)
        if (remove_trail(line) > 0)
            printf("%s", line);

    return 0;
}

int _getline(char line[], int lim) 
{
    int i, c;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;
    if (c == '\n') 
    {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}

int remove_trail(char rl[]) 
{
    int i;
    for (i = 0; rl[i] != '\n'; ++i);
        --i;
    for (i > 0; ((rl[i] == ' ') || (rl[i] == '\t')); --i); 
    if (i >= 0) 
    {
        ++i;
        rl[i] = '\n';
        ++i;
        rl[i] = '\0';
    }
    return i;
}
