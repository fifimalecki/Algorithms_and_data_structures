#include <iostream>
#include <queue>
#include <map>
#include <sstream>


using namespace std;

const int n=10;


struct node 
{ 
    char znak;
    int ile;
    node * left;
    node * right;

    node(char c,int i, node* l=nullptr,node* p=nullptr)
    :znak(c),ile(i),left(l),right(p)
    {}
};

void destroy(node* h)
{
    if(h)
    {  
        destroy(h->left);
        destroy(h->right);
        delete h;
    }
}

bool operator<(node a,node b)
{ 
    return a.ile > b.ile;
}

std::map<char,int> count(string message)
{
    std::map<char,int> counts;
    for(auto x :message)
        counts[x]++;
    return counts;
}

node* huffman(std::map<char,int> &counts)
{
    std::priority_queue<node> Q;
    for(auto x :counts)
		Q.push(node(x.first,x.second));
    
    while(Q.size()>1)
    { 
		node* a=new node(Q.top()); 
		Q.pop();

		node* b=new node(Q.top()); 
		Q.pop();
		
		Q.push(node(0,a->ile+b->ile,a,b));
    } 	
    
    return new node(Q.top());
} 

void makedict(node* m, map<char,string>& dict, string prefix="")
{
    /*
     * given binary tree from the Huffman algorithm 
     * create coding dictionary
     */
    
    if(m)
    {  
        if(m->znak)
            dict[m->znak]=prefix;
        else
        {
            makedict(m->left,dict,prefix+"0");	
            makedict(m->right,dict,prefix+"1");	
        }
    }
}

string encode(std::map<char,string> dict,string a)
{
    stringstream s;
    for(auto z:a)
		s<<dict[z];
    return s.str();	
}

string decode(node* h,string encoded)
{
    stringstream s;
    node *c=h;
    for(auto z:encoded)
    {
		if(z=='0' && c->left)
		   c=c->left;
		else
		   c=c->right;
		if(c->znak)
		{
			s<<c->znak;
			c=h;
		}    
    }
    return s.str();
}

int main()
{
   
    std::map<char,string> dict;

    cout<<"Kodowanie Huffmanna.\nPodaj tekst: ";

    string message;
    getline(cin,message);

    map<char,int> counts=count(message);
    
    cout<<"Ile wystąpień:"<<endl;
    for(auto x:counts)
      cout<<x.first<<":"<<x.second<<endl;

    node* h=huffman(counts);
    
    makedict(h,dict);

    cout<<"Kody Huffmana:"<<endl;    
    for(auto x:dict)
	    cout<< x.first<<" -> "<<x.second<<endl; 	

    string encoded=encode(dict,message);    
    string decoded=decode(h,encoded);

    cout<<"Tekst  : "<<message<<endl;
    cout<<"Szyfr  : "<<encoded<<endl;
    cout<<"Deszyfr: "<<decoded<<endl;

    destroy(h);
}
