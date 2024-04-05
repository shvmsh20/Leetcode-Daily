string makeGood(string s) {
        stack<int> st;
        for(int i=0; i<s.length(); i++){
            if(st.empty()){
                st.push(s[i]);
            }else{
                char top = st.top();
                if(top>='a' && top<='z' && (top-'a'==s[i]-'A')){
                    st.pop();
                }else if(top>='A' && top<='Z' && (top-'A'==s[i]-'a')){
                    st.pop();
                }else{
                    st.push(s[i]);
                }
            }
        }
        string res;
        while(!st.empty()){
            res+= st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }