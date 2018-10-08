#include <iostream>
#include <vector>

using namespace std;

int PlusZKropko(int a,int b,int m)
{
    return (a+b) % m;
}

int nwd(int a, int b)
{
    do
    {
        if(a>b) a=a-b;
        else b=b-a;
    }
    while(a!=b);
    return a;
}

int h(string s)
{
    unsigned h,i,p,q;
    h=0;
    p=30;
    q=13;
    for(i=0;i<s.length();i++)
        h += s[i] * (p^(s.length()-i));
    return h % q;
}

int main()
{
    int m,f;
    vector<int> results;
    m=10;
    f=1;
    for(int j = 1; j<m;j++){
    if(nwd(m,j) == 1){cout << m << " " << j << " Brak wspolnych dzielnikow"<<endl;

    for(int i = 0; i < m; i++)
    {
        //results.push_back(PlusZKropko(h("dup"),i*j,m));
        cout << PlusZKropko(h("dup"),i*j,m) << " ";
    }}
    else cout << m << " " << j << " NWD = " << nwd(m,j) << endl;
    cout << endl << endl;
    }

}
