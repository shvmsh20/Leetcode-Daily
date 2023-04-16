void dfs(int u, vector<vector<int>> &adj, vector<bool> &visited, vector<int> &temp){
        visited[u] = true;
        temp.push_back(u);
        for(auto v: adj[u]){
            if(visited[v]==false){
                dfs(v, adj, visited, temp);
            }
        }
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        vector<vector<int>> adj(n);
        for(int i=0; i<pairs.size(); i++){
            int u = pairs[i][0];
            int v = pairs[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        string res(n, '-');
        vector<bool> visited(n, false);
        vector<vector<int>> components;
        int count=0;
        for(int i=0; i<n; i++){
            if(visited[i]==false){
                vector<int> temp;
                dfs(i, adj, visited, temp);
                components.push_back(temp);
            }
        }
        
        for(int i=0; i<components.size(); i++){
            string str;
            vector<int> index;
            for(int j=0; j<components[i].size(); j++){
                str.push_back(s[components[i][j]]);
                index.push_back(components[i][j]);
            }
            sort(str.begin(), str.end());
            sort(index.begin(), index.end());
            for(int i=0; i<str.length(); i++){
                res[index[i]] = str[i];
            }
        }
       
    
        return res;
    }