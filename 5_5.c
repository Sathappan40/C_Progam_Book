#include<stdio.h>

int strcmp(char*s,char*t,int n);
char* strcpy(char*s,char*t,int n);
char* strcat(char*s,char*t,int n);

int main()
{
	char s[]="hello world";
	char t[]="erkds";
	int n=3;
	printf("%d\n",strcmp(s,t,n));
        strcpy(s,t,n);
	printf("%s\n",s);
        strcat(s,t,n);
	printf("%s\n",s);
}

int strcmp(char*s,char*t,int n)
{
	while(*s==*t && *s!='\0' && n)
	{
		s++;
		t++;
		n--;
	}
	if(n==0)
		return 0;
	else
		return 1;
}

char* strcpy(char*s,char*t,int n)
{
	while(n-- && *s)
	{
		*s=*t;
		s++;
                t++;
	}
	if(strlen(t)<n)
	{
		*s='\0';
	}
        return s;
}

char* strcat(char*s,char*t,int n)
{
	while(*s)
		s++;
	while(n-- && *t!='\0')
	{
		*s=*t;
		s++;
		t++;
	}
	*s='\0';
	return s;
}


