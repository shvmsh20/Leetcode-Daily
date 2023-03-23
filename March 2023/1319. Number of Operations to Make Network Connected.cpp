void dfs(int u, vector<vector<int>> &adj, vector<bool> &vis){
        vis[u] = true;
        for(int v: adj[u]){
            if(vis[v]==false){
                dfs(v, adj, vis);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int e = connections.size();
        //condition for MST
        if(e<n-1){
            return -1;
        }
        vector<vector<int>> adj(n);
        for(auto x: connections){
            int u = x[0];
            int v = x[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int count=0;
        vector<bool> vis(n, false);
        for(int i=0; i<n; i++){
            if(vis[i]==false){
                count++;
                dfs(i, adj, vis);
            }
        }
        
        //find redundent edges
        int red = e - ((n-1)-(count-1));
        if(red>=count-1){
            return count-1;
        }
        return -1;
    }