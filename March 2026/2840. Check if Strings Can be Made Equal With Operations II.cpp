bool checkStrings(string s1, string s2) {
        unordered_map<char, int> even, odd;
        int n = s1.size();
        for(int i=0; i<n; i++){
            if(i%2==0){
                even[s1[i]]++;
            }else {
                odd[s1[i]]++;
            }
        }
        for(int i=0; i<n; i++){
            if(i%2==0){
                if(even.find(s2[i])==even.end() || even[s2[i]]==0){
                    return false;
                }
                even[s2[i]]--;
            }else {
                if(odd.find(s2[i])==odd.end() || odd[s2[i]]==0){
                    return false;
                }
                odd[s2[i]]--;
            }
        }
        return true;
    }