 int numberOfSubstrings(string s) {
        int n = s.size();
        vector<int> a(n, INT_MAX), b(n, INT_MAX), c(n, INT_MAX);
        if(s[n-1]=='a'){
            a[n-1] = n-1;
        }else if(s[n-1]=='b'){
            b[n-1] = n-1;
        }else{
            c[n-1] = n-1;
        }
        for(int i=n-2; i>=0; i--){
            if(s[i]=='a'){
                a[i] = i;
            }else{
                a[i]= a[i+1];
            }
            if(s[i]=='b'){
                b[i] = i;
            }else{
                b[i]= b[i+1];
            }
            if(s[i]=='c'){
                c[i] = i;
            }else{
                c[i]= c[i+1];
            }
        }
        int res = 0;
        for(int i=0; i<n; i++){
            int mxIndex = max(a[i], max(b[i], c[i]));
            if(mxIndex==INT_MAX){
                continue;
            }
            res+= n-mxIndex;
        }
        return res;
    }