bool dfs(int pColor, int u, vector<int> &color, vector<vector<int>> &adj){
        color[u] = 1^pColor;
        for(int v: adj[u]){
            if(color[v]==-1 && dfs(color[u], v, color, adj)==false){
                return false;
            }else if(color[v]==color[u]){
                return false;
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n);
        for(int i=0; i<dislikes.size(); i++){
            int a = dislikes[i][0]-1;
            int b = dislikes[i][1]-1;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        vector<int> color(n, -1);
        for(int i=0; i<n; i++){
            if(color[i]==-1 && dfs(0, i, color, adj)==false){
                return false;
            }
        }
        return true;
    }