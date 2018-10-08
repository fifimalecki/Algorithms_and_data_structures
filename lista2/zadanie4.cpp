#include <iostream>
#include <algorithm>

using namespace std;
void przesuniecie(int tab[],int k,int n){

    for(int j = 0; j < k; j++)
    {
        int temp = tab[0];
        for(int i = 0; i < n; i++)
        {
            swap(temp,tab[(i+1)%n]);
        }
        for(int i = 0 ; i < n; i++)
        {
            cout << tab[i] << " ";
        }
        cout << "\n";
    }
}

int main() {
    int k=11;
    int n=10;
    int tab[n];
    for(int i=0; i<n; i++){
        tab[i] = i;
        cout << tab[i] << " ";
    }
    cout << "\n";
    przesuniecie(tab,k,n);
}
