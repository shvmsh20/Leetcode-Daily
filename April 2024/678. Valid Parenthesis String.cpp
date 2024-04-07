bool checkValidString(string s) {
        stack<int> open;
        stack<int> star;
        int n = s.length();
        for(int i=0; i<n; i++){
            if(s[i]=='('){
                open.push(i);
            }else if(s[i]=='*'){
                star.push(i);
            }else{
                if(!open.empty()){
                    open.pop();
                }else if(!star.empty()){
                    star.pop();
                }else{
                    return false;
                }
            }
        }
        while(!open.empty()){
            if(!star.empty() && open.top()<star.top()){
                open.pop();
                star.pop();
            }else{
                return false;
            }
        }
        return true;
    }