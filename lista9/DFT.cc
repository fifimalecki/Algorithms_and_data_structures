#include <iostream>
#include <complex>
#include <vector>
#include <cmath>

#define M_PI 3.14159265358979323846

using namespace std;

typedef complex<double> C;

void recursive_DFT(vector<C> & A, int n) // n=2^k;
{
    if(n==1) return;
    n/=2;
    vector<C> A0(n),A1(n);
    for(int i=0;i<n;i++)
    {
        A0[i]=A[2*i];
        A1[i]=A[2*i+1] ;
    }
    recursive_DFT(A0,n);
    recursive_DFT(A1,n);

    C w=exp(C(0,M_PI/n)); // pierwotny pierwiastek z 1
    C x=1;
    for(int i=0;i<n;i++)
    {

        A[i]=  A0[i]+x*A1[i];
        A[n+i]=A0[i]-x*A1[i];
        cout << A[i] << " " << A[n+i] << endl;
        x*=w; // kolejny pierwiastek z 1
    }
}

int reverse(int x, int n) // n musi być potęgą dwójki
{
    /*
     *  Odwrócenie bitowe liczby x
     */
    int wynik=0,i=1;
    while(n>>=1)
    {
        if(x&i)
            wynik|=n;
        i<<=1;
    }
    return wynik;
}

void bitreverse(vector<C>&A, int n) // n jest potęgą 2
{
    /*
     *  Zmiana kolejności współczynników wielomianu
     *  na kolejność bitowo odwróconą
     */
    for(int i=0;i<n;i++)
    {
        int j=reverse(i,n);
        if(i<j)
            swap(A[i],A[j]);
    }
}

void iterative_DFT(vector<C>& A) // n jest potegą 2
{
    /*
     *  iterative_DFT przepisane z Cormena
     */

    int n=A.size();
    bitreverse(A,n);
    for(int m=1;m<n;m*=2)
    {
        C w=exp(C(0,M_PI/m)); // pierwotny pierwiastek z 1;
        for(int k=0;k<n;k+=2*m)
        {
            C x=1;
            for(int j=0;j<m;j++)
            {
                C u=A[k+j];
                C t=A[k+j+m]*x;
                A[k+j]=u+t;
                A[k+j+m]=u-t;
                x*=w;
            }
        }
    }
}


int main()
{
    vector<C> A{1,5,3,1}, B=A;

    int n=A.size(); // n musi być potęgą dwójki

    recursive_DFT(A,n);
    for(auto x:A)
        cout<<x<<' ';
    cout<<endl;

    iterative_DFT(B);
    for(auto x:B)
        cout<<x<<' ';
    cout<<endl;

    cout<<"Obie metody dają ten sam wynik"<<endl;
}
