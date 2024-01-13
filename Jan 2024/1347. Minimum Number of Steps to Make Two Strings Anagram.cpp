int minSteps(string s, string t) {
        int n = s.length();
        vector<int> freq(26, 0);
        for(int i=0; i<n; i++){
            freq[t[i]-'a']++;
            freq[s[i]-'a']--;
        }
        int res = 0;
        for(int i=0; i<26; i++){
            res+= freq[i]>0? freq[i]: 0;
        } 
        return res;
    }