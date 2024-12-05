bool canChange(string s, string t) {
        vector<int> ls;
        vector<int> lt;
        vector<int> rs;
        vector<int> rt;
        int n=s.size();
        string x, y;
        for(int i=0; i<n; i++){
            if(s[i]=='L' || s[i]=='R'){
                x.push_back(s[i]);
            }
        }
        for(int i=0; i<n; i++){
            if(t[i]=='L' || t[i]=='R'){
                y.push_back(t[i]);
            }
        }
        if(x!=y){
            //cout << 1;
            return false;
        }
        
        for(int i=0; i<n; i++){
            if(t[i]=='L'){
                lt.push_back(i);
            }
            if(s[i]=='L'){
                ls.push_back(i);
            }
        }
        for(int i=n-1; i>=0; i--){
            if(t[i]=='R'){
                rt.push_back(i);
            }
            if(s[i]=='R'){
                rs.push_back(i);
            }
        }
        if((ls.size()!=lt.size()) || (rs.size()!=rt.size())){
            //cout << 2;
            return false;
        }
        for(int i=0; i<ls.size(); i++){
            int currP = ls[i];
            int desP = lt[i];
            if(currP<desP){
                return false;
            }
        }
        for(int i=0; i<rs.size(); i++){
            int currP = rs[i];
            int desP = rt[i];
            if(currP>desP){
                return false;
            }
        }
        return true;
       
    }