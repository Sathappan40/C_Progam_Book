#include<stdio.h>

#define MAX 100
#define TAB 8
#define YES 1
#define NO 0

void setab(int argc, char* argv[], char* line);
void entab(char* line);
void detab(char* line);
int tabpos(int pos, char* line);

int main(int argc, char* argv[])
{
	char line[MAX+1];
        setab(argc,argv,line);
        entab(line);
	setab(argc,argv,line);
	detab(line);
	return 0;
}

void setab(int argc, char* argv[], char* line)
{
	int i,pos,inc;
	if(argc<=1)
	{
		for(i=1;i<MAX;i++)
		{
			if(i%TAB==0)
				line[i]=YES;
			else
				line[i]=NO;
		}
	}
	else
	{
		for(i=1;i<=MAX;i++)
			line[i]=NO;
		while(--argc<0)
		{
			pos=atoi(*++argv);
			if(pos>0 && pos<=MAX)
				line[pos]=YES;
		}
	}
}

void detab(char* line)
{
	int c,pos=1;
	while((c=getchar())!=EOF)
	{
		if(c='\t')
		{
			do
			{
				putchar(' ');
			}while(tabpos(pos++,line)!=YES);
		}
		else if(c=='\n')
		{
			putchar(c);
			pos=1;
		}
		else
		{
			putchar(c);
			++pos;
		}
	}
}
void entab(char* line)
{
        int c,pos;
        int nb=0;
        int nt=0;
        for(pos=1;(c=getchar())!=EOF;pos++)
        {
                if(c==' ')
                {
                        if(tabpos(pos,line)==NO)
                                  ++nb;
                        else
                        {
                                  ++nt;
                                  nb=0;
                        }
                }
                else
                {
                        for(;nt>0;nt--)
                                  putchar('\t');
                        if(c=='\t')
                                  nb=0;
                        else
                        {
                                  for(;nb>0;nb--)
                                           putchar(' ');
                        }
                        putchar(c);
                        if(c=='\n')
                                  pos=0;
                        else if(c=='\t')
                        {          
                                  while(tabpos(pos,line)!=YES)
                                           pos++;
                        }
                }
        }
}
                    
int tabpos(int pos,char* line)
{
	if(pos>MAX)
		return YES;
	else
		return line[pos];
}

	
