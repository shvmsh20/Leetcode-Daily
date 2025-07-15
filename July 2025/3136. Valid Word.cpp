bool isValid(string word) {
        int n = word.size();
        if(n<3) return false;
        bool vowel = false, consonant = false;
        for(char x: word){
            if(x>='a' && x<='z'){
                if(x=='a' || x=='e' || x=='i' || x=='o' || x=='u'){
                    vowel = true;
                }else{
                    consonant = true;
                }
            }else if(x>='A' && x<='Z'){
                if(x=='A' || x=='E' || x=='I' || x=='O' || x=='U'){
                    vowel = true;
                }else{
                    consonant = true;
                }
            }else if(x>='0' && x<='9'){
                continue;
            }else{
                return false;
            }
        }
        return vowel && consonant;
    }