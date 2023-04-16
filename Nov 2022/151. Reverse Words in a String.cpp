void reverse(string &s, int i, int j){
        while(i<j){
            swap(s[i++], s[j--]);
        }
    }
    string reverseWords(string s) {
        int n = s.size();
        int i=0, j=0;
        int wordsCount=0;
        while(i<n){
            while(i<n && s[i]==' '){
                i++;
            }
            if(i==n){
                break;
            }
            if(wordsCount){
                s[j++] = ' ';
            }
            int start = j;
            while(i<n && s[i]!=' '){
                s[j++] = s[i++];
            }
            reverse(s, start, j-1);
            wordsCount++;
        }
        s.resize(j);
        reverse(s, 0, j-1);
        return s;
    }