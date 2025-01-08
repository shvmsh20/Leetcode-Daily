bool isPrefixAndSuffix(string x, string y){
        int n = x.length(), m = y.length();
        if(n>m){
            return false;
        }
        for(int i=0; i<n; i++){
            if(x[i]!=y[i]){
                return false;
            }
        }
        for(int i=n-1, j=m-1; i>=0; i--, j--){
            if(x[i]!=y[j]){
                return false;
            }
        }
        return true;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size(), res = 0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(isPrefixAndSuffix(words[i], words[j])){
                    res++;
                }
            }
        } 
        return res;
    }