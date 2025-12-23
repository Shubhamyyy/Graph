#include<bits/stdc++.h>
using namespace std;
class Graph{
	int V;
	vector<vector<pair<int,int>>> l;

public:
	Graph(int n){
		V=n;
		l.resize(n);
	}

	void addEdge(int x,int y,int w)
	{
		l[x].push_back({y,w});
		l[y].push_back({x,w});
	}

	int primMST()
	{
		priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

		vector<bool> visited(V,false);
		int ans=0;

		pq.push({0,0});

		while(!pq.empty())
		{
			auto best=pq.top();
			pq.pop();

			int weight=best.first;
			int to=best.second;

			if(visited[to])
				continue;

			ans+=weight;
			visited[to]=true;

			for(auto x:l[to])
			{
				if(!visited[x.first])
					pq.push({x.second,x.first});
			}

		}
		return ans;
	}
};


int main()
{
	Graph g(4);

	g.addEdge(0,1,1);
	g.addEdge(0,2,2);
	g.addEdge(0,3,2);
	g.addEdge(1,2,2);
	g.addEdge(1,3,2);
	g.addEdge(2,3,3);

	cout<<g.primMST()<<endl;

}