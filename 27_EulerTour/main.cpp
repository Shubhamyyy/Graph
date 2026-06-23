#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
vector<int> gr[N];
int tin[N],tout[N],flat[N],tme=0;
void dfs1(int cur,int par)
{
    // cout<<cur<<"  ";
    tin[cur]=tme++;
    for(auto x:gr[cur])
    {
        if(x!=par)
        {
            dfs1(x,cur);
        }
    }
    tout[cur]=tme++;
    // cout<<cur<<"  ";
}
void dfs2(int cur,int par)
{
    // cout<<cur<<"  ";
    for(auto x:gr[cur])
    {
        if(x!=par)
        {
            dfs2(x,cur);
            // cout<<cur<<"  ";
        }
    }
}
void dfs3(int cur,int par)
{
    tin[cur]=++tme;
    for(auto x:gr[cur])
    {
        if(x!=par)
        {
            dfs3(x,cur);
        }
    }
    tout[cur]=tme;
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
    // tme=1;
    // dfs1(1,0);

    // dfs2(1,0);

    tme=0;
    dfs3(1,0);
    for(int i=1;i<=n;i++)
        cout<<i<<" "<<tin[i]<<" "<<tout[i]<<endl;
    for(int i=1;i<=n;i++)
        flat[tin[i]]=i;
    for(int i=1;i<=n;i++)
        cout<<flat[i]<<"  ";

}