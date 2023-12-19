#include<stdio.h>
int mstrindex(char source[],char pattern[]);

int main(void)
{
    char line[] = "testdgftestghdtestdpg";
    char pattern[] = "test";
    int found;
    found = mstrindex(line, pattern);
    printf("%d\n", found);
}

int mstrindex(char s[],char t[])
{
    int i,j,k, result;
    result = -1;
    for(i=0;s[i]!='\0';i++)
    {
        for(j=i,k=0;t[k]!='\0' && s[j]==t[k];j++,k++)
            ;
        if(k>0 && t[k] == '\0')
            result = i;
    }
    return result;
}
