//M-1 Stack
int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);
        int mx = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='('){
                st.push(i);
            }else{
                st.pop();
                if(st.empty()){
                    st.push(i);
                }else{
                    mx = max(mx, i-st.top());
                }
            }
        }
        return mx;
    }

//M-2
int longestValidParentheses(string s) {
        int open=0, n=s.size();
        int close=0;
        int mx = 0;
        for(int i=0; i<n; i++){
            if(s[i]=='('){
                open++;
            }else{
                close++;
            }
            if(close==open){
                mx = max(mx, 2*open);
            }else if(close>open){
                close=0;
                open=0;
            }
        }
        open=0;
        close=0;
        for(int i=n-1; i>=0; i--){
            if(s[i]==')'){
                close++;
            }else{
                open++;
            }
            if(open==close){
                mx = max(mx, open*2);
            }else if(open>close){
                open=0;
                close=0;
            }
        }
        return mx;
    }    