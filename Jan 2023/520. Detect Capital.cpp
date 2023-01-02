bool detectCapitalUse(string word) {
        bool fCap = false, rCap = false, rnCap = false;
        if(word.size()==1){
            return true;
        }
        if(word[0]>='A' && word[0]<='Z'){
            fCap = true;
        }
        for(int i=1; i<word.size(); i++){
            if(word[i]>='A' && word[i]<='Z'){
                rCap = true;
            }else{
                rnCap = true;
            }
        }
        return (fCap==true && rCap==false && rnCap==true) || (fCap && rCap && rnCap==false) || (fCap==false && rCap==false && rnCap);
    }