int maxScore(string s) {
        int onesRight = 0, zerosLeft = 0, res = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='1'){
                onesRight++;
            }
        }
        for(int i=0; i<s.size()-1; i++){
            char x = s[i];
            if(x=='1'){
                onesRight--;
            }else{
                zerosLeft++;
            }
            res = max(res, zerosLeft+onesRight);
        }
        return res;
    }