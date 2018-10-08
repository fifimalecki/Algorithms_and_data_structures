#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

void Min_Max(int tab[], int N)
{
    int Min;
    int Max;
    int a;
    int b;
    for(int i = 0; i < N/2; i++)
    {
        a = tab[i];
        b = tab[N-i-1];
        if(a > b)
        {
            if(a > Max)
                Max = a;
            if(b < Min)
                Min = b;
        }
        else
        {
            if(b > Max)
                Max = b;
            if(a < Min)
                Min = a;
        }
            //if(a[N/2+1])
        //cout << a << " " << b << " "<< Max << " " << Min << "\n";
    }
    cout << "Max = "<< Max << " Min = " << Min;
}


int main()
{
    int N = 10;
    int a[N];
    srand(time(NULL));
    for(int i = 0; i < N; i++)
    {
        a[i] = rand() % 100;
        cout << a[i] << " ";
    }
    cout << "\n";
    Min_Max(a,N);
}
