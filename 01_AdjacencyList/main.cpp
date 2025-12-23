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

    void addEdge(int i,int j,bool undir=true)
    {
    	adj[i].push_back(j);
    	if(undir)
    		adj[j].push_back(i);
    }

    void printAdjList()
    {
    	for(int i=0;i<V;i++)
    	{
    		cout<<i<<" -> ";
    		for(auto x:adj[i])
    			cout<<x<<" ";
    		cout<<endl;
    	}
    }
};


int main()
{
	Graph g(6);
	g.addEdge(0,1);
	g.addEdge(0,4);
	g.addEdge(2,1);
	g.addEdge(3,4);
	g.addEdge(4,5);
	g.addEdge(2,3);
	g.addEdge(3,5);

	g.printAdjList();
}