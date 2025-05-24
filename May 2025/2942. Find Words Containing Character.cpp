bool checkContains(string word, char x){
        for(char y: word){
            if(x==y){
                return true;
            }
        }
        return false;
    }
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> res;
        for(int i=0; i<words.size(); i++){
            if(checkContains(words[i], x)){
                res.push_back(i);
            }
        }
        return res;
    }