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
    bool dfs(int source,vector<int> &color,int currColor)
    {
        color[source]=currColor;

        bool ans=true;
        for(auto nbrs:adj[source])
        {
            if(color[nbrs]==-1)
                ans&=dfs(nbrs,color,currColor^1);
            else if(color[nbrs]==color[source])
                ans=false;

            if(!ans)return false;
        }
        return ans;
    }
    bool isBipartite()
    {
        vector<int> color(V,-1);
        
        for(int i=0;i<V;i++)
        {
            if(color[i]==-1)
            {
                if(!dfs(i,color,0))
                    return false;
            }
        }
        return true;
    }

};

int main()
{
    Graph g(3);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,0);
    
    cout<<g.isBipartite()<<endl;
}