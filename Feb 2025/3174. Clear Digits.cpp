string clearDigits(string s) {
        stack<char> st;
        for(char x: s){
            if(x>='0' && x<='9'){
                if(!st.empty()){
                    st.pop();
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