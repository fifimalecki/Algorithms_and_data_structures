#include <iostream>
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <algorithm>

using namespace std;

#ifndef _mergesort4_h_
#define _mergesort4_h_

template < class T >
inline  void
merge5l (T * p1, T * k1, T * p2, T *k2) 
{ register T* p=p2 - (k1-p1);
  while(true)
  {if(*p1<=*p2)
     {*p++=*p1++;
      if(p1==k1) return;
      }
   else
     {*p++=*p2++;
      if(p2==k2) break;
       }
  }
  do  *p++=*p1++;
  while(p1<k1);
}

template < class T >
inline  void
merge5r (T * p1, T * k1, T * p2, T *k2) 
{ register T* p=p2 - (k1-p1);
  while(true)
  {if(*p1<*p2)
     {*p++=*p1++;
      if(p1==k1) return;
      }
   else
     {*p++=*p2++;
      if(p2==k2) break;
       }
  }
  do  *p++=*p1++;
  while(p1<k1);
}



template < class T > 
inline void
copying_mergesort5_3 (T * p, T * k, T * t)
{
  if (k > p + 3)
    {
      T *s = p + ((k - p) >>1);
      copying_mergesort5_3 (s, k, t+(s-p));
      copying_mergesort5_3 (p, s, s);
      merge5l (s,s+(s-p),t+(s-p),t+(k-p));
    }
  else 
  if(k-p==3)
  { if(p[1]<=p[2])
      {t[1]=p[1];
       t[2]=p[2];
       }
    else
      {t[1]=p[2];
       t[2]=p[1];
       }
    if(*p<=t[1])
        {*t=*p;
	 return;
        }
     else
        {*t=t[1];
	 if(*p<=t[2])
	   {t[1]=*p;return;
	   }
	 else
	   {t[1]=t[2];t[2]=*p;return;
	   }
	 }  
	     	 
      
  
/*  if(p[1]<=p[2])
      {if(*p<=p[1])
         {*t=*p;t[1]=p[1];t[2]=p[2];
	 }
      else if(p[2]<*p)
         {* t=p[1];t[1]=p[2];t[2]=*p;
	 }
      else
         {* t=p[1];t[1]=*p;t[2]=p[2];
	 }
      }
    else      
      {if(*p<=p[2])
         {*t=*p;t[1]=p[2];t[2]=p[1];
	 }
      else if(p[1]<*p)
         {* t=p[2];t[1]=p[1];t[2]=*p;
	 }
      else
         {* t=p[2];t[1]=*p;t[2]=p[1];
	 }
      }  
*/      
  }
  else
  if(k-p==2)   
    if(*p<=p[1])
      {*t=*p;
       t[1]=p[1];
       }
       else
      {*t=p[1];
       t[1]=*p;
       } 
  else 
//   if(k>p) to jest niepotrzebne sprawdzenie !!!
    *t=*p;
         
}



// SORTUJE [p,k) w miejscu po³uguj±c siê buforem rozmiaru n/2
// BARDZO SZYBKIE DZIÊKI U¯YCIU merge4 i mergesort4(T*,T*,T*)
// Prawie dwa razy szybsze ni¿ pozosta³e wersje
template < class T > 
inline void
mergesort5 (T * p, T * k)
{
  if (k > p + 1)
    { 
      T *s = p + ((k - p) >> 1);
      T *bufor=new T[k-s];
      copying_mergesort5_3 (s, k,bufor);
      copying_mergesort5_3 (p, s,k-(s-p));
      merge5r (bufor,bufor+(k-s),k-(s-p),k);
      delete []bufor;
    }
}

#endif

template < class T >
inline void insert(T t[],int n, T x)
{
	while(t[n-1]>x)
	{
		t[n]=t[n-1];
		if(--n==0) break;
	}
   t[n]=x; 	
}


template < class T >
inline void isort(T t[], int n)
{
    for(int k=1;k<n;k++)
       insert(t,k,t[k]);
}



template < class T >
inline  void
merge (T * p1, T * k1, T * p2, T *k2) 
{ register T* p=p2 - (k1-p1);
  while(true)
  {if(*p1<=*p2)
     {*p++=*p1++;
      if(p1==k1) return;
      }
   else
     {*p++=*p2++;
      if(p2==k2) break;
       }
  }
  do  *p++=*p1++;
  while(p1!=k1);
}

template <class T>
void cmsort(T t[], int n,T b[]);

template <class T>
void bmsort(T t[], int n, T b[])
{
   if(n<7)
      isort(t,n);
   else
    {int k=(n+1)/2;
	 cmsort(t,k,b);
	 bmsort(t+k,n-k,t);
	 merge(b,b+k,t+k,t+n);
    }
}

template <class T>
void cmsort(T t[], int n,T b[])
{
   if(n<7)
      {isort(t,n);
       while(n--)
         b[n]=t[n];
      }
   else
    {int k=(n)/2;
	 cmsort(t+k,n-k,b+k);
	 bmsort(t,k,t+k);
	 merge(t,t+k,b+k,b+n);
    }
}


template <class T>
void msort(T t[], int n)
{
  T* b=new T[(n+1)/2];
  if(b)
    {bmsort(t,n,b);
     delete b;
    }
  else
    cerr<<"can't allocate array of size"<<(n+1)/2<<endl;
}



template <class T>
void pokaz(T t[], int n)
{
//	cout<<t[0]<<"\t";
	for(int i=1;i<n;i++) 
	   {//cout<<t[i]<<"\t";
	    if(t[i]<t[i-1]) throw("zle pozostowane");
       }
//	cout<<endl;
}

const int N=100000;
double t[N];


#include <sys/timeb.h>
#include <sys/time.h>
// pomiar czasu w milisekundach 
inline double
stoper ()
{
 struct timeval tv;
 gettimeofday (&tv, NULL);
 return tv.tv_sec+0.000001*tv.tv_usec;
}



double test(int i,int n)
{
  srand(1112);
  for(int j=0;j<n;j++)	
     t[j]=rand();
  
  const char *s=NULL;
  
  double time=-stoper();
  
  switch(i)
  {
  case 1:  mergesort5(t,t+n); s="merge5"; break;
  case 2:  msort(t,n);        s="merge "; break;
  case 4:  sort(t,t+n);       s="quick "; break;
case 0:

  case 3:  stable_sort(t,t+n);s="stable"; break;
  default: return 0;
  }
  
  time+=stoper();
  
  pokaz(t,n);	
  cout<<s<<"="<<time<<endl;
  return time;
}


int main()
{
  int n=N;
  
  double res[5]={};
  for(int i=0;i<5;i++)
    {test(i,N);
     res[i]+=test(i,N);
     res[i]+=test(i,N);
     res[i]+=test(i,N);
    }
  cout<< res[0]/res[3] 
  <<" "<<res[1]/res[3]
  <<" "<<res[2]/res[3]
  <<" "<<res[3]/res[3]
  <<" "<<res[4]/res[3]
  <<endl;  
}



