#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <algorithm>


using namespace std;

struct edgeTo
{
    int v;    // number of the neighbour
    double d; // distance (or weight) of the edge
    
    edgeTo(int v0,double d0):v(v0),d(d0){}
};

class Graph
{
  public:
    vector<vector<edgeTo>> adj;

    Graph(int n):adj(n) {}

    void edge(int i, int j, double w=1)
    {
        adj[i].push_back(edgeTo(j,w));
    }

    void edge2(int i, int j, double w=1)
    {
        adj[i].push_back(edgeTo(j,w));
        adj[j].push_back(edgeTo(i,w));
    }
    
    void show(bool with_weights=true)
    {
        int i=0;
        for(auto u:adj)
        {
            cout<<i++<<":";
            for(auto e:u)
            {
                cout<<" "<<e.v;
                if(with_weights)
                    cout<<"("<<e.d<<")";
            }
            cout<<endl;
        }
    }
};

class DFS
{
    
    Graph &G;
    vector <bool>mark;
    
    public:
    
    DFS(Graph& G0) : G(G0), mark(G.adj.size(),false)
    {
    }

    void visit(int i)
    {
        mark[i]=true;
        cout<<" "<<i;
        for(auto x:G.adj[i])
            if(!mark[x.v])
                visit(x.v);
    }

    void visit_all()
    {
        for(size_t i=0;i<mark.size();i++)
            if(!mark[i])
                visit(i);
    }

    void reset()
    {
        mark.assign(mark.size(),false);
    }

};


class BFS
{
    
    Graph &G;
    vector <int>mark;
    vector <double>dist;
    vector <int>prev;
    
    public:
    
    BFS(Graph& G0) :
        G(G0), 
        mark(G.adj.size(),0),
        dist(G.adj.size(),numeric_limits<double>::max()),
        prev(G.adj.size(),0)
    {
    }

    BFS& visit(int i)
    {
        mark[i]=1;
        dist[i]=0;
        prev[i]=-1;
        auto closer=[this](int a, int b) 
            { 
                return this->dist[a] > this->dist[b];
            };
        priority_queue<int,vector<int>,decltype(closer)> Q(closer);
        Q.push(i);
        while(Q.size()>0)
        {
            int j=Q.top(); Q.pop();
            cout<<" "<<j;
            for(edgeTo x:G.adj[j])
                if(!mark[x.v])
                {
                    mark[x.v] = 1;
                    dist[x.v] = dist[j] + 1; // + x.d
                    prev[x.v] = j;
                    Q.push(x.v);
                }
            mark[j] = 2;
        }
        cout<<endl;
        return *this;
    }

    void visit_all()
    {
        for(size_t i=0;i<mark.size();i++)
            if(!mark[i])
                visit(i);
    }

    void reset()
    {
        mark.assign(G.adj.size(),0);
        dist.assign(G.adj.size(),numeric_limits<double>::max());
        prev.assign(G.adj.size(),-1);
    }
    
    void show_prev()
    {
        for(size_t i=0;i<prev.size();i++)
            cout<<i<<"->"<<prev[i]<<" ";
        cout<<endl;
    }
};

class myPQ
{
     vector<double>& dist;
     vector<int> what;
     vector<int> where;
 
     public:
        
     myPQ(vector<double>& dist0):dist(dist0),what(dist0.size()),where(dist0.size())
     {
         for(size_t i=0;i<dist.size();i++)
         {
            dist[i]=numeric_limits<double>::max(); 
            what[i]=where[i]=i;
         }
     }
      
     //~ void insert(int k)
     //~ {
         //~ n=what.size();
         //~ what.push_back(k);
         //~ upwards(n);
      
     //~ }
     
     void upwards(int n)
     {  
         int i;
         while(n>0&& dist[what[i=(n-1)/2]]>dist[what[n]])
         {  
             swap(what[i],what[n]);
             where[what[i]]=i;
             where[what[n]]=n;
         }
     }
     
     void decrease_key(int i,double val)  
     {
         dist[i]=val;
         upwards(where[i]);
     }
     
     int getmin()
     {
         int res=what[0];
         int i=0;
         int k;
         int n=what.size()-1;
         what[0]=what[n];
         what.pop_back();
         while(
                ((k=2*i+2)<n && dist[what[i]]>dist[what[k]] && dist[what[k-1]]>dist[what[k]])
                  || 
                (--k<n && dist[what[i]]>dist[what[k]] )
              )  
         {
             swap(what[i],what[k]);     
             where[what[i]]=i;
             where[what[k]]=k;
         }         
         return res;
     }
     
     int size()
     {
         return what.size();
     }
};

