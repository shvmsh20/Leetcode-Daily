string smallestPalindrome(string s) {
        vector<int> freq(26);
        for(char x: s){
            int index = x-'a';
            freq[index]++;
        }
        string first;
        char odd = '1';
        for(int i=0; i<26; i++){
            if(freq[i] && freq[i]&1){
                odd = 'a' + i;
            }
            if(freq[i]){
                int cnt = freq[i]/2;
                while(cnt--){
                    first+= 'a'+i;
                }
                freq[i] = 0;
            }
        }
        string second = first;
        reverse(second.begin(), second.end());
        string res = first;
        if(odd!='1'){
            res.push_back(odd);
        }
        res+= second;
        return res;
    }