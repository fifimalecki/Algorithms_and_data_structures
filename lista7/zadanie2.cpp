#include <iostream>
#include <cmath>

using namespace std;

int f (int n)
{
    cout << n <<endl;
    if (n == 0)
        return 0;
    else
        return (n & 1) + f(n >> 1);
}

int main()
{
  cout << f(13);
}
