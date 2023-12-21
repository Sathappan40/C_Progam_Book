#include<stdio.h>
#define MAX 100

void itoa(char s[],int n)
{
	static int i=0;
	if(n<0)
	{
		s[i++]='-';
		n=-n;
	}
	if(n/10)
		itoa(s,n/10);
	if(i<MAX-1)
		s[i++]=n%10+'0';
        s[i]='\0';
}

int main ()
{
	int num=2387;
	char s[MAX];
        itoa(s,num);
	printf("%s",s);
        return 0;
}
