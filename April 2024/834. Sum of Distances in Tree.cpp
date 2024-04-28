void dfs(int u, int level, vector<bool> &vis, vector<vector<int>> &adj, int &ans){
        vis[u] = true;
        for(int v: adj[u]){
            if(vis[v]==false){
                ans+= level+1;
                dfs(v, level+1, vis, adj, ans);
            }
        }
    }
    int findChild(int u, vector<int> &child, vector<vector<int>> &adj, vector<bool> &vis){
        int res=0;
        vis[u] = true;
        for(int v: adj[u]){
            if(vis[v]==false){
                res+=findChild(v, child, adj, vis);
            }
        }
        child[u] = res+1;
        return child[u];
    }
    void solve(int u, int prevAns, vector<int> &child, vector<vector<int>> &adj, 
    vector<bool> &vis, vector <int> &res, int n){
        vis[u] = true;
        int ans = prevAns - child[u] + (n-child[u]);
        res[u] = ans;
        for(int v: adj[u]){
            if(vis[v]==false){
                solve(v, ans, child, adj, vis, res, n);
            }
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto x: edges){
            int a = x[0], b = x[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        vector<bool> vis(n, false);
        int ans = 0;
        dfs(0, 0, vis, adj, ans);
        vector<int> res(n);
        vector<int> child(n);
        for(int i=0; i<n; i++){
            vis[i] = false;
        }
        findChild(0, child, adj, vis);
        for(int i=0; i<n; i++){
            vis[i] = false;
        }
        solve(0, ans+child[0], child, adj, vis, res, n);
        return res;
    }