#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

string DecToBin(int number)
{
    if ( number == 0 ) return "0";
    if ( number == 1 ) return "1";

    if ( number % 2 == 0 )
        return DecToBin(number / 2) + "0";
    else
        return DecToBin(number / 2) + "1";
}

double powIte(double x, int n)
{ //11 = 1011
    string binN = DecToBin(n);
    double result = 1;
    for(int i = 0; i < binN.size(); i++)
    {
        //cout << binN[binN.size() - i - 1] <<endl;
        if(binN[binN.size() - i - 1] == '1')
            result *= pow(x,pow(2,i));
    }
    return result;
}

double powRec(double x,int n)
{
    int index = 0;
    if(n == 0)
        return 1;
    else if(n==1)
        return x;
    else if(n%2 == 0)
    {
        index = n/2;
        return pow(x,index)*powRec(x,index);
    }
    else
    {
        index = (n-1)/2;
        return pow(x,index)*powRec(x,index)*x;
    }
}

int main()
{
    cout << powRec(3,11) <<"\n"<<powIte(3,11);
}
