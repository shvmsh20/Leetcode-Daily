int numberOfSpecialChars(string word) {
        vector<int> freq(56);
        unordered_set<char> s;
        for(char x: word){
            if(x>='a' && x<='z'){
                int index = 2*(x-'a');
                freq[index]++;
                if(freq[index+1]){
                    s.erase(index);
                }
            }else {
                int index = 2*(x-'A')+1;
                if(freq[index]){
                    continue;
                }
                freq[index]++;
                if(freq[index-1]){
                    s.insert(index-1);
                }
            }
        }
        return s.size();
    }