#include <stdio.h>
#include<string.h>
#define MAXLINE 100

int main(int argc, char *argv[])
{
    FILE *fp1, *fp2;
    void filecomp(FILE *, FILE *);
    if (argc == 1)
    {
        printf("Please provide two files");
        return 1;
    }
    else
        while (--argc > 0)
       	{
            if ((fp1 = fopen(argv[1], "r")) == NULL)
	    {
                printf("can't open %s\n", *argv);
                return 1;
            }
            if ((fp2 = fopen(argv[2], "r")) == NULL)
	    {
                printf("can't open %s\n", *argv);
                return 1;
            }
            filecomp(fp1, fp2);
            fclose(fp1);
            fclose(fp2);
        }
    return 0;
}

void filecomp(FILE *fp1, FILE *fp2)
{
	char line1[MAXLINE], line2[MAXLINE];
	char *lp1, *lp2;
	do
	{
		lp1=fgets(line1,MAXLINE,fp1);
		lp2=fgets(line2,MAXLINE,fp2);
		if(lp1==line1 && lp2==line2)
		{
			if(strcmp(line1,line2)!=0)
			{
				printf("difference in : %s\n",line1);
				lp1=lp2=NULL;
			}
		}
		else if(lp1!=line1 && lp2==line2)
			printf("end of first file at line : %s",line2);
		else if(lp1==line1 && lp2!=line2)
			printf("end of second file at line: %s",line1);
	}while(lp1==line1 && lp2==line2);
}

char *fgets(char *s, int n, FILE *iop)
{
	register int c;
	register char *cs;
	cs = s;
	while (--n > 0 && (c = getc(iop)) != EOF)
		if ((*cs++ = c) == '\n')
			break;
	*cs = '\0';
	return (c == EOF && cs == s) ? NULL : s;
}

