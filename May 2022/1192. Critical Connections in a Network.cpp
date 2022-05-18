void dfs(int u, vector<int> &disc, vector<int> &low, vector<int> &parent,
        vector<vector<int>> &adj, vector<vector<int>> &res){
        
        static int time = 0;
        disc[u] = time;
        low[u] = time;
        time++;
        for(int v: adj[u]){
            if(disc[v]==-1){
                parent[v] = u;
                dfs(v, disc, low, parent, adj, res);
                low[u] = min(low[u], low[v]);
                if(low[v]>disc[u]){
                    res.push_back(vector<int>({u, v}));
                }
            }else{
                if(v!=parent[u]){
                    low[u] = min(disc[v], low[u]);
                }
            }
        }
    }
            
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> parent(n, -1);
        vector<int> low(n, -1);
        vector<int> disc(n, -1);
        vector<vector<int>> res;
        vector<vector<int>> adj(n);
        for(auto x: connections){
            int u = x[0];
            int v = x[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i=0; i<n; i++){
            if(disc[i]==-1){
                dfs(i, disc, low, parent, adj, res);
            }
        }
        return res;
    }