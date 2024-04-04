int maxDepth(string s) {
        int n = s.length(), res = 0;
        stack<char> st;
        for(int i=0; i<n; i++){
            if(s[i]=='('){
                st.push('(');
            }else if(s[i]==')'){
                st.pop();
            }
            int m = st.size();
            res = max(res, m);
        }
        return res;
    }