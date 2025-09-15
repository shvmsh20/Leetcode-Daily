int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char> broken;
        for(char x: brokenLetters){
            broken.insert(x);
        }
        int cnt = 0;
        for(int i=0; i<text.size(); i++){
            if(text[i]==' '){
                cnt++;
            }
            if(broken.find(text[i])!=broken.end()){
                while(i<text.size() && text[i]!=' '){
                    i++;
                }
            }
            if(i==text.size()-1){
                cnt++;
            }
        }
        return cnt;
    }