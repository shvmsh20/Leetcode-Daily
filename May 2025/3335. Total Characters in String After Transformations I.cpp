int lengthAfterTransformations(string s, int t) {
        int n = s.size(), index = 0;
        vector<int> freq(26, 0);
        for(int i=0; i<n; i++){
            index = s[i]-'a';
            freq[index]++;
        }
        // for(int i=0; i<26; i++){
        //     cout << freq[i] << endl;
        // }
        int mod = 1e9+7;
        for(int i=0; i<t; i++){
            vector<int> temp(26, 0);
            for(int j=0; j<26; j++){
                if(freq[j]){
                    if(j!=25){
                        temp[j+1] = (temp[j+1]+freq[j])%mod;
                    }else{
                        temp[0] = (temp[0]+freq[j])%mod;
                        temp[1] = (temp[1]+freq[j])%mod;
                    }
                } 
            }
            for(int j=0; j<26; j++){
                // cout << temp[j] << " ";
                freq[j] = temp[j];
            }
        }
        int res = 0;
        for(int i=0; i<26; i++){
            res = (res + freq[i])%mod;
        }
        return res;
    }