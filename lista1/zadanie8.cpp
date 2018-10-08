#include <iostream>
#include <algorithm>

using namespace std;

class ulamek
{
    int licznik;
    int mianownik;
    public:

    ulamek(int _licznik, int _mianownik=1)
    :licznik(_licznik), mianownik(_mianownik)
    {
        int nwd = __gcd(licznik,mianownik);
        licznik /= nwd;
        mianownik /= nwd;
    }

    friend ostream & operator <<(ostream & o,const ulamek & u)
    {
        if(u.mianownik == 1)
            return o << u.licznik;
        o << u.licznik << "/" << u.mianownik;
        return o;
    }

    friend istream & operator >>(istream & i, ulamek &u)
    {
        char c;
        i >> u.licznik;
        i >> c;
        i >> u.mianownik;

        return i;
    }

    ulamek operator +(ulamek u)
    {
        licznik = this->licznik*u.mianownik + u.licznik*this->mianownik;
        mianownik = this->mianownik*u.mianownik;

        return ulamek(licznik,mianownik);
    }

    ulamek operator -(ulamek u)
    {
        licznik = this->licznik*u.mianownik - u.licznik*this->mianownik;
        mianownik = this->mianownik*u.mianownik;

        return ulamek(licznik,mianownik);
    }

    ulamek operator *(ulamek u)
    {
        licznik = this->licznik*u.licznik;
        mianownik = this->mianownik*u.mianownik;

        return ulamek(licznik,mianownik);
    }

    ulamek operator /(ulamek u)
    {
        licznik = this->licznik*u.mianownik;
        mianownik = this->mianownik*u.licznik;

        return ulamek(licznik,mianownik);
    }
};

int main()
{

}
