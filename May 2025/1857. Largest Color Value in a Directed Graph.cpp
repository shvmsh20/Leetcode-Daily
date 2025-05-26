int dfs(int node, vector<vector<int>> &adj, string &colors, unordered_set<int> &vis, unordered_set<int> &path, vector<vector<int>> &cnt){
        if(path.find(node)!=path.end()){
            return INT_MAX;
        }
        if(vis.find(node)!=vis.end()){
            return 0;
        }
        path.insert(node);
        vis.insert(node);
        int colorIndex = colors[node]-'a';
        cnt[node][colorIndex] = 1;
        for(int neigh: adj[node]){
            if(dfs(neigh, adj, colors, vis, path, cnt)==INT_MAX){
                return INT_MAX;
            }
            for(int i=0; i<26; i++){
                cnt[node][i] = max(cnt[node][i], cnt[neigh][i]+(i==colorIndex?1:0));
            }
        }
        path.erase(node);
        int mx = 0;
        for(int i=0; i<26; i++){
            mx = max(mx, cnt[node][i]);
        }
        return mx;
    }
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>> cnt(n, vector<int>(26, 0));
        unordered_set<int> vis, path;
        int res = 0;
        vector<vector<int>> adj(n);
        for(vector<int> x: edges){
            adj[x[0]].push_back(x[1]);
        }
        for(int i=0; i<n; i++){
            res = max(res, dfs(i, adj, colors, vis, path, cnt));
        }
        return res == INT_MAX ? -1: res;
    }