bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> mp1;
        unordered_map<char, int> mp2;
        int n = s1.size(), m = s2.size(), matches=0;
        if(n>m){
            return false;
        }
        for(int i=0; i<n; i++){
            mp1[s1[i]]++;
            mp2[s2[i]]++;
        }
        for(char x='a'; x<='z'; x++){
            //cout <<  x << " ";
            if(mp1[x]==mp2[x]){
                matches++;
            }
        }
        int i=0;
        for(int j=n; j<m; j++){
            if(matches==26){
                return true;
            }
            
            mp2[s2[j]]++;
            if(mp1[s2[j]]==mp2[s2[j]]){
                matches++;
            }else if((mp1[s2[j]]+1)==mp2[s2[j]]){
                matches--;
            }
            
            mp2[s2[i]]--;
            
            if(mp1[s2[i]]==mp2[s2[i]]){
                matches++;
            }else if((mp1[s2[i]]-1)==mp2[s2[i]]){
                matches--;
            }
            i++;
            
        }
        
        return matches==26;
    }