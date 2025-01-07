bool isSubstr(string x, string y){
        int n = x.length(), m = y.length();
        if(n>m){
            return false;
        }
        for(int i=0; i<=m-n; i++){
            bool substr = true;
            for(int j=0; j<n; j++){
                if(x[j]!=y[i+j]){
                    substr = false;
                    break;
                }
            }
            if(substr){
                return true;
            }
        }
        return false;
    }
    vector<string> stringMatching(vector<string>& words) {
        vector<string> res;
        int n = words.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i==j){
                    continue;
                }
                if(isSubstr(words[i], words[j])){
                    res.push_back(words[i]);
                    break;
                }
            }
        }
        return res;
    }