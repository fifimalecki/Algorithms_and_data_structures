#include <iostream>

using namespace std;
int count=0;
int maksA(int t[], int n)//n-1
{
    int x=t[--n];
    while(n--)
    {
        count++;
        if(t[n] > x)
        {
            x=t[n];
        }
    }
    return x;
}

int maksB(int tab[], int n)// optymistycznie = N, pesymistycznie =
{
    int max = maksA(tab,n);
    count++;
    if(max > tab[n-1])
        return maksB(tab,n-1);
    else
        return max;
}

int maksC(int tab[], int n)
{
    int _n = (n+1)/2;
    int tabA[_n];
    int tabB[_n];
   // cout << "n\t_n\ttabA[i]\ttabB[i]\ttab[i]\ttab[_n+i]\n";
    for(int i = 0; i < _n; i++)
    {
        tabA[i] = tab[i];
        tabB[i] = tab[_n+i];
        if(n%2==1)
        tab[_n+_n-1] = tab[_n+_n-2];
   // cout << n << "\t" << _n  << "\t" << tabA[i] << "\t" << tabB[i] << "\t" << tab[i] <<"\t" << tab[_n+i]<<"\n";
    }
    int maxA = maksA(tabA,_n);
    int maxB = maksA(tabB,_n);
    count++;
    //cout << "count\tmaxA\tmaxB\n";
    //cout << count << "\t" << maxA << "\t" << maxB << "\n";
    if(maxA > maxB)
    {
        if(_n == 1)
            return maxA;
        return maksC(tabA,_n);
    }
    else
    {
        if(_n == 1)
            return maxB;
        return maksC(tabB,_n);
    }
}

int main()
{
    int N = 12;
    int TAB[N] = {100,2,3,4,5,6,7,8,9,10,11,12};
    maksB(TAB,N);
    cout << count;
//maksC
//    cout <<"count\tpamiec1\tcala uzyta pamiec\n"<< count <<"\t"<<(sizeof(int[N])+2*sizeof(int[(N+1)/2])+2*sizeof(int))<<"\t"<< count*(sizeof(int[N])+2*sizeof(int[(N+1)/2])+2*sizeof(int));
}
