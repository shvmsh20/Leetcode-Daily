int numDecodings(string s) {
        int n = s.length();
        if(s[0]=='0'){
            return 0;
        }
        vector<int> dp(n+1);
        int c1 = 1;
        int c2 = 1;
        int count=0 ;
        for(int i=2; i<=n; i++){
            int d1 = s[i-1]-'0', t=0;
            if(d1!=0){
                t+=c2;
            }
            int d2 = ((s[i-2]-'0')*10)+d1;
            if(d2>9 && d2<27){
                t+=c1;
            }
            c1 = c2;
            c2 = t;
        }
        return c2;
    }