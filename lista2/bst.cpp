#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <typeinfo>
#define COUNT 10

using namespace std;

struct BST
{
    int key;
    BST * left;
    BST * right;

    BST(int _key, BST* _left=NULL, BST* _right=NULL)
    :key(_key), left(_left), right(_right)
    {}
};

struct RBT : BST
{
    bool black;
    RBT(int _key)//,RBT* _p=NULL, RBT* _left=NULL, RBT* _right=NULL)
    :BST(_key), black(false)
    {

    }
};
//
//void tree_insert(BST*& tree, int x)
//{
//    BST* y = NULL;
//    BST* z = new BST(x);
//    while(tree != NULL)
//    {
//        y = tree;
//        if(z->key < tree->key)
//            tree = tree->left;
//        else
//            tree = tree->right;
//    }
//    z->p = y;
//    if(y == NULL)
//        tree = z;
//    else if(z->key < y->key)
//        y->left = z;
//    else
//        y->right = z;
//}

void tree_insert(BST *& t, int x) // wstawianie (nierekurencyjna)
{
	BST **t1=&t;
	while(*t1)
		if(x<(*t1)->key)
			t1=&((*t1)->left);
		else
			t1=&((*t1)->right);
	*t1=new BST(x);
}

void inorder_tree_walk(BST* x)
{
    if(x != NULL)
    {
        inorder_tree_walk(x->left);
        cout << x->key << " ";
        inorder_tree_walk(x->right);
    }
}

void preorder_tree_walk(BST* x)
{
    if(x != NULL)
    {
        cout << x->key << " ";
        preorder_tree_walk(x->left);
        preorder_tree_walk(x->right);
    }
}

void postorder_tree_walk(BST* x)
{
    if(x != NULL)
    {
        postorder_tree_walk(x->left);
        postorder_tree_walk(x->right);
        cout << x->key << " ";
    }
}

void wypisz(BST* tree, int order = 0)
{
    if(order == 0)
    {
        if(tree != NULL)
        {
            wypisz(tree->left,0);
            cout << tree->key << " ";
            wypisz(tree->right,0);
        }
    }
    else if(order == 1)
    {
        if(tree)
        {
            cout << tree->key << " ";
            wypisz(tree->left,1);
            wypisz(tree->right,1);
        }
    }
    else if(order == 2)
    {
        if(tree)
        {
            wypisz(tree->left,2);
            wypisz(tree->right,2);
            cout << tree->key << " ";
        }
    }
}

//void wypisz(BST* tree, int order=0)
//{
//    if(order == 0){
//        cout << "INORDER: ";
//        inorder_tree_walk(tree);
//        cout << endl;}
//    else if(order == 1){
//        cout << "PREORDER: ";
//        preorder_tree_walk(tree);
//        cout << endl;}
//    else if(order == 2){
//        cout << "POSTORDER: ";
//        postorder_tree_walk(tree);
//        cout << endl;}
//    else
//        cout << "ERROR" << endl;
//}

BST* tree_search(BST* x, int k)
{
    if(x == NULL)
        return nullptr;
    if(k == x->key)
        return x;
    if(k < x->key)
        return tree_search(x->left,k);
    else
        return tree_search(x->right,k);
}

BST* iterative_tree_search(BST* tree, int x)
{
    while(tree != NULL && x != tree->key)
    {
        if(x < tree->key)
            tree = tree->left;
        else
            tree = tree->right;
    }
    if( tree == NULL)
        return nullptr;
    return tree;
}

BST* tree_minimum(BST* x)
{
    while(x->left != NULL)
        x = x->left;
    return x;
}

BST* tree_maximum(BST* x)
{
    while(x->right != NULL)
        x = x->right;
    return x;
}
//
//BST* tree_successor(BST* x)
//{
//    if(x->right != NULL)
//        return tree_minimum(x->right);
//    BST* y = x->p;
//    while(y != NULL && x == y->right)
//    {
//        x = y;
//        y = y->p;
//    }
//    return y;
//}
//
//void tree_delete(BST* T, BST* z)
//{
//    BST* y = T;//new BST();
//    BST* x = new BST(0);
//    if(z->left == NULL || z->right == NULL)
//        y = z;
//    else
//        y = tree_successor(z);
//    if(y->left != NULL)
//        x = y->left;
//    else
//        x = y->right;
//    if(x != NULL)
//        x->p = y->p;
//    if(y->p == NULL)
//        T = x;
//    else if(y == y->p->left)
//        y->p->left = x;
//    else
//        y->p->right = x;
//    if(y != z)
//        z->key = y->key;
//}
//
//int height(BST* t)
//{
//    int lDepth = height(t->left);
//    int rDepth = height(t->right);
//
//    if(lDepth > rDepth)
//        return lDepth+1;
//    else return rDepth+1;
//}

void PrintTree(BST* tp, int spaces )
{
  int i;

  if( tp != NULL )
  {
    PrintTree( tp->right, spaces + 3 );
    for( i = 0; i < spaces; i++ )
      cout <<' ';
    cout << tp->key << endl;
    PrintTree( tp->left, spaces + 3 );
  }
}
int main()
{
    {
//    BST *root = new BST(5);
//
//    tree_insert(root,4);
//    tree_insert(root,9);
//    tree_insert(root,2);
//    tree_insert(root,1);
//    tree_insert(root,3);
//    tree_insert(root,7);
//    tree_insert(root,6);
//    tree_insert(root,8);
//
//    cout << endl;
//    wypisz(root,0);
//    cout << endl;
//    wypisz(root,1);
//    cout << endl;
//    wypisz(root,2);
//    cout << endl;
//    PrintTree(root,0);
    }
    RBT* root = new RBT(5);
    cout << iterative_tree_search(root,5);
}
