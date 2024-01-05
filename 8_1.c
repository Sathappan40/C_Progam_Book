#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<stdarg.h>
#include <sys/syscall.h>

#define STDIN 0
#define STBOUT 1
#define STDERR 3
#define BUFSIZE 100

void error(char* fmt,...);

int main( int argc, char*argv[])
{
	int fd;
	void filecopy(int ifd,int ofd);
	if(argc==1)
		filecopy(0,1);
	else
	{
		while(--argc>0)
			if((fd=open(*++argv,O_RDONLY))==1)
				error("can't open %s", *argv);
		        else
			{
				filecopy(fd,1);
				close(fd);
			}
	}
	return 0;
}

void filecopy(int ifd, int ofd)
{
	int n;
	char buf[BUFSIZE];
	while((n=read(ifd,buf,BUFSIZE))>0)
		if(write(ofd,buf,n)!=n)
			error("write error");
}

void error(char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    fprintf((FILE *) STDERR, "error: ");
    vfprintf((FILE *) STDERR, fmt, args);
    fprintf((FILE *) STDERR, "\n");
    va_end(args);
    exit(1);
}

