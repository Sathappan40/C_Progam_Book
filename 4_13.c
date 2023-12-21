#include<stdio.h>
#include<string.h>

#define MAX 100

int _getline(char line[],int max);
void reverse(char s[]);

int main()
{
	char s[MAX];
	_getline(s,MAX);
	reverse(s);
	printf("%s",s);
	return 0;
}

int _getline(char line[],int max)
{
	int i,c;
	for(i=0;i<max-1 && (c=getchar())!=EOF && c!='\n';i++)
		line[i]=c;
	if(c=='\n')
		line[i++]=c;
	line[i]='\0';
}

void reverse(char s[])
{
	static int i=0;
	static int len;
	int j;
	char c;

	if(i==0)
		len=strlen(s);
	j=len-(i+1);
	if(i<j)
	{
		c=s[i];
		s[i]=s[j];
		s[j]=c;
		i++;
		reverse(s);
	}
	else
		i=0;
}


