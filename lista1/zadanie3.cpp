#include <iostream>
#include <cmath>

using namespace std;

double oblicz(double a[], int n, double x)
{
    int multipyCounter = 0;
    double result = 0.0;
    int tempN = n;
    double tempElement = 1;
    for(int i=0; i<n; i++)
    {
        for(int j=1; j<tempN+1; j++)
        {
            tempElement *= x;
            multipyCounter++;
        }
        tempN--;
        result += a[i]*tempElement;
        multipyCounter++;
        tempElement = 1;
    }
    cout << multipyCounter <<"\t";
    return result;
}

int main()
{
    double a[3] = {2,3,3};
    int N = sizeof(a)/sizeof(*a);

    cout << oblicz(a,N,2);
}
