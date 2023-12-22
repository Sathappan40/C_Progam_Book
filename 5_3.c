#include<stdio.h>
void str_cat(char* ,char*);

int main(void)
{
	char s[]="dncj";
	char t[]="cnnas";
	str_cat(s,t);
	printf("%s\n",s);
	return 0;
}

void str_cat(char*s, char*t)
{
	while(*s!='\0')
	{
		s++;
	}
	while(*t!='\0')
	{
		*s=*t;
		s++;
		t++;
	}
}

