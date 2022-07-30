vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> res;
        int n = words2.size();
        unordered_map<char, int> mp2;
        unordered_map<char, int> mp;
        for(int i=0; i<n; i++){
            mp.clear();
            for(int j=0; j<words2[i].size(); j++){
                mp[words2[i][j]]++;
                if(mp2.find(words2[i][j])==mp2.end()){
                    mp2[words2[i][j]]++;
                }else if(mp2[words2[i][j]]<mp[words2[i][j]]){
                    mp2[words2[i][j]] = mp[words2[i][j]];
                }
            }
        }
        int m = words1.size();
        for(int i=0; i<m; i++){
            unordered_map<char, int> mp1;
            for(int j=0; j<words1[i].size(); j++){
                mp1[words1[i][j]]++;
            }
            bool f1 = true;
            for(auto x: mp2){
                if(mp1.find(x.first)==mp1.end() || mp1[x.first]<x.second){
                    f1 = false;
                    break;
                }
            }
            if(f1){
                res.push_back(words1[i]);
            }
        }
        return res;
    }