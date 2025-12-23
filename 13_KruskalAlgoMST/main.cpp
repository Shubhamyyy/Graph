#include<bits/stdc++.h>
using namespace std;
class DSU{
	vector<int> parent,rank;
public:
	DSU(int n){
		parent.resize(n,-1);
		rank.resize(n,1);
	}

	int find(int i)
	{
		if(parent[i]==-1)
			return i;
		return parent[i]=find(parent[i]);
	}
	void unite(int x,int y)
	{
		int p1=find(x),p2=find(y);

		if(p1==p2)return;
		if(rank[p1]<rank[p2])
		{
			parent[p1]=p2;
			rank[p2]+=rank[p1];
		}
		else
		{
			parent[p2]=p1;
			rank[p1]+=rank[p2];
		}
	}
};

class Graph{
	int V;
	vector<vector<int>> edgeList;

public:
	Graph(int V){
		this->V=V;
	}
	void addEdge(int x,int y,int w)
	{
		edgeList.push_back({w,x,y});
	}

	int kruskalMST()
	{
		sort(edgeList.begin(),edgeList.end());

		DSU s(V);

		int ans=0;
		for(auto edge:edgeList)
		{
			int w=edge[0];
			int x=edge[1];
			int y=edge[2];

			if(s.find(x)!=s.find(y))
			{
				s.unite(x,y);
				ans+=w;
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

	cout<<g.kruskalMST()<<endl;
}