bool solve(string s, string pattern){
        int n = s.size(), m = pattern.size();
        if(m>n){
            return false;
        }
        for(int i=0; i<m; i++){
            if(s[i]!=pattern[i]){
                return false;
            }
        }
        return true;
    }
    int isPrefixOfWord(string sentence, string searchWord) {
        vector<string> words;
        string word;
        int n = sentence.size();
        for(int i=0; i<n; i++){
            if(sentence[i]==' '){
                words.push_back(word);
                word.clear();
            }else{
                word.push_back(sentence[i]);
            }
        }
        if(word.size()){
            words.push_back(word);
        }
        for(int i=0; i<words.size(); i++){
            if(solve(words[i], searchWord)){
                return i+1;
            }
        }
        return -1;
    }