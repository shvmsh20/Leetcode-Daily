bool dfs(string src, unordered_map<string, vector<string>> &mp, vector<string> &res, 
            int n){
        res.push_back(src);
        if(res.size()==1+n){
            return true;
        }
        if(mp.find(src)==mp.end()){
             res.pop_back();
            return false;
        }
        vector<string> temp = mp[src];
        for(int i=0; i<temp.size(); i++){
            string v = mp[src][i];
            mp[src].erase(mp[src].begin()+i);
            if(dfs(v, mp, res, n)){
                return true;
            }
            mp[src].insert(mp[src].begin()+i, v);
        }
        res.pop_back();
        return false;
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string>> mp;
        for(vector<string> s: tickets){
            mp[s[0]].push_back(s[1]);
        }
        for(auto &x: mp){
            sort(x.second.begin(), x.second.end());
        }
        vector<string> res;
        int n = tickets.size();
        dfs("JFK", mp, res, n);
        
        return res;
    }