class Dijkstra
{

    Graph &G;
    vector <double>dist;
    vector <int>prev;
    
    public:
    
    Dijkstra(Graph& G0):
        G(G0), 
        dist(G.adj.size(),numeric_limits<double>::max()),
        prev(G.adj.size(),0)
    {
    }

    Dijkstra& distFrom(int i)
    {
        
        myPQ Q(dist);
        prev[i]=i;
        Q.decrease_key(i,0);
        while(Q.size()>0)
        {
            int j=Q.getmin();
            for(edgeTo x:G.adj[j])
                if(dist[x.v]>dist[j] + x.d)
                {
                    prev[x.v] = j;
                    Q.decrease_key(x.v,dist[j] + x.d);
                }
        }
        return *this;
    }

    void show_prev()
    {
        for(size_t i=0;i<prev.size();i++)
            cout<<i<<"("<<dist[i]<<")->"<<prev[i]<<" ";
        cout<<endl;
    }

};


class MST_Prim
{
    Graph &G;
    vector <double>dist;
    vector <int>prev;
    
    public:
    
    MST_Prim(Graph& G0):
        G(G0), 
        dist(G.adj.size(),numeric_limits<double>::max()),
        prev(G.adj.size(),0)
    {
    }

    MST_Prim& MST(int i)
    {
        myPQ Q(dist);
        prev[i]=i;
        Q.decrease_key(i,0);
        while(Q.size()>0)
        {
            int j=Q.getmin();
            for(edgeTo x:G.adj[j])
                if(dist[x.v]> x.d)
                {
                    prev[x.v] = j;
                    Q.decrease_key(x.v, x.d);
                }
            dist[j]=0;
        }
        return *this;
    }

    void show_prev()
    {
        for(size_t i=0;i<prev.size();i++)
            cout<<i<<"("<<dist[i]<<")->"<<prev[i]<<" ";
        cout<<endl;
    }

};


class UnionFind
{
    public:
      vector<int> parent;
      vector<int> rank;
    
    UnionFind(int n):parent(n),rank(n,0)
    {
        for(int i=0;i<n;i++)
            parent[i]=i;
    }
      
    int Find(int i)
    {   
        if(parent[i]!=i) 
            parent[i]=Find(parent[i]);
        return parent[i];
    }
    
    int Union(int i, int j)
    {
        int a=Find(i);
        int b=Find(j);
        if(a==b)
            return 0;
        if(rank[a]>rank[b])
            parent[b]=a;
        else
        {
            parent[a]=b;
            if(rank[a]==rank[b])
                rank[b]++;
        }   
        return 1;
    }
};

struct edge
{
    int a;
    int b;
    double d;
    
    edge(int a0, int b0, double d0):a(a0),b(b0),d(d0){}
};

Graph MST_Kruskal(Graph &G)
{
    Graph tree(G.adj.size());
    UnionFind uf(G.adj.size());
    
    // zrób tablicę krawędzi
    vector<edge> edges;
    for(size_t i=0;i<G.adj.size();i++)
        for(edgeTo x:G.adj[i])
            edges.push_back(edge(i,x.v,x.d));

    // sortuj krawędzie wg długości        
    sort(edges.begin(),edges.end(),[](edge e1, edge e2){return e1.d<e2.d;});

    // przetwarzaj krawędzie od najkrótszej do najdłuższej
    // akcepuj krawędź (a,b) jeśli było jeszcze połączenia między a i b
    for(edge e:edges)
        if(uf.Union(e.a,e.b)) // prawda jeśli nie było połączenia
            tree.edge2(e.a,e.b,e.d);
            
    return tree;        
}


int main()
{
    Graph G(7);
    G.edge2(0,1, 300);
    G.edge2(1,2, 400);
    G.edge2(2,3, 100);
    G.edge2(3,4, 500);
    G.edge2(4,5, 001);
    G.edge2(5,6, 001);
    G.edge2(6,0, 001);
    G.edge2(2,4, 001);
    G.edge2(6,4, 100);
    G.show(false);
    
    cout<<"DSF.visit(0):";
    DFS(G).visit(0);
    cout<<endl;
    
    cout<<"BSF.visit(0):";
    BFS(G).visit(0).show_prev();

    G.show();
    int i=1;
    cout<<"Dijkstra.distFrom("<<i<<"):"<<endl;
    Dijkstra(G).distFrom(i).show_prev();
    
    cout<<"MST_Kruskal:"<<endl;
    MST_Kruskal(G).show();

    cout<<"MST_Prim:"<<endl;
    MST_Prim(G).MST(0).show_prev();
    
    return 0;
}
