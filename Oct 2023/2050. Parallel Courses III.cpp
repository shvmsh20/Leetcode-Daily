int dp[50001];
    int dfs(int i,vector<int>adj[],vector<int>&time)
{
    if(dp[i]!=-1) return dp[i];
    int cur=0;
    for(int j:adj[i])
    cur=max(cur,dfs(j,adj,time));
    return dp[i]=cur+time[i-1];
}
int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
    vector<int>adj[n+1];
    memset(dp,-1,sizeof(dp));
    for(auto v:relations)
    adj[v[1]].push_back(v[0]);
    int ans=0;
    for(int i=1;i<=n;i++)
    ans=max(ans,dfs(i,adj,time));
    return ans;
}