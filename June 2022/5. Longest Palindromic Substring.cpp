int palindromeLength(string &s, int l, int h){
        int n = s.size();
        while(l>=0 && h<n && (s[l]==s[h])){
            l--;
            h++;
        }
        return h-l-1;
    }
    string longestPalindrome(string s) {
        int ans = -1, n = s.size(), start=0, end=0;
        for(int i=0; i<n; i++){
            int len1 = palindromeLength(s, i, i);
            int len2 = palindromeLength(s, i, i+1);
            int mx = max(len1, len2);
            if(mx>ans){
                ans = mx;
                start = i - ((mx-1)/2);
                end = i+ (mx/2);
            }
        }
        
        return s.substr(start, end-start+1);
    }