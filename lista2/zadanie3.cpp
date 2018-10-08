#include <iostream>
//iloczyn skalarny n mnozen

using namespace std;

int count = 0;

int wielomian(int n)//wielomian (n*(n+1))/2
{
    for(int i = 0; i <= n; i++)
    {
        if(i>=1)
        count++;
    }
    if(n==0)
        return 1;
    return wielomian(n-1);
}

int mnozenie_wielomianow(int n)
{
    for(int i = 0; i < 2; i++)
    wielomian(n);
    count += n*n;
}

int mnozenie_macierzy(int n)//n^3
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            count += n;
        }
    }
}

int wyznacznik(int n)//powyzej n=2 2(n(n-1))
{
    if(n == 1)
        count = 0;
    else if(n == 2)
        count = 2;
    else
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < n; j++)
        {
            for(int k = 0; k < n-1; k++ )
                count++;
        }
    }
}

int main()
{
    for(int i = 1; i <= 10; i++)
    {
        wielomian(i);
        cout << "wielomian("<<i<<") count: "<<count<<"\n";
        count = 0;
        mnozenie_wielomianow(i);
        cout << "mnozenie_wielomianow("<<i<<") count: "<<count<<"\n";
        count = 0;
        mnozenie_macierzy(i);
        cout << "mnozenie_macierzy("<<i<<") count: "<<count<<"\n";
        count = 0;
        wyznacznik(i);
        cout << "wyznacznik("<<i<<") count: "<<count<<"\n\n";
        count = 0;
    }
}
