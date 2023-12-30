bool makeEqual(vector<string>& words) {
        int n = words.size();
        unordered_map<char, int> mp;
        for(int i=0; i<n; i++){
            for(char x: words[i]){
                mp[x]++;
            }
        }
        for(auto it = mp.begin(); it!=mp.end(); it++){
            if((it->second)%n!=0){
                return false;
            }
        }
        return true;
    }