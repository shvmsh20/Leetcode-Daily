//Using 2 stacks
bool backspaceCompare(string s, string t) {
        stack<char> s1;
        stack<char> s2;
        for(int i=0; i<s.length(); i++){
            if(s[i]=='#'){
                if(!s1.empty()){
                    s1.pop();
                }
            }else{
                s1.push(s[i]);
            }
        }
        for(int i=0; i<t.length(); i++){
            if(t[i]=='#'){
                if(!s2.empty()){
                    s2.pop();
                }
            }else{
                s2.push(t[i]);
            }
        }
        if(s1.size()!=s2.size()){
            return false;
        }
        while(!s1.empty()){
            if(s1.top()!=s2.top()){
                return false;
            }
            s1.pop();
            s2.pop();
        }
        return true;
    }

//without stacks
bool backspaceCompare(string s, string t) {
        int i = s.length()-1;
        int j = t.length()-1;
        while(i>=0 || j>=0){
            int c1=0;
            while(i>=0 && (c1>0 || s[i]=='#')){
                if(s[i]=='#'){
                    c1++;
                }else{
                    c1--;
                }
                i--;
            }
            int c2=0;
            while(j>=0 && (c2>0 || t[j]=='#')){
                if(t[j]=='#'){
                    c2++;
                }else{
                    c2--;
                }
                j--;
            }
            if(i>=0 && j>=0){
                if(s[i]!=t[j]){
                    return false;
                }else{
                    i--;
                    j--;
                }
            }else if(i>=0 || j>=0){
                return false;
            }
        }
        return true;
    }    