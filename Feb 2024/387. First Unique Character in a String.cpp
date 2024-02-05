int firstUniqChar(string s) {
        vector<int> mp(26, -1);
        for(int i=0; i<s.length(); i++){
            if(mp[s[i]-'a']==-1){
                mp[s[i]-'a'] = i;
            }else{
                mp[s[i]-'a'] = -2;
            }
        }
        int res = INT_MAX;
        for(int i=0; i<26; i++){
            if(mp[i]>-1){
                res = min(res, mp[i]);
            }
        }
        return res==INT_MAX?-1: res;
    }