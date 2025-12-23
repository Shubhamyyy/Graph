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
    bool dfs(int source,vector<bool> &visited,vector<bool> &stack)
    {
    	visited[source]=true;
        stack[source]=true;

        bool ans=false;
    	for(auto nbrs:adj[source])
    	{
            if(!visited[nbrs])
                ans|=dfs(nbrs,visited,stack);
            else if(stack[nbrs])
                ans=true;

            if(ans)return true;
    	}
        stack[source]=false;
    	return ans;
    }
    bool containsCycle()
    {
    	vector<bool> visited(V,false);
        vector<bool> stack(V,false);
    	
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                if(dfs(i,visited,stack))
                    return true;
            }
        }
        return false;
    }

};

int main()
{
	Graph g(3);
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(2,0);
	
	cout<<g.containsCycle()<<endl;
}