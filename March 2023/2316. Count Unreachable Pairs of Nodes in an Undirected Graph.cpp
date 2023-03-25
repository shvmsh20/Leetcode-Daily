long long dfs(int node, vector<bool> &vis, vector<vector<int>> &adj){
        vis[node] = true;
        long long count=1;
        for(int x: adj[node]){
            if(vis[x]==false){
                count+= dfs(x, vis, adj);
            }
        }
        return count;
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto x: edges){
            int u = x[0];
            int v = x[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        long long res=0;
        vector<bool> vis(n, false);
        for(int i=0; i<n; i++){
            if(vis[i]==false){
                long long t = dfs(i, vis, adj);
                res+= t*(n-t);
            }
        }
        return res/2;
    }