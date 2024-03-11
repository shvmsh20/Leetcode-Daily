string customSortString(string order, string s) {
        
        unordered_map<char, int> mp;
        for(int i=0; i<s.size(); i++){
            mp[s[i]]++;
        }
        string res;
        for(int i=0; i<order.size(); i++){
            if(mp.find(order[i])!=mp.end()){
                int itr = mp[order[i]];
                while(itr--){
                    res+= order[i];
                }
                mp.erase(order[i]);
            }
        }
        for(auto x: mp){
            char c = x.first;
            int itr = x.second;
            while(itr--){
                res+= c;
            }
        }
        return res;
        
    }