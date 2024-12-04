bool canMakeSubsequence(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        vector<int> letter;
        for(char x='a'; x<='z'; x++){
            letter.push_back(x);
        }
        if(m>n){
            return false;
        }
        int x = 0;
        for(int i=0; i<n; i++){
            if(str1[i]==str2[x] || letter[(str1[i]-'a'+1)%26]==str2[x]){
                x++;
            }
            if(x==m){
                return true;
            }
        }
        return false;
    }