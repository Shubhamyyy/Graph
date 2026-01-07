#include<bits/stdc++.h>
using namespace std;
int tsp(vector<vector<int>> &dist,int setOfCities,int city,int n,vector<vector<int>> &dp)
{
	if(setOfCities==(1<<n)-1)
		return dist[city][0];

	if(dp[setOfCities][city]!=-1)return dp[setOfCities][city];

	int ans=INT_MAX;
	for(int choice=0;choice<n;choice++)
	{
		if((setOfCities&(1<<choice))==0)
			ans=min(ans,dist[city][choice]+tsp(dist,setOfCities|(1<<choice),choice,n,dp));
	}
	return dp[setOfCities][city]=ans;
}
int main()
{
	int n=4;
	vector<vector<int>> dist={
		{0,20,42,25},
		{20,0,30,34},
		{42,30,0,10},
		{25,34,10,0}
	};
	vector<vector<int>> dp(1<<n,vector<int>(n,-1));
	cout<<tsp(dist,1,0,n,dp)<<endl;
}