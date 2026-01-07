#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
vector<int> gr[N];
int vis[N],disc[N],low[N];
int tme=1;
vector<pair<int,int>> bridges;
set<int> artiPoints;
void dfs(int cur,int par)
{
	vis[cur]=1;
	disc[cur]=low[cur]=tme++;
	int child=0;
	for(auto x:gr[cur])
	{
		if(!vis[x])
		{
			dfs(x,cur);
			child++;
			low[cur]=min(low[cur],low[x]);

			if(low[x]>disc[cur])
				bridges.push_back({cur,x});

			if(par!=-1 && low[x]>=disc[cur])
			artiPoints.insert(cur);	

		}
		else if(x!=par)
		{
			low[cur]=min(low[cur],disc[x]);
			
		}
	}
	if(par==-1 && child>1)
		artiPoints.insert(cur);
}
int main()
{
	int n,m;
	cin>>n>>m;

	for(int i=0;i<m;i++)
	{
		int x,y;
		cin>>x>>y;
		gr[x].push_back(y);
		gr[y].push_back(x);
	}
	
	dfs(1,-1);
	for(auto x:artiPoints)
		cout<<x<<endl;
	for(auto x:bridges)
		cout<<x.first<<" "<<x.second<<endl;

}