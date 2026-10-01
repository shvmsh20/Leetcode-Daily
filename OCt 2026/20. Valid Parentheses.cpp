bool check(char x, char y){
        if((x=='(' && y==')') || (x=='{' && y=='}') || (x=='[' && y==']')){
            return true;
        }
        return false;
    }
    bool isValid(string s) {
        stack<char> st;
        int n = s.size();
        for(int i=0; i<n; i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                st.push(s[i]);
            }else{
                if(st.empty()){
                    return false;
                }
                char top = st.top();
                st.pop();
                if(!check(top, s[i])){
                    return false;
                }
            }
        }
        return st.empty();
    }