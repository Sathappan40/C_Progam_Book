#include<stdio.h>

int day_of_year(int year,int month,int day);
void month_day(int year,int yearday,int* month,int* day);

static char daytab[2][13]={ {0,31,28,31,30,31,30,31,31,30,31,30,31},
	                   {0,31,29,31,30,31,30,31,31,30,31,30,31} };

int main()
{
	int yearday,month,day;
	yearday = day_of_year(2009,3,18);
	printf("%d ",yearday);
	month_day(2022,97,&month,&day);
	printf("day-%d  month-%d", month,day);
	return 0;
}

int day_of_year(int year,int month,int day)
{
	int i,leap;
	leap= year%4==0 && year%100!=0 || year%400==0;
	if(year<1 || month<1 || month>12 || day<1 || day>*(*(daytab+leap)+i))
		return -1;
	for(i=0;i<month;i++)
		day=day+*(*(daytab+leap)+i);
	return day;
}

void month_day(int year,int yearday,int* month,int* day)
{
	int leap,i;
	leap= year%4==0 && year%100!=0 || year%400==0;
	if(year<1 || yearday<1 || yearday>(leap?366:365))
		*month = *day=-1;
	for(i=1;yearday>*(*(daytab+leap)+i);i++)
		yearday=yearday-*(*(daytab+leap)+i);
	*month=i;
	*day=yearday;
}

