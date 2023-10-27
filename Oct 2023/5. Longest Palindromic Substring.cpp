int helper(string &s, int a, int b, int n){
        while(a>=0 && b<n){
            if(s[a]==s[b]){
                a--;
                b++;
            }else{
                break;
            }
        }
        return b-a-1;
    }
    string longestPalindrome(string s) {
        int n = s.length();
        int res = 0;
        string ans;
        for(int i=0; i<n; i++){
            int t1 = helper(s, i, i, n);
            int t2 = helper(s, i, i+1, n);
            int t = max(t1, t2);
            if(t>res){
                int st = i-(t-1)/2;
                int end = i+t/2;
                res = t;
                ans = s.substr(st, end-st+1);
            }
            
        }
        return ans;
    }