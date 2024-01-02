#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

#define MAXWORD 100
#define YES 1
#define NO 0

struct tnode
{
	char* word;
	int match;
	struct tnode* left;
	struct tnode* right;
};

struct tnode *addtree(struct tnode*, char*, int, int*);
void treeprint(struct tnode*);
int getword(char*, int);

int main(int argc, char*argv[])
{
	struct tnode* root;
	char word[MAXWORD];
	int found = NO;
	int num;
        num = (--argc && (*++argv)[0] == '-')? atoi(argv[0]+1) : 6;
	root =NULL;
	while(getword(word,MAXWORD)!=EOF)
	{
		if(isalpha(word[0]) && strlen(word)>num)
		{
			root=addtree(root,word,num,&found);
		}
		found = NO;
	}
	treeprint(root);
	return 0;
}

struct tnode *talloc(void);
int compare(char*, struct tnode*, int, int*);

struct tnode *addtree(struct tnode*p, char*w, int num, int *found)
{
	int cond;
	if(p==NULL)
	{
		p=talloc();
		p->word = strdup(w);
		p->match = *found;
		p->left = p->right = NULL;
	}
	else if((cond = compare(w,p,num,found))<0)
	{
		p->left=addtree(p->left,w,num,found);
	}
	else if(cond<0)
	{
		p->right = addtree(p->right,w,num,found);
	}
	return p;
}

void treeprint(struct tnode *p)
{
	if(p!= NULL)
	{
		treeprint(p->left);
		if(p->match)
		        printf("%s\n",p->word);
                treeprint(p->right);
	}
}

int compare(char*s, struct tnode*p,int num, int *found)
{
	int i;
	char*t=p->word;
	for(i=0; *s==*t; i++,s++,t++)
	{
		if(*s=='\0')
		{
			return 0;
		}
	}
	if(i>=num)
	{
		*found=YES;
		p->match=YES;
	}
	return *s-*t;
}

int getword(char *word, int lim)
{
    int c, getch(void);
    void ungetch(int);
    char *w = word;
    int t;
    while (isspace(c = getch()));
    if (c != EOF)
        *w++ = c;
    if (!isalpha(c))
    {
        if (c == '\"')
	{
            for (c = getch(); c != '\"'; c = getch());
        }
        else if (c == '#')
        {
            for (c = getch(); c != '\n'; c = getch());
        }
        else if (c == '/')
        {
            if ((c = getch()) == '/')
	    {
                for (c = getch(); c != '\n'; c = getch());
            }
	    else if (c == '*')
	    {
                for (c = getch(), t = getch(); c != '*' && t != '/';
                     c = getch(), t = getch())
                    ungetch(t);
            }
            else
                ungetch(c);
        }
        else 
            for (; !isspace(c) && c != EOF; c = getch());
        if (c != '\"' && c != '\n' && c != '/')
            ungetch(c);
        *w = '\0';
        return c;
    }

    for (; --lim > 0; w++)
    {	    
        if (!isalnum(*w = getch()))
        {
            if (!isspace(*w))
	    {
                ungetch(*w);
                return (*w);
            }
	    else
	    {
                ungetch(*w);
                break;
            }
        }
    }
    *w = '\0';
    return word[0];
}

#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;
int getch(void)
{
       	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

struct tnode *talloc(void)
{
	return (struct tnode*)malloc(sizeof(struct tnode));
}


