 bool chck(char a, char b){
        if((a=='(' && b==')') || (a=='{' && b=='}') || (a=='[' && b==']')){
            return true;
        }
        return false;
    }
    bool isValid(string s) {
        int n = s.length();
        stack<char> st;
        for(int i=0; i<n; i++){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
                st.push(s[i]);
            }else{
                if(st.empty() || chck(st.top(), s[i])==false){
                    return false;
                }else{
                    st.pop();
                }
            }
        }

    return st.empty();
    }