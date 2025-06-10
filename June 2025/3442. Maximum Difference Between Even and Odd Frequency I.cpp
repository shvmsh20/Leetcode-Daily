int maxDifference(string s) {
        vector<int> freq(26);
        for(char x: s){
            freq[x-'a']++;
        }
        int res = INT_MIN;
        for(int i=0; i<26; i++){
            for(int j=0; j<26; j++){
                if(freq[i]==0 || freq[j]==0 || i==j){
                    continue;
                }
                if(freq[i]&1 && freq[j]%2==0){
                    res = max(res, freq[i]-freq[j]);
                }
            }
        }
        return res;
    }