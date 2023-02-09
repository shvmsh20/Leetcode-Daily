long long distinctNames(vector<string>& ideas) {
        unordered_set<string> mp;
        int n = ideas.size();
        for(int i=0; i<n; i++){
            mp.insert(ideas[i]);
        }
        int count=0;
        vector<vector<int>> v(26, vector<int> (26));
        for(int i=0; i<n; i++){
            string word = ideas[i].substr(1);
            for(int j=0; j<26; j++){
                char c = 'a'+j;
                string newWord = c+word;
                if(mp.find(newWord)==mp.end()){
                    v[ideas[i][0]-'a'][j]++;
                }
            }
        }
        long long  ans=0;
        for(int i=0; i<26; i++){
            for(int j=0; j<26; j++){
                if(i==j) continue;
                else if(v[i][j]>0){
                    ans+= v[i][j]*v[j][i];
                }
            }
        }
        return ans;
    }