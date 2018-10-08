#include <iostream>
#include <complex>
#include <vector>

#define M_PI 3.14159265358979323846

using namespace std;

typedef complex<double> C;

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

void bitreverse(vector<C>&A, int n)
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

void DFT(vector<C>& A, int inv=1)
{
    /*
     *  DFT przepisane z Cormena
     *  int = -1 gdy transformata odwrotna
     */

    int n=A.size();
    bitreverse(A,n);
    for(int m=1;m<n;m*=2)
    {
        C w=exp(C(0,M_PI/m*inv)); // pierwotny pierwiastek z 1;
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
    if(inv==-1)
        for(C& x:A)
            x/=n;
}

void Mnoz_DFT(vector<C> A,vector<C> B, vector<C>& X)
{
    /*
     *  Mnożenie z wykorzystaniem DFT
     */
    int n=A.size()+A.size()-1; // Rozmiar wielomianu wynikowego
    int m=1;
    while(m<n)
        m*=2;
    A.resize(m,0);
    B.resize(m,0);
    DFT(A);
    DFT(B);
    X.resize(m);
    for(int i=0;i<m;i++)
        X[i]=A[i]*B[i];
    DFT(X,-1);
    X.resize(n);
}

void Mnoz(vector<C> A,vector<C> B, vector<C>& X)
{
    int n=A.size()+A.size()-1; // Rozmiar wielomianu wynikowego
    X=vector<C>(n,0);
    for(size_t i=0;i<A.size();i++)
        for(size_t j=0;j<B.size();j++)
            X[i+j]+=A[i]*B[j];
}



void pokaz(vector<C> A)
{
   for(auto x:A)
        cout<<x<<' ';
    cout<<endl;
}

void pokazreal(vector<C> A)
{
   for(auto x:A)
        cout<<x.real()<<' ';
    cout<<endl;
}


void test(int n)
{
    /*
     *  Porównanie szybkości mnożenia wielomianów z DFT i zwyczajnie
     */
    vector<C> A(n),B(n),X,Y;
    double i=12;
    for(C&x:A)
        x=i++; // "PSEUDOLOSOWE" współczynniki
    for(C&x:B)
        x=i++; // "PSEUDOLOSOWE" współczynniki

    cout<<"Mnożenie z DFT n="<<n<<endl;
    Mnoz_DFT(A,B,X);
    if(n<10)
        pokazreal(X);
    else
        cout<<"Gotowe."<<endl;

    cout<<"Mnożenie zwykłe n="<<n<<endl;
    Mnoz(A,B,Y);
    if(n<10)
        pokazreal(X);
    else
        cout<<"Gotowe."<<endl;
}


int main()
{
    vector<C> A{1,5,3,1}, B=A,X,Y;

    cout<<"A = ";
    pokaz(A);   // Początkowy wielomian

    cout<<"DFT(A) = ";
    DFT(A);     // Dyskretna Transformata Fouriera
    pokaz(A);

    cout<<"invDFT(DFT(A)) = ";
    DFT(A,-1); // transformata odwrotna
    pokaz(A);  // pokazuje to samo co na początku + błędy zaokrąleń

    for(int i=2;i<100000;i*=2)
        test(i);    // porównanie szybkości mnozenia wielomianów
}
