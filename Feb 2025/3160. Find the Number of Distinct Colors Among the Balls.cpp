vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> mp;
        unordered_map<int, int> freq;
        vector<int> res;
        for(vector<int> v: queries){
            int x = v[0], y = v[1];
            if(mp.find(x)!=mp.end()){
                int oldColor = mp[x];
                freq[oldColor]--;
                if(freq[oldColor]==0){
                    freq.erase(oldColor);
                }
                
            }
            freq[y]++;
            mp[x] = y;
            res.push_back(freq.size());
        }
        return res;
    }