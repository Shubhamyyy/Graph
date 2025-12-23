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
    void topologicalSort()
    {
    	vector<int> inDegree(V,0);
    	for(auto x:adj)
    	{
    		for(auto y:x)
    			inDegree[y]++;
    	}
    	queue<int> q;
    	for(int i=0;i<V;i++)
    	{
    		if(inDegree[i]==0)
    			q.push(i);
    	}

    	while(!q.empty())
    	{
    		int node=q.front();
    		q.pop();

    		cout<<node<<" "<<endl;

    		for(auto x:adj[node])
    		{
    			inDegree[x]--;
    			if(inDegree[x]==0)
    				q.push(x);
    		}
    	}
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