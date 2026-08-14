int maximumLengthSubstring(string s) {
        int n = s.size();
        int left = 0, res = 2;
        unordered_map<int, int> mp;
        for(int right=0; right<n; right++){
            mp[s[right]]++;
            while(mp[s[right]]>2){
                mp[s[left]]--;
                left++;
            }
            res = max(res, right-left+1);
        } 
        return res;
    }