bool canConstruct(string s, int k) {
        int n = s.size();
        if(k>n){
            return false;
        }
        unordered_map<int,int> mp;
        for(char x: s){
            mp[x]++;
        }
        int oddCount = 0;
        for(auto it: mp){
            if(it.second&1){
                oddCount++;
            }
        }
        if(oddCount>k){
            return false;
        }
        return true;
    }