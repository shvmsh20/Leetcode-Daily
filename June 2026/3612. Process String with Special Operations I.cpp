string processStr(string s) {
        string res;
        for(char x: s){
            if(x>='a' && x<='z'){
                res.push_back(x);
            }else if(x=='*'){
                if(res.size()){
                    res.pop_back();
                }
            }else if(x=='#'){
                res += res;
            }else if(x=='%'){
                reverse(res.begin(), res.end());
            }
        }
        return res;
    }