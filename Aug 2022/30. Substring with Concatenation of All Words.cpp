vector<int> findSubstring(string s, vector<string>& words) {
        
        vector<int> res;
        int n = words.size();
        int m = words[0].size();
        if(s.size()<m*n){
            return res;
        }
        for(int i=0; i<=s.length()-m*n; i++){
            unordered_map<string, int> mp;
            for(auto x: words){
                mp[x]++;
            }
            int t=0;
            for(t=0; t<n; t++){
                string temp = s.substr(i+t*m, m);
                if(mp.count(temp)!=0){
                    if(mp[temp]==0){
                        break;
                    }
                    mp[temp]--;
                }else{
                    break;
                }
            }
            if(t==n){
                res.push_back(i);
            }
        }
        return res;
    }