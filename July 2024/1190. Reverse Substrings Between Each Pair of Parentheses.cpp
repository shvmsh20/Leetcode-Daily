string reverseParentheses(string s) {
        stack<char> st;
        queue<char> q;
        for(char x: s){
            if(x==')'){
                while(st.top()!='('){
                    q.push(st.top());
                    st.pop();
                }
                st.pop();
                while(!q.empty()){
                    st.push(q.front());
                    q.pop();
                }
                
            }else{
                st.push(x);
            }
        }
        string res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }