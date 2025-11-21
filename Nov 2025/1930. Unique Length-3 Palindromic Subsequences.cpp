int countPalindromicSubsequence(string s) {
        int n = s.length(), res = 0;
        unordered_map<char, int>mp;
        for(int i=2; i<n; i++){
            mp[s[i]]++;
        }
        vector<int> freq(26, 0);
        unordered_set<string> st;
        freq[s[0]-'a']++;
        for(int i=1; i<n-1; i++){
            if(i!=1){
                mp[s[i]]--;
            }
            for(int j=0; j<26; j++){
                if(freq[j] && mp['a'+j]){
                    string t = string(1, 'a' + j) + s[i] + string(1, 'a' + j);
                    st.insert(t);
                }
            }
            freq[s[i]-'a']++;
            
        }
        return st.size();
    }