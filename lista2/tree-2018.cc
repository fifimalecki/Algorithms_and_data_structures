#include <iostream>
#include <cassert>
using namespace std;

// Operacje na drzewie BST
// Przykłady do wykładu z Algorytmów i Struktur Danych
// C. Juszczak (2018)

struct node  // drzewo bez wskaźnika na rodzica
{
	int x;
	node* left;
	node* right;

	node(int x0, node* l=NULL, node* r=NULL)
		:x(x0), left(l), right(r)
	{}
};

void insert_recursive(node *& t, int x) // wstawianie (rekurenycjnie)
{
	if(!t)
		t=new node(x);
	else
		if(x<t->x)
			insert_recursive(t->left,x); // tail recursion
		else
			insert_recursive(t->right,x); // tail recursion
}

void insert(node *& t, int x) // wstawianie (nierekurencyjna)
{
	node **t1=&t;
	while(*t1)
		if(x<(*t1)->x)
			t1=&((*t1)->left);
		else
			t1=&((*t1)->right);
	*t1=new node(x);
}


node* find_recursive(node* t,int x) // wyszukiwanie klucza (rekurencja)
{
	if(t==NULL || t->x==x)
		return t;
	if(x<t->x)
		return find_recursive(t->left,x); // tail recursion
	else
		return find_recursive(t->right,x); // tail recursion
}

node* find(node* t,int x)  // wyszukiwanie klucza (bez rekurencji)
{
	while(t && t->x!=x)
	{
		if(x<t->x)
			t=t->left;
		else
			t=t->right;
	}
	return t;
}


void inorder(node *t)  // wypisanie kluczy w porządku "in order"
{
	if(t)
	{
		inorder(t->left);
		std::cout<<t->x<<" ";
		inorder(t->right);
	}
}

void prerder(node *t) // wypisanie kluczy w porządku "pre order"
{
	if(t)
	{
		std::cout<<t->x<<" ";
		prerder(t->left);
		prerder(t->right);
	}
}

void postorder(node *t) // wypisanie kluczy w porządku "post order"
{
	if(t)
	{
		postorder(t->left);
		postorder(t->right);
		std::cout<<t->x<<" ";
	}
}

void display(node *t,char z1=' ',char z2=' ') // in order z nawiasami
{
	if(t)
	{
		std::cout<<z1;
		display(t->left,'(',')');
		std::cout<<t->x;
		display(t->right,'[',']');
		std::cout<<z2;
	}
}


int N(node* t) // ilość kluczy w drzewie (rekurenycjnie)
{
	if(!t) return 0;
	int nL=N(t->left);
	int nR=N(t->right);
	return nL+nR+1;
}

int n(node* t) // ilość kluczy w drzewie (to samo krócej)
{
	return !t ? 0 : 1+n(t->left)+n(t->right);
}

int H(node* t)  // wysokość drzwa BST (rekurencyjnie)
{
	if(!t) return 0;
	int hL=H(t->left);
	int hR=H(t->right);
	if(hR>hL)
		return 1+hR;
	else
		return 1+hL;
}

int h(node* t) // wysokość drzwa BST (to samo krócej)
{
	return !t ? 0 : 1+std::max(h(t->left),h(t->right));
}


int min_recursive (node* t)  // minimalny klucz (rekurencyjnie)
{
	assert(t);  // używaj tylko tylko gdy drzewo nie jest puste
	if(t->left)
		return min_recursive(t->left); // tail recursion
	else
		return t->x;
}

int min (node* t)  // minimalny klucz (bez rekurencji)
{
	assert(t);
	while(t->left)
		t=t->left;
	return t->x;
}

int max_recursive (node* t)   // maksymalny klucz (rekurencyjnie)
{
	assert(t);
	if(t->right)
		return max_recursive(t->right); // tail recursion
	else
		return t->x;
}

int max (node* t)   // maksymalny klucz (bez rekurencji)
{
	assert(t);
	while(t->right)
		t=t->right;
	return t->x;
}


void remove_recursive(node *&t, int x)  // usuwanie elementu z drzewa (rekurencja)
{
	if(t==NULL) return;
	if(t->x==x)
	{
		if(t->left==NULL)
		{
			node *d=t->right;
			delete t;
			t=d;
		}
		else
		if(t->right==NULL)
		{
		    node *d=t->left;
			delete t;
			t=d;
		}
		else
		{  t->x=min(t->right);
		   remove_recursive(t->right,t->x); // tail recursion
	    }
	}
	else
	if(x < t->x)
		remove_recursive(t->left,x); // tail recursion
	else
		remove_recursive(t->right,x); // tail recursion
}

void remove(node *&t, int x)  // usuwanie elementu z drzewa (bez rekurencji)
{
	node **t1=&t;
	while (*t1 && (*t1)->x!=x)
	{
		if(x<(*t1)->x)
			t1=&((*t1)->left);
		else
			t1=&((*t1)->right);
	}
	if(*t1)
	{
		if((*t1)->right && (*t1)->left)
		{
			node **t2=&((*t1)->right);
			while ((*t2)->left)
				t2=&((*t2)->left);
			(*t1)->x=(*t2)->x;
			t1=t2;
		}
		if((*t1)->left==NULL)
		{
			node *d=(*t1)->right;
			delete *t1;
			(*t1)=d;
		}
		else
		{
		    node *d=(*t1)->left;
			delete *t1;
			(*t1)=d;
		}
	}
}



void destroy(node*&t) // usunięcie drzwa i zwolnienie pamięci
{
	if(t)
	{	destroy(t->right);
		destroy(t->right);
		t=NULL;
	}
}


int main()
{
	node* t=NULL; // tworzymy puste drzewo BST

	// dodajemy klucze

	insert(t,3);
	insert(t,4);
	insert(t,1);
	insert(t,7);
	insert(t,-4);
	insert(t,9);
	insert(t,2);

	cout<<"kolejnosc inorder :"; inorder(t); cout<<endl;
	cout<<"kolejnosc prerder :"; prerder(t); cout<<endl;
	cout<<"kolejnosc postrder:"; postorder(t);cout<<endl;
	cout<<"struktura         :"; display(t);cout<<endl;
	cout<<"Ilosc wezlow    = "<<n(t)<<endl;
	cout<<"Wysokosc drzewa = "<<h(t)<<endl;
	cout<<"min = "<<min(t)<<" max = "<< max(t)<<endl;
	cout<<"wyszukaj 9: "<<find(t,9)->x<<endl;
	cout<<"usun korzen ("<<t->x<<"): "; remove(t,t->x); display(t); cout<<endl;
	cout<<"usun 9: "; remove(t,9); display(t); cout<<endl;
	destroy(t); inorder(t); cout<<endl;
}

