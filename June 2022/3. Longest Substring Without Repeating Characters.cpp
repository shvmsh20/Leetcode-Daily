nt lengthOfLongestSubstring(string s) {
        unordered_map<int, int> mp;
        int l=0, r=0, n = s.size();
        int ans=0;
        while(r<n){
            if((mp.count(s[r])==0) || (mp.count(s[r])>0 && mp[s[r]]<l)){
                ans = max(ans, r-l+1);
                mp[s[r]] = r;
                r++;
            }else{
                l = mp[s[r]]+1;
            }
        }
        return ans;
    }