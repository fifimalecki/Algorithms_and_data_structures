#include <iostream>
#include <cstdlib>
#include <time.h>
#include <algorithm>

using namespace std;


void hcmerge(int t1[], int k1, int t[], int k)
{
	int j=k1,i=0,l=0;
	for(;;)
	{
		if(t1[i]<=t[j])
		{
			t[l++]=t1[i++];
			if(i==k1) return;
		}
		else
		{
			t[l++]=t[j++];
			if(j==k)
			{
				do{
					t[l++]=t1[i++];
				}while(i!=k1);
				break;	
			}
		}
	}
}

void cms(int t[], int n, int b[]);

void ipms(int t[], int n, int b[])
{
	if(n>1)
	{
		cms(t,n/2,b);
		ipms(t+n/2,n-n/2,t);
		hcmerge(b,n/2,t,n);
	}
}

void cms( int t[], int n, int b[])
{
	if(n>1)
	{
		cms(t+n/2,n-n/2,b+n/2);
		ipms(t,n/2,t+n/2);
		hcmerge(t,n/2,b,n);
	}
	else
	*b=*t;
}



int main()
{
  int t[]={4,15,13,3,14,12,3,2,3,-4,4,222,1231,10 ,19, 9 ,12};
  int n=sizeof(t)/sizeof(*t);
  for(int i=0;i<n;i++)
	cout<<t[i]<<" ";
  int b[n/2];
  ipms(t,n,b);
  cout<<endl;
  for(int i=0;i<n;i++)
	cout<<t[i]<<" ";
  
  
}



