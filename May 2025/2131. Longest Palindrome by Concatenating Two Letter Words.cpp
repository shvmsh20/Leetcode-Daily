int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> mp;
        int res = 0;
        for(string x: words){
            mp[x]++;
        }
        bool odd = false;
        for(pair<string, int> p: mp){
            string x = p.first;
            int cnt1 = p.second;
            if(x[0]==x[1]){
                res+= cnt1/2;
                if(cnt1&1){
                    odd = true;
                }
            }else{
                string rev = x;
                reverse(rev.begin(), rev.end());
                if(mp.find(rev)!=mp.end()){
                    int cnt2 = mp[rev];
                    mp.erase(rev);
                    res+= min(cnt1, cnt2);
                }
            }
        }
        res = res*4;
        if(odd){
            res+=2;
        }
        return res;
    }