#include <sys/timeb.h>
#include <sys/time.h>
#include <iostream>
#include <cmath>

using namespace std;

const int N=200000;

// POMIAR CZASU
double stoper ()
{
 static double t=0;
 double t1=t;
 struct timeval tv;
 gettimeofday (&tv, NULL);
 t=tv.tv_sec+0.000001*tv.tv_usec;
 return t-t1;  // zwraca czas jaki upłynął od poprzedniego wywołania
}


// INSERTION SORT (EDUCATIONAL VERSION)
void insertion_sort (double t[], int n)
{
    int counter = 0;
  for (int k = 1; k < n; k++)
  {
    for(int i = k; i > 0 && t[i-1] > t[i]; i--)
    {
        cout<<++counter<<" "<<i<<" "<<t[i-1]<< ">"<<t[i]<<endl;
	    std::swap(t[i],t[i - 1]);
    }
   // cout<<++counter<<endl;
  }
}


// INSERTION SORT (OPTIMIZED) 3 razy szybsza
void insertion_sort2 (double t[], int n)
{
  int i;
  for (int k = 1; k < n; k++)
  {
    double x = t[k];
    for(i=k; i > 0 && t[i-1] > x; i--)
	    t[i] = t[i - 1];
    t[i] = x;
  }
}

// INSERTION SORT SENTINEL
inline void sort2(double &a, double &b)
{
  if(a>b) {double c=a;a=b;b=c;}
}

inline void wstaw_z_wartownikiem(double *t, double x)
{
  while(*--t>x)
    t[1]=t[0];
  t[1]=x;
}

void sortuj_z_wartownikiem(double t[],int n)
{
  // ustaw najmniejszy na poczatku
  for(int j=n-1;j>0;j--)
    sort2(t[j-1],t[j]);
  // posortuj pozostałe elementy traktując t[0] jako wartownika
  for(int i=2;i<n;i++)
    wstaw_z_wartownikiem(t+i,t[i]);
}


// HEAP SORT

void przesiej2 (double t[],  int n, int i)
{
  int k;
  double x = t[i]; //przesiewany element
  while (true)
    {
      k = 2 * i + 2; //prawy syn 'x'-a
      if( (k<n && t[k]>x && t[k]>t[k-1]) // prawy syn istnieje i jest większy od ojca i brata
          ||                             // lub
          (--k<n && t[k]>x))             // lewy syn istnieje i jest większy od ojca
      {
        t[i] = t[k];  // podsuń syna w górę
          i  =   k;   // przejdź w dół
      }
      else
      {
        t[i] = x;    // zapisz x w nowym miejscu
        return;
      }
    }
}

void  heap_sort (double t[],int n)
{
  // Budowanie kopca
  for (int i = n/2; i >= 0; i--)
    przesiej2 (t, n, i);

  // Oproznianie kopca
  while (--n)
  {
      std::swap(t[0],t[n]);
      przesiej2 (t,n,0);
  }
}


// MERGE SORT

double b[N];

void merge(int n,int k,double t[], double b[])
{
  int i=0,j=k,l=0;
  while (i<k && j<n)
    if(t[i]<=t[j]) b[l++]=t[i++];
    else           b[l++]=t[j++];
  while(i<k)
    b[l++]=t[i++];
  for(i=0;i<j;i++)
    t[i]=b[i];
}

void merge_sort(double t[],int n)
{
  if(n>1)
  {
    int k=n/2;
    merge_sort(t,k);
    merge_sort(t+k,n-k);
    merge(n,k,t,b);
  }
}

// QUICK SORT
int partition (double t[], int n)
{
  int k = -1;
  double x = t[n / 2];
// pivot bierzemy posrodku
  for(;;)
  {
     while (t[--n] > x);
     while (t[++k] < x);
     if (k < n){std::swap(t[k],t[n]);}
     else       return k;
  }
}

void quick_sort (double t[], int n)
{
  if (n > 1)
  {
    int k = partition (t,n); //podziel na dwie czesci
    quick_sort (t,k);	     //posortuj lewa
    quick_sort (t+k,n-k);    //posortuj prawa
  }
}

//COUNTING SORT

void counting_sort(double t[], int n, double b[],int max)
{
   int ile[max]={0};  // liczniki
   for(int i=0;i<n;i++)  // zliczanie
      ile[int(t[i])]++;
   for(int i=1;i<max;i++)  //akumulacja
      ile[i]+=ile[i-1];
   for(int i=n-1;i>=0;i--)  // wpis do bufora
      b[--ile[int(t[i])]]=t[i];
   for(int i=0;i<n;i++)    // przepisanie
      t[i]=b[i];
}


// RADIX SORT

