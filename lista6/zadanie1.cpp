#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

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

template <typename T>
class hasz
{
public:
    struct lnode
    {
        T x;
        lnode* next;

        lnode(T x0, lnode *n0 = NULL): x(x0), next(n0)
        {}

        lnode(): next(NULL)
        {}
    };

    unsigned int m;
    vector<lnode*> arr;
    hasz(int _m) : m(_m), arr(_m)
    { }

    ~hasz()
    {
        for(int i=0;i<m;i++)
        {
            delete arr[i];
        }
    }

    T show(int n)
    {
        return arr[n]->x;
    }

    int h(T s)
    {
        unsigned h,i,p,q;
        h=0;
        p=13;
        q=m;
        for(i=0;i<s.length();i++)
            h += s[i] * (p^(s.length()-i));
        return h % q;
    }

    void add(T s)
    {
        lnode* temp = new lnode(s,NULL);
        int index = h(s);
        temp->next = arr[index];
        arr[index] = temp;
    }

    void remove(T s)
    {
        int index = h(s);
        lnode* temp = new lnode();
        lnode* prev = new lnode();
        temp = arr[index];
        while(temp != NULL)
        {
            if(temp->x == s) break;
            else{
                prev = temp;
                temp = temp->next;
            }
        }
        if(temp != NULL)
        {

//            cout << endl << "-----------" << endl;
//            cout << "DELETING : " << endl;
//            cout << temp->x << "IN T[" << index << "]" ;
//            cout << endl << "-----------" << endl;
            prev->next = temp->next;
            delete temp;
        }
    }

    void find(T s)
    {
        unsigned int index = h(s);
        lnode *temp = new lnode();
        temp = arr[index];
        while(temp != NULL)
        {
            if(temp->x == s) break;
            temp=temp->next;
        }
        if(temp != NULL)
        {
            cout << endl << "-----------" << endl;
            cout << "FOUND : " << temp->x << " IN T[" << index << "]";
            cout << endl << "-----------" << endl;
        }
    }

    void display()
    {
        for(int i = 0; i < m; i++)
        {
            cout << i << ". ";
            lnode *temp = arr[i];
            while(temp != NULL)
            {
                cout << temp->x << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }

    void display_specific(int i)
    {
        lnode *temp = arr[i];
        while(temp != NULL)
        {
            cout << temp->x << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

string genString(int length)
{

    std::string Str;
    static const char alphanum[] =
    "0123456789"
    "!@#$%^&*"
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "abcdefghijklmnopqrstuvwxyz";

    int stringLength = sizeof(alphanum) - 1;

    for(unsigned int i = 0; i < length; ++i)
    {
        Str += alphanum[rand() % stringLength];
    }
    return Str;
}

int main()
{
    srand(time(NULL));
    hasz<string> tab(100);
    vector<string> znaki;
    for(int i = 0; i < 1000; i++)
    {
        string temp = genString(5);
        tab.add(temp);
        znaki.push_back(temp);
    }
    tab.display();
    for(int i = 0; i < 200; i++)
        tab.remove(znaki[rand() % tab.m - 1]);
    for(int i = 0; i < 100; i++)
        tab.find(znaki[rand() % tab.m - 1]);
    for(int i = 0; i < 100 ; i++)
    {

        string temp = genString(5);
        tab.find(temp);
    }
    tab.display();
}
