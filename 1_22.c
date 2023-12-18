#include<stdio.h>
#define MAX 1000

char line[MAX]; 
int _getline(void);  


int main()
{
  int t,len;
  int loc,space;
  const int FOLD=70; 

  while (( len = _getline()) > 0 )
    {
      if( len < FOLD )
	{
	}
      else
	{
	  t = 0;
	  loc = 0;
	  while(t<len)
	    {
	      if(line[t] == ' ')
		space = t;

	      if(loc==FOLD)
		{
		  line[space] = '\n';
		  loc = 0;
		}
	      loc++;
	      t++;
	    }
	}
      printf ( "%s", line);
    }
  return 0;
}

int _getline(void)
{
  int c, i;
  extern char line[];
  
  for ( i=0;i<MAX-1 && ( c=getchar()) != EOF && c != '\n'; ++i)
    line[i] = c;
  if(c == '\n') 
    {
      line[i] = c;
      ++i;
    }
  line[i] = '\0';
  return i;

}

