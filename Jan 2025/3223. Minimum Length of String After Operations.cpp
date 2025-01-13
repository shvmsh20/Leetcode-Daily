int minimumLength(string s) {
        unordered_map<char, int> mp;
        for(char x: s){
            mp[x]++;
        }
        int res = 0;
        for(auto x: mp){
            int cnt = x.second;
            if(cnt==1 || cnt==2){
                res+= cnt;
            }else{
                if(cnt%2==0){
                    res+= 2;
                }else{
                    res++;
                }
            }
        }
        return res;
    }