int solve(int source, int target, vector<vector<int>> &adj){
        int moves = 0;
        queue<int> q;
        q.push(source);
        unordered_set<int> vis;
        vis.insert(source);
        while(!q.empty()){
            int n = q.size();
            for(int i=0; i<n; i++){
                int node = q.front();
                q.pop();
                if(node==target){
                    return moves;
                }
                for(int neigh: adj[node]){
                    if(vis.find(neigh)==vis.end()){
                        vis.insert(neigh);
                        q.push(neigh);
                    }
                }
            }
            moves++;
        }
        return moves;
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> adj(n);
        for(int i=0; i<n-1; i++){
            adj[i].push_back(i+1);
        }
        vector<int> res;
        for(vector<int> x: queries){
            adj[x[0]].push_back(x[1]);
            res.push_back(solve(0, n-1, adj));
        }
        return res;
    }