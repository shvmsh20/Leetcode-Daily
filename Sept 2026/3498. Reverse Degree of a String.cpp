 int reverseDegree(string s) {
        int n = s.size();
        int res = 0;
        for(int i=0; i<n; i++){
            res += (('z'-s[i]+1)*(i+1));
        }
        return res;
    }