#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

double P(int k, int n, double p)
{
    double sum = 0;
    double q = 1 - p;
    double qn = pow(q,n);
    double p_div_q = p/q;
    double last = qn;

    sum = last;

    for(int i=1; i<=k; ++i)
    {
        last *= p_div_q;
        last *= n+1-i;
        last /= i;
        sum += last;
    }
    return sum;
}
int main()
{
    cout << P(5,10,0.5);
}
