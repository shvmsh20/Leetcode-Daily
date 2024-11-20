int takeCharacters(string s, int k) {
        int n = s.length(), ca, cb, cc;
        if(k==0){
            return 0;
        }
        unordered_map<int, int> mp_a, mp_b, mp_c;
        mp_a[0] = mp_b[0] = mp_c[0] = n;
        ca = cb = cc = 0;
        for(int i=n-1; i>=0; i--){
            if(s[i]=='a'){
                ca++;
                mp_a[ca] = i;
            }
            if(s[i]=='b'){
                cb++;
                mp_b[cb] = i;
            }
            if(s[i]=='c'){
                cc++;
                mp_c[cc] = i;
            }  
        }
        if(mp_a.find(k)==mp_a.end() || mp_b.find(k)==mp_b.end() || mp_c.find(k)==mp_c.end()){
            return -1;
        }
        ca  = cb = cc = 0;
        int res = n;
        for(int i=0; i<n; i++){
            if(s[i]=='a'){
                ca++;  
            }
            if(s[i]=='b'){
                cb++;
            }
            if(s[i]=='c'){
                cc++;
            }
            int mn = n;
            if((k-ca)>0){
                mn = min(mn, mp_a[k-ca]);
            }
            if((k-cb)>0){
                mn = min(mn, mp_b[k-cb]);
            }
            if((k-cc)>0){
                mn = min(mn, mp_c[k-cc]);
            }
            int ans = (i+1)+n-mn;
            res = min(res, ans);
        }
        res = min(res, n - min(mp_a[k], min(mp_b[k], mp_c[k])));
        return res;
    }