#include <stdio.h>
#define MAX 1000
void copy(char to[], const char from[]);

int main() 
{
    int len, max;
    char line[MAX];
    while ((len = _getline(line, MAX)) > 0) 
   {
    if (len > 80) 
    {
       printf("string=%s", line);
    }
    return 0;
   }
}

int _getline(char arr[], int lim) 
{
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) 
    {
        arr[i] = c;
    }
    if (c == '\n') 
    {
        arr[i] = c;
        ++i;
    } 
    arr[i] = '\0';
    return i;
}


