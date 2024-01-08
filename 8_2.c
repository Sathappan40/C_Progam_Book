#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/syscall.h>
#include <stdarg.h>
#include <unistd.h>

#ifdef NULL
#undef NULL
#endif

#define NULL 0
#define EOF (-1)
#define BUFSIZE 1024
#define OPEN_MAX 20 
#define PERMS 0666

typedef struct _iob
{
    int cnt;    
    char *ptr;  
    char *base; 
    struct flag_field
    {
	unsigned is_read : 1;
	unsigned is_write : 1;
	unsigned is_unbuf : 1;
	unsigned is_buf : 1;
	unsigned is_eof : 1;
	unsigned is_err : 1;
    }flag;  
    int fd;   
} _FILE;

extern _FILE _iob[OPEN_MAX];

#define stdin (&_iob[0])
#define stdout (&_iob[1])
#define stderr (&_iob[2]) 

#define feof(p) (((p)->flag & _EOF) != 0)
#define ferror(p) (((p)->flag & _ERR) != 0)
#define fileno(p) ((p)->fd)

#define getc(p) (--(p)->cnt >= 0 ? (unsigned char)*(p)->ptr++ : _fillbuf(p))
#define putc(x, p) (--(p)->cnt >= 0 ? *(p)->ptr++ = (x) : _flushbuf((x), p))
#define getchar() getc(stdin)
#define putchar(x) putc((x), stdout)

_FILE* _fopen(char*, char*);
int fillbuf(_FILE *);

_FILE* _fopen(char* name, char* mode)
{
	int fd;
	_FILE* fp;
	if(*mode!='r' && *mode!='w' && *mode!='a')
		return NULL;
	for(fp=_iob; fp < _iob+OPEN_MAX; fp++)
		if(fp->flag.is_read ==0 && fp->flag.is_write==0)
			break;
	if(fp>=_iob+OPEN_MAX)
		return NULL;
	if(*mode=='w')
		fd=creat(name,PERMS);
	else if(*mode=='a')
	{
		if(fd=open(name, O_RDONLY, 0)==-1)
			fd = creat(name,PERMS);
		lseek(fd, 0L, 2);
	}
	else
		fd=open(name, O_RDONLY, 0);
	if(fd==-1)
		return NULL;
	fp->fd = fd;
	fp->cnt = 0;
	fp->base = NULL;
	fp->flag.is_unbuf=0;
	fp->flag.is_buf=1;
	fp->flag.is_eof=0;
	fp->flag.is_err=0;
	if(*mode=='r')
	{
		fp->flag.is_read = 1;
		fp->flag.is_write = 0;
	}
	else
	{
		fp->flag.is_read = 0;
		fp->flag.is_write = 1;
	}
	return fp;
}

int fillbuf(_FILE*fp)
{
	int bufsize;
	if(fp->flag.is_read == 0 || fp->flag.is_eof == 1 || fp->flag.is_err ==1)
		return EOF;
	bufsize = (fp->flag.is_unbuf==1)?1:BUFSIZE;
	if(fp->base==NULL)
		if((fp->base= (char*)malloc(bufsize))==NULL)
			return EOF;
	fp->ptr = fp->base;
	fp->cnt = read(fp->fd, fp->ptr, bufsize);
	if(--fp->cnt<0)
	{
		if(fp->cnt == -1)
			fp->flag.is_eof = 1;
		else
			fp->flag.is_err = 1;
		fp->cnt=0;
		return EOF;
	}
	return (unsigned char)*fp->ptr++;
}

int _flushbuf(int c, _FILE *fp) 
{
    int num_written, bufsize;
    unsigned char uc = c;

    if (((fp->flag.is_write | fp->flag.is_eof | fp->flag.is_err)) != fp->flag.is_write) 
    {
        return EOF;
    }

    if (fp->base == NULL && (fp->flag.is_unbuf) == 0)
    {
        if ((fp->base = malloc(BUFSIZE)) == NULL)
            fp->flag.is_unbuf=1;
        else 
        {
            fp->ptr = fp->base;
            fp->cnt = BUFSIZE - 1;
        }
    }

    if (fp->flag.is_unbuf) 
    {
        fp->ptr = fp->base = NULL;
        fp->cnt = 0;
        if (c == EOF) 
        {
            return EOF;
        }
        num_written = write(fp->fd, &uc, 1);
        bufsize = 1;
    } 
    else 
    {
        bufsize = (int) (fp->ptr - fp->base);
        num_written = write(fp->fd, fp->base, bufsize);
        fp->ptr = fp->base;
        fp->cnt = BUFSIZE - 1;
    }

    if (num_written == bufsize)
        return c;
    else 
    {
        fp->flag.is_err=1;
        return EOF;
    }
}


int main(int argc, char *argv[])
{
    int c;
    while ((c = getchar()) != 'x')
    {
        putchar(c);
    }
}

