 string clearStars(string s) {
        unordered_map<char, set<int>> mp;
        int n = s.length();
        for(int i=0; i<n; i++){
            if(s[i]!='*'){
                mp[s[i]].insert(i);
            }else{
                for(char x='a'; x<='z'; x++){
                    if(mp[x].size()){
                        auto it = mp[x].end();
                        it--;
                        int index = *it;
                        
                        mp[x].erase(index);
                        s[index] = '#';
                        break;
                    }
                }
            }
        }
        string res;
        for(char x: s){
            if(x!='*' && x!='#'){
                res.push_back(x);
            }
        }
        return res;
    }