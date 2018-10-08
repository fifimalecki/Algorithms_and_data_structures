#include <iostream>
#include <cmath>

using namespace std;

double f(double x)
{
    return pow(x,3)-x+1;
}

double bisekcja(double a,double b,double e)
{
    double x = 0;
    while(abs(a-b)>e)
    {
        x = (a+b)/2;
        if(f(x) <= 0.0 + e && f(x) >= 0.0 - e)
            break;
        else if(f(x)*f(a) < 0)
            b = x;
        else
            a = x;
    }
    return x;
}

int main()
{
 cout << bisekcja(-2,2,0.0000001);
}
