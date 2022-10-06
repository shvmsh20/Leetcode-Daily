unordered_map<string, vector<pair<int, string>>>mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        
        int l = 0;
        int h = mp[key].size()-1;
        string res = "";
        while(l<=h){
            int m = l+(h-l)/2;
            if(mp[key][m].first<timestamp){

                res = mp[key][m].second;
                l = m+1;
            }else if(mp[key][m].first>timestamp){
                h = m-1;
            }else{
                return mp[key][m].second;
            }
        }
        return res;
    }