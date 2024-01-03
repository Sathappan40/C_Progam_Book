#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define HASHSIZE  100

struct nlist
{
	struct nlist* next;
	char *name;
	char *defn;
};

static struct nlist *hashtab[HASHSIZE];
unsigned hash(char *);
struct nlist *lookup(char*);
struct nlist *install(char*,char*);

unsigned hash(char*s)
{
	unsigned hashval;
	for(hashval=0; *s!='\0'; s++)
		hashval = *s+31*hashval;
	return hashval % HASHSIZE;
}

struct nlist *lookup(char *s)
{
    struct nlist *np;
    for (np = hashtab[hash(s)]; np != NULL; np = np->next)
        if (strcmp(s, np->name) == 0)
            return np; 
    return NULL;       
}

struct nlist *install(char *name, char *defn)
{
    struct nlist *np;
    unsigned hashval;
    if ((np = lookup(name)) == NULL)
    {
        np = (struct nlist *) malloc(sizeof(*np));
        if (np == NULL || (np->name = strdup(name)) == NULL)
            return NULL;
        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    }
    else                      
        free((void *) np->defn); 
    if ((np->defn = strdup(defn)) == NULL)
        return NULL;
    return np;
}

void undef(char* s)
{
	int h;
	struct nlist *prev,*np;
	prev = NULL;
	h=hash(s);
	for(np=hashtab[h]; np!=NULL; np=np->next)
	{
		if(strcmp(s,np->name)==0)
			break;
		prev=np;
	}
	if(np!=NULL)
	{
		if(prev==NULL)
			hashtab[h]=np->next;
		else
			prev->next = np->next;
		free((void*)np->name);
		free((void*)np->defn);
		free((void*)np);
	}
}

int main(int argc, char *argv[])
{
    struct nlist *table[4] = {
            (install("key", "value")), (install("key1", "value1")),
            (install("key2", "value2")), (install("key3", "value3"))};

    int i;
    for (i = 0; i < 4; i++)
    {
        printf("%s->%s\n", table[i]->name, table[i]->defn);
    }
    undef("key");
    undef("key3");
    struct nlist *result;
    char *keys[4] = {"key", "key1", "key2", "key3"};
    for (i = 0; i < 4; i++)
    {
        if ((result = lookup(keys[i])) == NULL)
       	{
            printf("key not found\n");
        }
       	else
       	{
            printf("%s->%s\n", result->name, result->defn);
        }
    }
    return 0;
}

