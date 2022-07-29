vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        int n = pattern.size(), j;
        for(int i=0; i<words.size(); i++){
            if(n!=words[i].size()){
                continue;
            }
            unordered_map<char, char> mp;
            unordered_set<char> s;
            for(j=0; j<n; j++){
                if(mp.find(pattern[j])==mp.end()){
                    if(s.find(words[i][j])!=s.end()){
                        break;
                    }
                    mp[pattern[j]] = words[i][j];
                }else if(mp[pattern[j]]!=words[i][j]){
                    break;
                }
                s.insert(words[i][j]);
            }
            if(j==n){
                res.push_back(words[i]);
            }
        }
        return res;
    }