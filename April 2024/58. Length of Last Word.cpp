int lengthOfLastWord(string s) {
        int res = 0,n = s.size();
        bool seenWord = false;
        for(int i=n-1; i>=0; i--){
            if(s[i]==' ' && seenWord){
                return res;
            }else if(s[i]!=' '){
                res++;
                seenWord = true;
            }
        }
        return res;
    }