bool dfs(int currNode, int des, vector<vector<int>> &adj, unordered_set<int> &vis){
        if(currNode==des){
            return true;
        }
        vis.insert(currNode);
        for(int neigh: adj[currNode]){
            if(vis.find(neigh)==vis.end()){
                if(dfs(neigh, des, adj, vis)){
                    return true;
                }
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for(vector<int>&x: edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        unordered_set<int> vis;
        return dfs(source, destination, adj, vis);
    }