#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

#define NUMERIC 1
#define DECR 2
#define FOLD 4
#define DIRC 8
#define LINES 100
#define MAX 1000
#define ALLOCSIZE 1000
#define MAXSTR 100

int charcmp(char* ,char*);
int numcp(char*,char*);
void readargs(int argc, char* argv[]);
int readlines(char* lineptr[],int maxlines);
void substr(char* s,char*t);
void myqsort(void* v[],int left, int right, int(*comp)(void*,void*));
void writelines(char* lineptr[],int nlines,int decr);
int _getline(char* , int);
char* alloc(int);

static int option=0;
int pos1=0;
int pos2=0;

int main(int argc, char *argv[])
{
	char *lineptr[LINES];  
        int nlines;        
        int rc = 0;
        readargs(argc, argv);
        if ((nlines = readlines(lineptr, LINES)) > 0)
       	{
                if (option & NUMERIC)
                        myqsort((void **) lineptr, 0, nlines - 1, (int (*)(void *, void *)) numcp);
                else
                        myqsort((void **) lineptr, 0, nlines - 1, (int (*)(void *, void *)) charcmp);

                writelines(lineptr, nlines, option & DECR);
        }
       	else
       	{
                printf("input too big to sort \n");
                rc = -1;
        }
        return rc;
}

void readargs(int argc, char *argv[])
{
    int c;
    int atoi(char* );
    while (--argc > 0 && (c = (*++argv)[0]) == '-' || c == '+')
    {
        if (c == '-' && !isdigit(*(argv[0] + 1)))
	{
            while (c = *++argv[0])
            {
                switch (c)
	       	{
                    case 'd':    
                        option |= DIRC;
                        break;
                    case 'f':
                        option |= FOLD;
                        break;
                    case 'n':
                        option |= NUMERIC;
                        break;
                    case 'r':
                        option |= DECR;
                        break;
                    default:
                        printf(" illegal option %c \n", c);
                        break;
                }
            }
	}
        else if (c == '-')
            pos2 = atoi(argv[0] + 1);
        else if ((pos1 = atoi(argv[0] + 1)) < 0)
            printf("Usage: sort ");
    }
    if (argc || pos1 > pos2)
        printf("Usage: sort");
}

void writelines(char *lineptr[],int nlines, int decr)
{
	int i;
	if(decr)
		for(i=nlines-1; i>=0 ;i--)
			printf("%s\n", lineptr[i]);
	else
		for(i=0;i<nlines;i++)
			printf("%s\n",lineptr[i]);
}

int numcp(char* s1,char* s2)
{
	double v1,v2;
	char str[MAXSTR];
	substr(s1,str);
	v1=atof(str);
	substr(s2,str);
	v2=atof(str);
	if(v1<v2)
		return -1;
	else if(v1>v2)
		return 1;
	else
		return 0;
}

int charcmp(char* s,char* t)
{
	char a,b;
	int i,j,endpos;
	extern int option,pos1,pos2;
	int fold = (option & FOLD)?1:0;
	int dir=(option & DIRC)?1:0;
	i=j=pos1;
	if(pos2>0)
		endpos=pos2;
	else if((endpos=strlen(s))>strlen(t))
		endpos=strlen(t);
	do
	{
		if(dir)
		{
			while(i<endpos && !isalnum(s[i]) && s[i]!=' ' && s[i]!='\0')
			        i++;
			while(j<endpos && !isalnum(t[j]) && t[j]!=' ' && t[j]!='\0')
			        j++;
		}
		a=fold?tolower(*s):*s;
		s++;
		b=fold?tolower(*t):*t;
                t++;
		if(a==b && a=='\0')
			return 0;
	}while(a==b);
	return a-b;
}

void substr(char *s, char *str)
{
    int i, j, len;
    extern int pos1, pos2;
    len = strlen(s);
    if (pos2 > 0 && len > pos2)
        len = pos2;
    else if (pos2 > 0 && len < pos2)
        printf("string too short");
    for (j = 0, i = pos1; i < len; i++, j++)
        str[j] = str[i];
    str[j] = '\0';
}

int readlines(char* lineptr[],int maxlines)
{
	int len,nlines;
	char* p,line[MAX];
	nlines=0;
	while(len=_getline(line,MAX)>0)
	{
		if(nlines>MAX || (p=alloc(len))==NULL)
			return -1;
		else
		{
			line[len-1]='\0';
			strcpy(p,line);
			lineptr[nlines++]=p;
		}
		return nlines;
	}
}

void myqsort(void*v[],int left,int right,int (*comp)(void*,void*))
{
	int i,last;
	void swap(void*v[],int ,int );
	if(left>=right)
		return ;
	swap(v,left,(left+right)/2);
	last=left;
	for(i=left+1;i<=right;i++)
	{
		if((*comp)(v[i],v[left])<0)
			swap(v,last++,i);
	}
	swap(v,left,last);
	myqsort(v,left,last-1,comp);
	myqsort(v,last+1,right,comp);
}

void swap(void*v[],int i,int j)
{
	void* temp;
	temp=v[i];
	v[i]=v[j];
	v[j]=temp;
}

int _getline(char s[],int lim)
{
	int c,i;
	for(i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; i++)
			s[i]=c;
	if(c=='\n')
	{
		s[i]=c;
		++i;
	}
	s[i]='\0';
	return i;
}

static char allocbuf[ALLOCSIZE];
static char *allocp=allocbuf;

char*alloc(int n)
{
	if(allocbuf+ALLOCSIZE-allocp>=n)
	{
		allocp=allocp+n;
		return allocp-n;
	}
	else
		return 0;
}
