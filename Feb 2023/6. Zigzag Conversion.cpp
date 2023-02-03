string convert(string s, int numRows) {
        if(numRows==1){
            return s;
        }
        int n = s.length();
        string res;
        int increment = 2*(numRows-1);
        for(int i=0; i<numRows; i++){
            for(int j=i; j<n; j+=increment){
                res+= s[j];
                if(i>0 && i<numRows-1 && (j+increment-(2*i))<n){
                    res+= s[j+increment-(2*i)];
                }
            }
        }
        return res;
    }