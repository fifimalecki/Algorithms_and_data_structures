#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int FindX(int x, int tab[], int n)
{
    int min = 0;
    int max = n-1;
    int temp = (min+max)/2;
    int counter = 0;
    while(min < max)
    {
        counter++;
        temp = (min+max)/2;
        if(tab[temp] < x)
            min = temp + 1;
        else
            max = temp - 1;
    }
    return counter;
}

int FindX2(int tab[], unsigned tab_size, int x)
{
    unsigned a=0,b=tab_size-1,c;
    while(a<b)
    {
        c=(a+b)/2;
        if(tab[c]<x)
            a = c+1;
        else
            b = c;
    }
    return x==tab[a]?a:-1;
}

void insertion_sort(int A[], int n)
{
int key, i;
for(int j = 1; j < n; j++)
{
    key = A[j];
    i = j-1;
	while( i >= 0 && A[i] > key)
	{
		A[i+1] = A[i];
		i = i - 1;
    }
    A[i+1] = key;
}
}
//
//void merge_sort(int A[],int p, int r)
//{
//    int q;
//    if(p < r)
//    {
//        q = (p+r)/2;
//        merge_sort(A,p,q);
//        merge_sort(A,q+1,p);
//        merge(A,p,q,r);
//    }
//}

int partition(int A[], int p, int r)
{
    int x = A[p];
    int i = p - 1;
    int j = r + 1;
    while(true)
    {
        while(A[j] <= x) j--;
        while(A[i] >= x) i++;
        if( i < j )
            swap(A[i],A[j]);
        else
            return j;
    }
}

void quicksort(int A[],int p, int r)
{
    if(p < r)
    {
        int q = partition(A,p,r);
        quicksort(A,p,q);
        quicksort(A,q+1,r);
    }
}

void counting_sort(int A[], int B[], int k)
{
    int C[k];
    int n = k;
    for(int i = 0; i < k; i++)
        C[i] = 0;
    for(int i = 0; i < n; i++)
        C[A[i]] = C[A[i]]+1;
    for(int i = 1; i < k; i++)
        C[i] = C[i] + C[i - 1];
    for(int i = n; i > 0; i--)
    {
        B[C[A[i]]] = A[i];
        C[A[i]] = C[A[i]] -1;
    }
}

int main()
{
    unsigned n = 10;
    int tab[n] = {10,9,8,7,6,5,4,3,2,1};
//    int b[n];
//
//    for(int i = 0; i < n; i++)
//        cout << tab[i] << " ";
//    cout << endl;
//
//    counting_sort(tab,b,n);
//
//    for(int i = 0; i < n; i++)
//        cout << b[i] << " ";
//    cout << endl;
    cout << FindX2(tab,n,10);
    //log2(N)+1
}
