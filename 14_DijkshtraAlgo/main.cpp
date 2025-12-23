#include<bits/stdc++.h>
using namespace std;
class Graph{
	int V;
	vector<vector<pair<int,int>>> l;

public:
	Graph(int v){
		V=v;
		l.resize(v);
	}
	void addEdge(int u,int v,int wt,bool undir=true)
	{
		l[u].push_back({wt,v});
		if(undir)
			l[v].push_back({wt,u});
	}
	int dijkstra(int src,int dest)
	{
		vector<int> dist(V,INT_MAX);
		priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

		dist[src]=0;
		pq.push({0,src});

		while(!pq.empty())
		{
			auto node=pq.top();
			pq.pop();

			int queueX=node.second;
			int queueWT=node.first;
			
			if(queueWT>dist[queueX])
				continue;

			for(auto pair:l[queueX])
			{
				int pairX=pair.second;
				int pairWT=pair.first;

				if(queueWT+pairWT<dist[pairX])
				{
					dist[pairX]=queueWT+pairWT;
					pq.push({dist[pairX],pairX});
				}
			}
		}
		for(int i=0;i<V;i++)
			cout<<"Node i "<<i<<" Dist "<<dist[i]<<endl;
		return dist[dest];
	}
};
int main()
{
	Graph g(5);
	g.addEdge(0,1,1);
	g.addEdge(1,2,1);
	g.addEdge(0,2,4);
	g.addEdge(0,3,7);
	g.addEdge(3,2,2);
	g.addEdge(3,4,3);

	cout<<g.dijkstra(0,4)<<endl;
}
