bool closeStrings(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        if(n!=m){
            return false;
        }
        vector<int> freq1(26, 0), freq2(26, 0);
        for(int i=0; i<n; i++){
            freq1[word1[i]-'a']++;
            freq2[word2[i]-'a']++;
        }
        for(char x = 'a'; x<='z'; x++){
            if(freq1[x-'a']!=0 && freq2[x-'a']!=0){
                continue;
            }
            if(freq1[x-'a']!=0 || freq2[x-'a']!=0){
                return false;
            }
        }
        sort(freq1.begin(), freq1.end());
        sort(freq2.begin(), freq2.end());
        for(int i=0; i<26; i++){
            if(freq1[i]!=freq2[i]){
                return false;
            }
        }
        return true;
    }