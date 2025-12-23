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

    void dfs(int source){
    	vector<bool> visited(V,false);
    	dfsHelper(source,visited);
    }
    void dfsHelper(int source,vector<bool> &visited)
    {
    	cout<<source<<" ";
    	visited[source]=true;
    	for(auto x:adj[source])
    	{
    		if(!visited[x])
    			dfsHelper(x,visited);
    	}
    	return;
    }
};

int main()
{
	Graph g(7);
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(2,3);
	g.addEdge(3,5);
	g.addEdge(5,6);
	g.addEdge(4,5);
	g.addEdge(0,4);
	g.addEdge(3,4);
	
	g.dfs(1);
}