#include<bits/stdc++.h>
using namespace std;
class Graph{
    int V;
    vector<vector<int>> adj;

public:
    Graph(int v) {
        V = v;
        adj.resize(V);  // Create V empty vectors
    }
    void addEdge(int i,int j,bool undir=false)
    {
        adj[i].push_back(j);
        if(undir)
            adj[j].push_back(i);
    }
    void dfs(int source,vector<bool> &visited,list<int> &ordering)
    {
        visited[source]=true;
        for(int nbr:adj[source])
        {
            if(!visited[nbr])
                dfs(nbr,visited,ordering);
        }
        ordering.push_front(source);

    }
    void topologicalSort()
    {
        vector<bool> visited(V,false);
    	list<int> ordering;
    	
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
                dfs(i,visited,ordering);
        }

        for(auto x:ordering)
            cout<<x<<" ";
        cout<<endl;

    }
};

int main()
{
    Graph g(6);
    g.addEdge(0,2);
    g.addEdge(2,3);
    g.addEdge(3,5);
    g.addEdge(4,5);
    g.addEdge(1,4);
    g.addEdge(1,2);
    
    g.topologicalSort();
}