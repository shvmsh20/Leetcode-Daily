unordered_map<string, bool> mp;
    bool solve(string s1, string s2){
        if(s1==s2) return true;
        if(s1.length()<=1) return false;
        string key = s1+ " " +s2;  
        if(mp.find(key)!=mp.end()){
            return mp[key];
        }
        int n = s1.size();
        bool flag = false;
        for(int i=1; i<=n-1; i++){
            bool cond1 = solve(s1.substr(0, i), s2.substr(n-i, i)) && solve(s1.substr(i, n-i),                   s2.substr(0, n-i));
            bool cond2 = solve(s1.substr(0, i), s2.substr(0, i)) && solve(s1.substr(i, n-i),                     s2.substr(i, n-i));
            if(cond1 || cond2){
                flag = true;
                break;
            }
        }
        return mp[key] = flag;
        
    }
    bool isScramble(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        if(n1!=n2) return false;
        if(n1==0 && n2==0) return true;
        return solve(s1, s2);
    }