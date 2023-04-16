bool reorderedPowerOf2(int n) {
        long long int t=1;
        unordered_map<string, int> mp;
        while(t<=1e9){
            string tmp = to_string(t);
            sort(tmp.begin(), tmp.end());
            mp[tmp]++;
            t = 2*t;
        }
        string s = to_string(n);
        sort(s.begin(), s.end());
        if(mp.find(s)!=mp.end()){
            return true;
        }
        return false;
    }