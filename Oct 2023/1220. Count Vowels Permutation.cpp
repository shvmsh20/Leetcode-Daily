int mod = 1e9+7;
    int helper(char last, int n, unordered_map<string, int> &mp){
        if(n==0){
            return 1;
        }
        string key = to_string(last)+"#"+to_string(n);
        if(mp.find(key)!=mp.end()){
            return mp[key];
        }
        int val=0;
        switch(last){
            case 'a':
                val = helper('e', n-1, mp)%mod;
                break;
            case 'e':
                val = (helper('a', n-1, mp)+helper('i', n-1, mp))%mod;
                break;
            case 'i':
                val = ((helper('a', n-1, mp)%mod+helper('e', n-1, mp)%mod)%mod+(helper('o', n-1, mp)%mod+helper('u', n-1, mp)%mod)%mod)%mod;
                break; 
            case 'o':
                val = (helper('i', n-1, mp)%mod+helper('u', n-1, mp)%mod)%mod;
                break;
            case 'u':
                val = helper('a', n-1, mp)%mod;
                break;  
            default:
                val=0;
                
        }
        return mp[key] = val;
    }
    int countVowelPermutation(int n) {
        vector<char> v = {'a', 'e', 'i', 'o', 'u'};
        int total = 0;
        unordered_map<string, int> mp;
        for(int i=0; i<5; i++){
            total = (total+helper(v[i], n-1, mp))%mod;
        }
        
        return total;
    }