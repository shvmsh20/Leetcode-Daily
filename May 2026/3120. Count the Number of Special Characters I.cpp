int numberOfSpecialChars(string word) {
        int n = word.size();
        unordered_set<char> s;
        int res = 0;
        for(char x: word){
            if(s.find(x)!=s.end()){
                continue;
            }
            if(x>='A' && x<='Z'){
                char lowerCaseChar = 'a'+(x-'A');
                if(s.find(lowerCaseChar)!=s.end()){
                    res++;
                }
            }else{
                char upperCaseChar = 'A'+(x-'a');
                if(s.find(upperCaseChar)!=s.end()){
                    res++;
                }
            }
            s.insert(x);
        }
        return res;
    }