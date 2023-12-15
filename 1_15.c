
# include <stdio.h> 
float conv(int fahr)
{
      float cel;
      cel= (5.0/9.0)*(fahr-32.0);
      return cel;
}
int main()
{
    int f,i;
    for(i=0;i<=300;i=i+20)
    {
      f=i;
      printf("%d\t%f\n",f,conv(f));
    }
    return 0;
}
