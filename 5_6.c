int _getline(char*s,int max)
{
	int c;
	char* t;
	while(--max>0 && (c=getchar())!=EOF && c!='\n')
	{
		*s++=c;
	}
	if(c=='\n')
	{
		*s++=c;
	}
	*s='\0';
	return s-t;
}

void reverse(char*s)
{
	int c;
	char* t;
	for(t=s+strlen(s); s<t; s++,t--)
	{
		c=*s;
		*s=*t;
		*t=c;
	}
}

void atoi(char* s)
{
	int n,sign;
	for(;isspace(*s);s++)
		;
	sign=(*s=='-')?-1:1;
	if(*s=='+' || *s=='-')
		s++;
	for(n=0;isdigit(*s);s++)
		n=10*n+(*s-'0');
	return sign*n;
}

void itoa(int n,char* s)
{
	int sign;
	char* t= s;
	if((sign=n)<0)
		n=-n;
	do
	{
		*s++=n%10+'0';
	}while((n=n/10)>0)
	if(sign<0)
		*s++='-';
	*s='\0';
}

int getop(char *s)
{
    int c;
    while ((*s = c = getch()) == ' ' || c == '\t')
	    ;
    *(s + 1) = '\0';

    if (!isdigit(c) && c != '.')
        return c;     
    if (isdigit(c))
        while (isdigit(*++s = c = getch()));
    if (c == '.')
        while (isdigit(*++s = c = getch()));

    *s = '\0';

    if (c != EOF)
        ungetch(c);
    return NUMBER;
}

int strindex(char* s,char* t)
{
	char* b =s;
	char* p, char*q;
	for(;*s!='\0';s++)
	{
		for(p=s,q=t; *q!='\0' && *p==*q; p++,q++)
			;
		if(q>t && *q=='\t')
			return s-b;
	}
	return -1;
}

