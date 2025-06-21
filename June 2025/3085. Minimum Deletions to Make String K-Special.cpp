int minimumDeletions(string word, int k) {
        unordered_map<int, int> mp;
        for(char x: word){
            mp[x-'a']++;
        }
        vector<int> freq;
        for(auto x: mp){
            freq.push_back(x.second);
        }
        int res = INT_MAX;
        for(int i=0; i<freq.size(); i++){
            int cnt = 0;
            for(int j=0; j<freq.size(); j++){
                if(i==j){
                    continue;
                }
                if(freq[j]>(freq[i]+k)){
                    cnt+= freq[j]-freq[i]-k;
                }else if(freq[j]<freq[i]){
                    cnt+= freq[j];
                }
            }
            res = min(res, cnt);
        }
        retur