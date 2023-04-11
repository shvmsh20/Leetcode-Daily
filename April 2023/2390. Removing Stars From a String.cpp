tring removeStars(string s) {
        int n = s.length();
        int count=0;
        string str;
        for(int i=n-1; i>=0; i--){
            if(count==0 && s[i]!='*'){
                str+=s[i];
            }else if(s[i]=='*'){
                count++;
            }else if(s[i]!='*'){
                count--;
            }
        }
        reverse(str.begin(), str.end());
        return str;
    }