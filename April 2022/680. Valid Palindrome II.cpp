bool solve(string &s, int l, int h, bool &flag){
        while(l<h){
            if(s[l]==s[h]){
                l++;
                h--;
            }else{
                if(flag){
                    flag=false;
                    if(solve(s, l+1, h, flag) || solve(s, l, h-1, flag)){
                        return true;
                    }else{
                        return false;
                    }
                    
                }else{
                    return false;
                }
            }
        }
        return true;
    }
    bool validPalindrome(string s) {
        bool flag = true;
        return solve(s, 0, s.length()-1, flag);
    }