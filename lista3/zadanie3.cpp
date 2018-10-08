#include <iostream>
using namespace std;

struct lnode
{
    int x;
    lnode* next;

    lnode(int x0,lnode* n0=NULL)
    :x(x0), next(n0)
    {}

    lnode()
    :next(NULL)
    {}
};

int size(lnode*& L)
{
    lnode *temp = L;
    int counter = 0;
    while(temp != NULL)
    {
        counter++;
        temp = temp->next;
    }
    return counter;
}

void display(lnode *L)
{
    lnode *temp = L;
    while (temp != NULL)
    {
        printf("%d  ", temp->x);
        temp = temp->next;
    }
}

void add(lnode*& L, int x)
{
    lnode * temp = new lnode(x);
    temp->next = L;
    L = temp;
}

void reverse(lnode*& L)
{
    lnode *prev = NULL;
    lnode *current = L;
    lnode *next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    L = prev;
}

void insertion_sort(lnode*& L)
{
    if(!L || !L->next )
        return;
    lnode* temp = NULL;
    lnode* current;
    lnode** p;
    while(L)
    {
        current = L;
        p = &temp;
        L = L->next;
        while(*p && current->x > (*p)->x)
        {
            p = &(*p)->next;
        }
        current->next = *p;
        *p = current;
    }
    L = temp;
}

lnode* merge(lnode *L1, lnode *L2)
{
  lnode tmp;
  lnode *L3 = &tmp;
  tmp.next = NULL;
  while(L1 || L2){
    if(!L2 || L1->x >= L2->x){
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

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(lnode*& L)
{

}

int main()
{
    lnode * l1 = new lnode(3);
    add(l1,6);
    add(l1,4);
    add(l1,2);
    add(l1,5);


    lnode * l2 = new lnode(3);
    add(l2,4);
    add(l2,10);
    add(l2,8);
    add(l2,7);

    l1 = merge(l1,l2);

    display(l1);
    cout << endl;
    insertion_sort(l1);
    display(l1);
}
