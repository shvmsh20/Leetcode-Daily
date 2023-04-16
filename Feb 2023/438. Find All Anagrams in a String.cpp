vector<int> findAnagrams(string s, string p) {
        int m = s.size(), n = p.size();
        vector<int> res;
        if(n>m){
            return res;
        }
        vector<int> mp1(26);
        vector<int> mp2(26);
        int matches=0;
        for(int i=0; i<n; i++){
            int index = s[i]-'a';
            mp2[index]++;
            index = p[i]-'a';
            mp1[index]++;
        }
        for(int i=0; i<26; i++){
            if(mp1[i]==mp2[i]){
                matches++;
            }
        }
        
        int i=0;
        for(int j=n; j<m; j++){
            if(matches==26){
                res.push_back(i);
            }
            
            mp2[s[i]-'a']--;
            
            if(mp1[s[i]-'a']==mp2[s[i]-'a']){
                matches++;
            }else if(mp1[s[i]-'a']-1==mp2[s[i]-'a']){
                matches--;
            }
            
            mp2[s[j]-'a']++;
            
            if(mp1[s[j]-'a']==mp2[s[j]-'a']){
                matches++;
            }else if(mp1[s[j]-'a']+1==mp2[s[j]-'a']){
                matches--;
            }
            
            i++;
        }
        if(matches==26){
            res.push_back(i);
        }
        return res;
        
    }