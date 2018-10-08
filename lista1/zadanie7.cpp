#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void load(string file, vector<double> &coefs)
{
    ifstream f(file);
    char znak;
    double coef;
    f >> znak;
    while(znak!=')')
    {
        f >> coef >> znak;
        coefs.push_back(coef);
    }
}

void mnozenie(vector<double> &A, vector<double> &B, vector<double> &C)
{
    for(int i=0; i<A.size(); ++i)
        for(int j=0; j<B.size(); ++j)
            C[i+j] += A[i] *B[j];
}

void zapisz(string file, vector<double> C)
{
    ofstream f(file);
    f << "(";
    for(int i = 0; i < C.size(); i++)
        if(i < C.size() -1)
            f << C[i] <<",";
        else
            f << C[i];
    f << ")";
}

int main()
{
    vector<double> A(1);
    vector<double> B(1);

    load("a.txt",A);
    load("b.txt",B);

    vector<double> C(A.size()+ B.size()-1);

    mnozenie(A,B,C);
    zapisz("c.txt",C);
}
