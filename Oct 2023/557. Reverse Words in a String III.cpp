void rev(int i, int j, string &s){
        while(i<j){
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }
    string reverseWords(string s) {
        int n = s.length();
        int i=0, j=0;
        for(j; j<n; j++){
            if(s[j]==' '){
                rev(i, j-1, s);
                i = j+1;
            }
        }
        if(j==n){
            rev(i, j-1, s);
        }
        return s;
    }