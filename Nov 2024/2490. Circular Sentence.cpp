bool isCircularSentence(string sentence) {
        char curr = 'x';
        int n = sentence.size();
        for(int i=0; i<n; i++){
            if(sentence[i]==' '){
                if(curr!=sentence[i+1]){
                    return false;
                }
            }
            curr = sentence[i];
        }
        if(sentence[0]!=sentence[n-1]){
            return false;
        }
        return true;
    }