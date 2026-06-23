#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
vector<int> gr[N];
void dfs(int cur,int par)
{
    for(auto x:gr[cur])
    {
        if(x!=par)
            dfs(x,cur);
    }
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++)
    {
        int x,y;
        cin>>x>>y;
        gr[x].push_back(y);
        gr[y].push_back(x);
    }
    dfs(1,-1);
}