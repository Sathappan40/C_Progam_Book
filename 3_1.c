#include<stdio.h>
int bisearch(int x,int v[],int n);

int main()
{
	int arr[]={1,3,6,8,10,14,20,30,45,54,57};
	printf("%d",bisearch(8,arr,10));
	return 0;
}

int bisearch(int x,int v[],int n)
{
         int l,h,m;
	 h=n-1;
	 m=l+h/2;
	 while(l<h && x!=v[m])
	 {
	      if(x>v[m])
	      {
	         l=m+1;
	      }
	      else
	      {
	         h=m-1;
	      }
	      m=l+h/2;
	 }
	 if(x==v[m])
         {
		 return m;
         }
	 else
		 return -1;
}

