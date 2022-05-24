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
// M-3 DP
int longestValidParentheses(string s) {
        int n = s.size();
        int mx = 0;
        vector<int> dp(n+1, 0);
        for(int i=1; i<n; i++){
            int j = i-dp[i]-1;
            if(j>=0 && s[i]==')' && s[j]=='('){
                dp[i+1] = dp[i]+dp[j]+2;
            }
            mx = max(mx, dp[i+1]);
        }
        return mx;
    }    