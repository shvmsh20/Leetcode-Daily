bool dfs(int src, int des, vector<vector<int>> &adj, unordered_set<int> &vis){
        if(src==des){
            return true;
        }
        vis.insert(src);
        for(int x: adj[src]){
            if(vis.find(x)==vis.end() && dfs(x, des, adj, vis)){
                return true;
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int src, int des) {
        if(src==des){
            return true;
        }
        vector<vector<int>> adj(n);
        for(auto x: edges){
            int u = x[0];
            int v = x[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        unordered_set<int> vis;
        if(dfs(src, des, adj, vis)){
            return true;
        }else{
            
            return false;
        }
    }