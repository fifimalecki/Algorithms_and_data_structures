#include <iostream>

using namespace std;

struct lnode
{
    int key;
    lnode *next;
};

int nty(int n, lnode *l)
{
    l->key = n;
    return l->key;
}

int main()
{
    lnode lista;
    nty(3,&lista);
}
