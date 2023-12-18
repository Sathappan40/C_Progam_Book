#include <stdio.h>
void squeeze(char*s,char*q)
int main()
{

        char* s = "Operating system";
        char* q = "soy";
        squeeze(s, q);
        printf("%s",s);

}

void squeeze(char* s,char* q)
{
    int i, j, k;
    int f = 0;
    for ( i = j = 0; s[i] != '\0'; i++)
    {
        for (k=0; q[k] != '\0'; k++)
        {
            if (s[i] == q[k])
                f = 1;
        }
        if (!f)
        {
            s[j++] = s[i];
        }
    }
    s[j] = '\0';
}

