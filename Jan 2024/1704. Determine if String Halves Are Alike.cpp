bool isVowel(char c){
        return c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U';
    }
    bool halvesAreAlike(string s) {
        int n = s.size();
        int firstHlf = 0, secondHlf = 0;
        for(int i=0; i<n/2; i++){
            if(isVowel(s[i])){
                firstHlf++;
            }
        }
        for(int i=n/2; i<n; i++){
            if(isVowel(s[i])){
                secondHlf++;
            }
        }
        return firstHlf == secondHlf;
    }