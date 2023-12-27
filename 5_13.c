#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define DEFLIN 10
#define LINES 100
#define MAXLEN 100

int _getline(char*,int);

int main(int argc, char* argv)
{
	char* p;
	char* bufs;
	char* bufend;
	char line[MAXLEN];
	char* lineptr[LINES];
        int first,i,last,len,nlines,n;

	if(argc==1)
		n==DEFLIN;
	else if(argc==2 && (*++argv)[0]=='-')
		n=atoi(argv[0]+1);
	else
		printf("error");
	if(n<1 || n>LINES)
		n=LINES;
	for(i=0;i<LINES;i++)
		lineptr[i]=NULL;
	if(p=bufs=malloc(LINES*MAXLEN)==NULL)
		printf("cannot allocate buf");
	bufend = bufs+ LINES*MAXLEN;

	last=0;
	nlines=0;
	while((len= _getline(line,MAXLEN))>0)
	{
		if(p+len+1>=bufend)
			p=bufs;
		lineptr[last]=p;
		strcpy(lineptr[last],line);
		if(++last>=LINES)
			last=0;
		p=p+len+1;
		nlines++;
	}
	if(n>nlines)
		n=nlines;
	first=last-n;
	if(first<0)
		first=first+LINES;
	for(i=first;--n>0;i=(i+1)%LINES)
		printf("%s",lineptr[i]);
	return 0;
}

int _getline(char s[],int lim)
{
	int c,i;
	for(i=0;i<lim-1 && (c=getchar())!=EOF && c!='\n';i++)
	{	
	        s[i]=c;
	}
	if(c=='\n')
	{
	        s[i]=c;
		++i;
	}
        s[i]='\0';
	return i;
}

