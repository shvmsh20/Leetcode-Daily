int longestIdealString(string s, int k) {
        unordered_map<int, int> mp;
        for(int i=0; i<s.length(); i++){
            
            int curr = 1;
            if(mp.find((int)s[i])!=mp.end()){
                curr = mp[(int)s[i]];
            }
            //previous
            int st = (int)s[i]-k;
            for(int j=st; j<=(int)s[i]; j++){
                if(mp.find(j)!=mp.end()){
                    curr = max(curr, 1+mp[j]);
                }
            }
            //end;
            int ed = (int)s[i]+k;
            for(int j=ed; j>=(int)s[i]; j--){
                if(mp.find(j)!=mp.end()){
                    curr = max(curr, 1+mp[j]);
                }
            }
            mp[(int)s[i]] = curr;
        }
        int res = 1;
        for(auto it: mp){
            res = max(res, it.second);
        }
        return res;
    }