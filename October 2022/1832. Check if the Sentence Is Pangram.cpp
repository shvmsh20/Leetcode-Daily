bool checkIfPangram(string s) {
        vector<int> v(26);
        for(int i=0; i<s.size(); i++){
            int index = s[i]-'a';
            v[index]++;
        }
        for(int i=0; i<26; i++){
            if(v[i]==0){
                return false;
            }
        }
        return true;
    }