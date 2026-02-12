bool isBalanced(unordered_map<char, int> &mp){
        int prev = -1;
        for(auto it: mp){
            if(prev==-1){
                prev = it.second;
            }else if(it.second!=prev){
                return false;
            }
        }
        return true;
    }
    int longestBalanced(string s) {
        int n = s.size();
        int res = 0;
        for(int i=0; i<n; i++){
            unordered_map<char, int> mp;
            for(int j=i; j<n; j++){
                mp[s[j]]++;
                if(isBalanced(mp)){
                    res = max(res, j-i+1);
                }
            }
        }
        return res;
    }