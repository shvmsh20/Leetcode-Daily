int mod = 1e9+7;
    int countVowelPermutation(int n) {
        vector<int> v(5, 1);
        vector<int> prev(5, 1);
        //a e i o u
        //0 1 2 3 4
        for(int i=2; i<=n; i++){
            for(int j=0; j<5; j++){
                prev[j] = v[j];
            }
            v[0] = (prev[1])%mod;
            v[1] = (prev[0]%mod+prev[2]%mod)%mod;
            v[2] = (((prev[0]%mod)+prev[1]%mod)%mod+(prev[3]%mod+prev[4]%mod)%mod)%mod;
            v[3] = (prev[2]%mod+prev[4]%mod)%mod;
            v[4] = (prev[0])%mod;
        }
        int ans = 0;
        for(int i=0; i<5; i++){
            ans = (ans+v[i])%mod;
        }
        return ans;
    }