int countBinarySubstrings(string s) {
        int res = 0;
        int prevChain = 0, currChain = 1;
        for(int i=1; i<s.size(); i++){
            if(s[i]==s[i-1]){
                currChain++;
                if(prevChain>=currChain){
                    res++;
                }
            }else{
                res++;
                prevChain = currChain;
                currChain = 1;
            }
        }
        return res;

    }