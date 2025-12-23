#include<bits/stdc++.h>
using namespace std;

class Graph{
	int V;
	vector<pair<int,int>> l;

public:
	Graph(int V){
		this->V=V;
	}

	void addEdge(int u,int v){
		l.push_back(make_pair(u,v));
	}

	int findSet(int i,vector<int> &parent)
	{
		if(parent[i]==-1)
			return i;
		return parent[i]=findSet(parent[i],parent);
	}

	void unionSet(int p1,int p2,vector<int> &parent,vector<int> &rank)
	{
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

	bool containCycle(){
		//DSU Logic to check if graph contains cycyle or not
		vector<int> parent(V,-1);
		vector<int> rank(V,1);
		for(auto edge:l)
		{
			int i=edge.first;
			int j=edge.second;

			int p1=findSet(i,parent);
			int p2=findSet(j,parent);

			if(p1!=p2)
				unionSet(p1,p2,parent,rank);
			else
				return true;

		}
		parent.clear();
	    return false;
	}
};

int main(){
	Graph g(4);

	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(2,3);
	g.addEdge(3,0);

	cout<<g.containCycle()<<endl;

}