#include<stdio.h>
int strend(char*,char*);

int main()
{
	char s[]="Operating System";
        char t[]="System";
	printf("%d\n",strend(s,t));
}

int strend(char*s,char*t)
{
	while(*s++)
        {
		if(*t==*s)
		{
			while((*s++==*t++))
			{
				if(*s=='\0'&&*t=='\0')
				{
					return 1;
				}
                                return 0;
			}
		}
	}
	return 0;
}

