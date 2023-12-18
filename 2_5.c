#include<stdio.h>
#include<limits.h>

int main()
{
	int l;
	char s1[] = "Operating system";
	char s2[] = "so";
	l=any(s1,s2);
	printf("%d",l);
        return 0;
}

int any(char s1[],char s2[])
{
	int i=0,j;
	int l=-1;
	while (s1[i]!='\0')
	{
		j=0;
		while(s2[j]!='\0')
		{
		        if(s1[i]==s2[j])
			{
				l=i;
                                return l;
				
		        }
			j++;
		}
		i++;
	}
        return -1;
}	
