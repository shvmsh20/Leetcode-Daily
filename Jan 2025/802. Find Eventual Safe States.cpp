bool dfs(int node, unordered_map<int, bool> &mp, vector<vector<int>>& graph){
        mp[node] = false;
        for(int v: graph[node]){
            if(mp.find(v)!=mp.end()){
                if(mp[v]==false){
                    return false;
                } 
            }else if(!dfs(v, mp, graph)){
                return false;
            } 
        }
        mp[node] = true;
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> res;
        int n = graph.size();
        unordered_map<int, bool> mp;
        for(int i=0; i<n; i++){
            if(mp.find(i)==mp.end()){
                dfs(i, mp, graph);
            }
        }
        for(int i=0; i<n; i++){
            if(mp[i]){
                res.push_back(i);
            }
        }
        return res;
    }