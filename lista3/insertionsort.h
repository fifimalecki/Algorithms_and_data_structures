#ifndef _insertionsort_h_
#define _insertionsort_h_
#include <limits>
//wersja bez wartownika
template <class T>
void insertionsort (T *p,T*k)
{ for(T *s=p+1;s<k;s++)
  {T x=*s;
   T *s1=s;
   while(p<s1 && *(s1-1) >x)
     {*s1=*(s1-1) ;
      --s1;
      }
   *s1=x;
   } 
}

template <class T>
void insertionsort1 (T *p,T*k)
{ for(T *s=p+1;s<k;s++)
  {T x=*s;
   T *s1=s;
   if(p[0]<=x)
   for(;x<s1[-1];--s1)
      *s1=s1[-1] ;
   else 
   for(;p<s1;s1--)
      *s1=s1[-1] ;
   *s1=x;
   } 
}

//element nie mniejszy niz key
template <class T> 
inline T* find (T* p,T *k, T key)
{   T*s;
     while(k>p+1)
       {s=p+((k-p)>>1);    
//        s=1;
        if(*s<=key) p=s;
          else k=s;
	}  
  if (*p<key) p=k;		
  return p;      
}    

template <class T>
inline void move_up(T *p, T*k)
{while(p<k)
   {*k=k[-1];
    k--;
    }
}


template <class T>
void insertionsort_b(T*p,T*k)
{ T x,*y; 
  for(T* s=p+1;s!=k;s++)
    { x=*s;
      y=find(p,s,x);
//      std::cout<< x<< ' '<<*y<<std::endl;
      move_up(y,s);
      *y=x;
     }     
} 



//wersja z wartownikiem (bardzo dobra)
template <class T>
void insertionsort_s (T *p,T*k)
{ T y=*p;
  *p=std::numeric_limits<T>::min();
  for(T *s=p+2;s<k;s++)
  {T x=*s;
   T *s1=s;
   while( *(--s1) >x)
     *(s1+1)=*s1;
   *(s1+1)=x;
   }  

  while(++p<k && *p<y)
     *(p-1)=*p;
  *(p-1)=y;     
       
}
// wersja bez szablonu nie jest szybsza
void insertionsort_sd (double *p,double *k)
{ double y=*p;
  *p=std::numeric_limits<double>::min();
  for(double *s=p+2;s<k;s++)
  {double x=*s;
   double *s1=s;
   while( *(--s1) >x)
     *(s1+1)=*s1;
   *(s1+1)=x;
   }  

  while(++p<k && *p<y)
     *(p-1)=*p;
  *(p-1)=y;     
       
}

//wersja z wartownikiem za tablica (niebezpeczna i wolniejsza od poprzedniej)
template <class T>
void insertionsort_ss (T *p,T*k)
{ T y=p[-1]; 
  p[-1]=std::numeric_limits<T>::min();
  for(T *s=p+1;s<k;s++)
  {T x=*s;
   T *s1=s;
   while( *(--s1) >x)
     *(s1+1)=*s1;
   *(s1+1)=x;
   }  
  p[-1]=y; 
}

#endif
