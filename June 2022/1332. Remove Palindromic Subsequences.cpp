int removePalindromeSub(string s) {
        int n = s.size();
        if(n==0){
            return 0;
        }
        int l=0, r=n-1;
        bool flag = true;
        while(l<n){
            if(s[l]!=s[r]){
                return 2;
            }else{
                l++;
                r--;
            }
        }
        return 1;
    }