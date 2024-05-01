string reversePrefix(string word, char ch) {
        int n = word.size();
        int index = -1;
        for(int i=0; i<n; i++){
            if(word[i]==ch){
                index = i;
                break;
            }
        }
        if(index==-1){
            return word;
        }
        int st = 0, end = index;
        while(st<end){
            char temp = word[st];
            word[st] = word[end];
            word[end] = temp;
            st++;
            end--;
        }
        return word;
    }