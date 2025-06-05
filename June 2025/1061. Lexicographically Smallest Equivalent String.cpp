char dfs(char u, vector<vector<char>> &adj, unordered_set<char> &vis, unordered_map<char, char> &mp, char parent){
        vis.insert(u);
        char x = parent;
        char p = min(x, u);
        for(char v: adj[u-'a']){
            if(vis.find(v)==vis.end()){
                x = min(x, dfs(v, adj, vis, mp, p));
            }
        }
        x = min(x, u);
        mp[u] = x;
        return x;
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<vector<char>> adj(26);
        int n = s1.size();
        for(int i=0; i<n; i++){
            adj[s1[i]-'a'].push_back(s2[i]);
            adj[s2[i]-'a'].push_back(s1[i]);
        }
        unordered_map<char, char> mp;
        unordered_set<char> vis;
        for(char u='a'; u<='z'; u++){
            if(vis.find(u)==vis.end()){
                dfs(u, adj, vis, mp, 'z');
            }
        }
        string res;
        for(int i=0; i<baseStr.size(); i++){
            res.push_back(mp[baseStr[i]]);
        }
        return res;
        
    }