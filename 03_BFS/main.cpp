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

    void bfs(int source){
    	queue<int> q;
    	vector<bool> visited(V,false);
    	q.push(source);
    	visited[source]=true;
    	while(!q.empty())
    	{
    		int t=q.front();
    		cout<<t<<" ";
    		for(auto x:adj[t])
    		{
    			if(!visited[x])
    			{
    				q.push(x);
    				visited[x]=true;
    			}
    		}
    		q.pop();
    	}
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
	
	g.bfs(1);
}