double res = 0;
    bool atLeastOnePath = false;
    void dfs(int u, int end, vector<vector<pair<int, double>>> &adj, vector<bool> &vis, double ans){
        if(ans<=1e-5){
            return;
        }
        if(u==end){
            res = max(res, ans);
            atLeastOnePath = true;
            return;
        }
        vis[u] = true;
        for(pair<int, double> &x: adj[u]){
        
          
            int v = x.first;
            double prob = x.second;
            double nextProb = ans*prob;
            if(!vis[v] && !(nextProb<=res)){
                dfs(v, end, adj, vis, nextProb);
            }
        }
        vis[u] = false;
        
    }
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int, double>>> adj(n);
        for(int x=0; x<edges.size(); x++){
            int u = edges[x][0], v = edges[x][1];
            adj[u].push_back({v, succProb[x]});
            adj[v].push_back({u, succProb[x]});
        }
        double ans = 1.00;
        
        vector<bool> vis(n, false);
        dfs(start, end, adj, vis, ans);
        if(!atLeastOnePath){
            return 0.00;
        }
        return res;
    }