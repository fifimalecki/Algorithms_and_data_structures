#include <iostream>
#include <cmath>
#include <math.h>
#include <vector>

using namespace std;

vector<bool> GenerateList(int n)
{
    vector<bool> tempList(1);
    for(int i=0; i<n; i++)
        tempList.push_back(true);
    return tempList;
}

vector<bool> Sito(vector<bool> vec, int n)
{
    vector<bool> v = vec;
    for(int i=2; i<sqrt(n);i++)
    {
        if(v[i] == true)
        {
            for(int j=0; j<n-1; j++)
            {
                if(pow(i,2)+j*i <= n-1)
                    v[pow(i,2)+j*i] = false;
            }
        }
    }
    return v;
}

int main()
{
    int N = 20;
    vector<bool> prime = Sito(GenerateList(N+1),N+1);
    for(int i = 0; i<=N; i++)
    {
        if(prime[i] == 1)
            cout << "true "<<i<<"\n";
        else
            cout << "false "<<i<<"\n";
    }

}
