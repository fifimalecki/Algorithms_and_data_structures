
#include <iostream>

using namespace std;

struct lnode
{
    int x;
    struct lnode* next;

    lnode(int x0, lnode *n0 = NULL)
        : x(x0), next(n0)
    {
    }

    lnode()
        : next(NULL)
    {
    }
};


void reverse(lnode*& L)
{
    lnode *prev = NULL, *current=L, *next=NULL;
    while(current){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    L = prev;
}

void add(lnode *&L, int x)
{
    lnode *temp = new lnode(x);
    temp->next = L;
    L = temp;
}

/* Function to print linked list */
void display(lnode *head)
{
    lnode *temp = head;
    while(temp != NULL)
    {
        printf("%d  ", temp->x);
        temp = temp->next;
    }
}

/*zadanie6*/
lnode* merge(lnode *L1, lnode *L2)
{
  lnode tmp;
  lnode *L3 = &tmp;
  tmp.next = NULL;
  while(L1 || L2){
    if(!L1 || L1->x <= L2->x){
        L3->next = L1;
        L1 = L1->next;
    }
    else{
        L3->next = L2;
        L2 = L2->next;
    }
    L3 = L3->next;
  }
  return tmp.next;
}

int main()
{
    lnode* l1 = new lnode(1);
    lnode* l2 = new lnode(6);

    add(l1,2);
    add(l1,3);
    add(l1,4);
    add(l1,5);

    add(l2,7);
    add(l2,8);
    add(l2,9);
    add(l2,10);

    display(l1);
    cout << endl;
    display(l2);
    cout << endl;

    lnode* l3 = merge(l1,l2);
    display(l3);
}