void radix_sort(double t[], int n)
{ int u=1000; // Udajemy że jest 1000 cyfr (0,...,999)
  int max=0;
  double *b=new double[n]; // tworzymy bufor
  double *t_orig=t;
  double *b_orig=b;

  //wyznaczamy maksimum
  for(int i=0;i<n;i++)
     if(t[i]>max)
       max=t[i];

  //u=ceil(sqrt(max)); // w ukladzie o u cyfrach bedziemy mieli liczby 2 cyfrowe

  // sortowanie według kolejnych "cyfr" od końca
  for(int r=1;r<=max;r*=u)
  {
      int ile[u]={0};  // liczniki

      for(int i=0;i<n;i++)  //zliczanie
        ile[int(t[i])/r%u]++;
      for(int i=1;i<u;i++)  //akumulacja
        ile[i]+=ile[i-1];
      for(int i=n-1;i>=0;i--) //wpis do bufora
        b[--ile[int(t[i])/r%u]]=t[i];

      std::swap(t,b);  // zamiana ról tablicy i bufora
  }

  if(t!=t_orig)           // jeśli trzeba
    for(int i=0;i<n;i++)  // kopiujemy do tablicy wyjściowej
      t_orig[i]=t[i];

  delete b_orig;  //usuwamy bufor
}

// BUCKET SORT
void bucket_sort(double t[], int n)
{
  //szukamy maximum i minimum
  double max=t[0],min=t[0];
  for(int i=1;i<n;i++)
     if(t[i]< min) min=t[i];
     else if(t[i]>max) max=t[i];

  if(max==min) return;

  double u=n/(max-min)/2;    // zakładamy przeciętnie po 2 liczby w kubełku
  double *b=new double[n];

  //counting sort
  int ile[n/2+2]={0};  // liczniki

  for(int i=0;i<n;i++)  // zliczanie
     ile[int((t[i]-min)*u)]++;
  for(int i=1;i<u;i++)  //akumulacja
     ile[i]+=ile[i-1];
  for(int i=n-1;i>=0;i--)  // wpis do bufora
     b[--ile[int((t[i]-min)*u)]]=t[i];

  // insertion sort
  int i;
  t[0]=b[0];
  for (int k = 1; k < n; k++)
    {
      double x = b[k];
      for(i=k; i > 0 && t[i-1] > x; i--)
	 t[i] = t[i - 1];
      t[i] = x;
    }

  delete b;
}

// SPRAWDZENIE

bool check(double t[], int n, string s)
{  for(int i=1;i<n;i++)
     if(t[i]<t[i-1])
     {
	cout<<s<<" error."<<endl;
	return false;
     }

   cout<<s<<" ok."<<endl;
   return true;
}

void kopia(double t1[],double t2[],int n)
{
    for(int i=0;i<n;i++)
       t2[i]=t1[i];
}

void wypisz(double t[],int n)
{
    for(int i=0;i<n;i++)
       cout<<t[i]<<" ";
    cout<<endl;
}


double orig[N],t[N];

int main()
{
    double t1[7] = {1,2,3,4,5,6,7};
    double t2[7] = {7,6,5,4,3,2,1};

    insertion_sort(t2,7);
    //insertion_sort(t1,7);
//
//    for(int i=0;i<N;i++)
//        orig[i]=rand()%N;
//
//    if(N<100000) wypisz(orig,N);
//
//    kopia(orig,t,N);
//    stoper(); heap_sort(t,N); cout<<stoper()<<" ";
//    check(t,N,"heap_sort");
//
//    kopia(orig,t,N);
//    stoper(); merge_sort(t,N); cout<<stoper()<<" ";
//    check(t,N,"merge_sort");
//
//
//    kopia(orig,t,N);
//    stoper();  quick_sort(t,N); cout<<stoper()<<" ";
//    check(t,N,"quick_sort");
//
//    kopia(orig,t,N);
//    stoper();  radix_sort(t,N); cout<<stoper()<<" ";
//    check(t,N,"radix_sort");
//
//    kopia(orig,t,N);
//    stoper();  counting_sort(t,N,b,N+1); cout<<stoper()<<" ";
//    check(t,N,"counting_sort");
//
//    kopia(orig,t,N);
//    stoper();  bucket_sort(t,N); cout<<stoper()<<" ";
//    check(t,N,"bucket_sort");
//
//    if(N<300000) // Nie chcemy czekać ponad minutę na wynik
//    {
//        kopia(orig,t,N);
//        stoper(); insertion_sort(t,N); cout<<stoper()<<" ";
//        check(t,N,"insertion_sort");
//
//        kopia(orig,t,N);
//        stoper(); insertion_sort2(t,N); cout<<stoper()<<" ";
//        check(t,N,"insertion_sort2");
//
//        kopia(orig,t,N);
//        stoper(); sortuj_z_wartownikiem(t,N); cout<<stoper()<<" ";
//        check(t,N,"insertion_sort3");
//    }
//

}
