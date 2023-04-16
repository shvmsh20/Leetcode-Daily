string minWindow(string s, string t) {
        unordered_map<char, int> mp1;
        unordered_map<char, int> mp2;
        for(char x: t){
            mp1[x]++;
        }
        int have=0, need=mp1.size();
        int res = INT_MAX, i=0, left=-1, right=-1;
        string ans="";
        for(int j=0; j<s.size(); j++){
            if(mp1.find(s[j])==mp1.end()){
                continue;
            }
            mp2[s[j]]++;
            if(mp2[s[j]]==mp1[s[j]]){
                have++;
            }
            while(i<=j && have==need){
                if(res>j-i+1){
                    res = j-i+1;
                    left = i;
                    right = j;
                }
                if(mp1.find(s[i])==mp1.end()){
                    i++;
                }else{
                    mp2[s[i]]--;
                    if(mp2[s[i]]<mp1[s[i]]){
                        have--;
                    }
                    i++;
                }
            }
        }
        return res==INT_MAX?"":s.substr(left, right-left+1);
        
    }