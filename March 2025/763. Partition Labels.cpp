vector<int> partitionLabels(string s) {
        unordered_map<char, int> mp;
        int n = s.size();
        for(int i=n-1; i>=0; i--){
            if(mp.find(s[i])==mp.end()){
                mp[s[i]] = i;
            }
        }
        vector<int> res;
        int st = 0, currMax = 0;
        for(int i=0; i<n; i++){
            currMax = max(currMax, mp[s[i]]);
            if(currMax==i){
                res.push_back(i-st+1);
                st = i+1;
                currMax = i+1;
            }
        }
        return res;
    }