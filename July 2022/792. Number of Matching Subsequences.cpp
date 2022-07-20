int numMatchingSubseq(string s, vector<string>& words) {
        int n = s.length(), count=0, j;
        unordered_map<char, vector<int>> mp;
        for(int i=0; i<n; i++){
            mp[s[i]].push_back(i);
        }
        for(int i=0; i<words.size(); i++){
            int prev = -1;
            for(j=0; j<words[i].size(); j++){
                auto it = upper_bound(mp[words[i][j]].begin(), mp[words[i][j]].end(), prev);
                if(it==mp[words[i][j]].end()){
                    break;
                }else{
                    prev = *it;
                }
            }
            if(j==words[i].size()){
                count++;
            }
        }
        return count;
    }