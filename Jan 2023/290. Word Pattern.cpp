bool wordPattern(string pattern, string s) {
        int n = pattern.size();
        int j=0, i=0;
        unordered_map<char, string> mp1;
        unordered_map<string, char> mp2;
        for(; i<n && j<s.size(); i++){
            string temp;
            while(j<s.size() && s[j]!=' '){
                temp+=s[j];
                j++;
            }
            
            
            if(mp1.find(pattern[i])!=mp1.end()){
                if(mp1[pattern[i]]!=temp){
                    return false;
                }
            }else if(mp2.find(temp)!=mp2.end()){
                if(mp2[temp]!=pattern[i]){
                    return false;
                }
            }else{
                mp1[pattern[i]] = temp;
                mp2[temp] = pattern[i];
            }
            if(j!=s.size()){
                j++;
            }
        }
        
        return i==n && j==s.size();
    }