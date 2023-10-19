bool backspaceCompare(string s, string t) {
        int i = s.length()-1;
        int j = t.length()-1;
        while(i>=0 || j>=0){
            int c1=0;
            while(i>=0 && (c1>0 || s[i]=='#')){
                if(s[i]=='#'){
                    c1++;
                }else{
                    c1--;
                }
                i--;
            }
            int c2=0;
            while(j>=0 && (c2>0 || t[j]=='#')){
                if(t[j]=='#'){
                    c2++;
                }else{
                    c2--;
                }
                j--;
            }
            if(i>=0 && j>=0){
                if(s[i]!=t[j]){
                    return false;
                }else{
                    i--;
                    j--;
                }
            }else if(i>=0 || j>=0){
                return false;
            }
        }
        return true;
    }