bool areAlmostEqual(string s1, string s2) {
        int swapsNeeded = 0;
        vector<int> freq(26, 0);
        for(int i=0; i<s1.length(); i++){
            if(s1[i]!=s2[i]){
                swapsNeeded++;
            }
            freq[s1[i]-'a']++;
            freq[s2[i]-'a']--;
        }
        for(int i=0; i<26; i++){
            if(freq[i]!=0){
                return false;
            }
        }
        if(swapsNeeded%2){
            return false;
        }
        swapsNeeded/=2;
        if(swapsNeeded<=1){
            return true;
        }
        return false;
    }