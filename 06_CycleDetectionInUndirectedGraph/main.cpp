#include<bits/stdc++.h>
using namespace std;
class Graph{
	int V;
    vector<vector<int>> adj;

public:
    Graph(int v) {
        V = v;
        adj.resize(V);
    }
    void addEdge(int i,int j,bool undir=true)
    {
    	adj[i].push_back(j);
    	if(undir)
    		adj[j].push_back(i);
    }
    bool dfs(int source,vector<bool> &visited,int parent)
    {
    	visited[source]=true;

        bool ans=false;
    	for(auto nbrs:adj[source])
    	{
    		if(!visited[nbrs])
                ans|=dfs(nbrs,visited,source);
    		else if(nbrs!=parent)
    			ans=true;

            if(ans)return true;
    	}
    	return ans;
    }
    bool containsCycle()
    {
    	vector<bool> visited(V,false);
    	for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                if(dfs(i,visited,-1))
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
	g.addEdge(0,2);
	
	cout<<g.containsCycle()<<endl;
}