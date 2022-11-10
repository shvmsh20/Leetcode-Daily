string removeDuplicates(string s) {
        stack<char> st;
        int n=s.size();
        for(int i=0; i<n; i++){
            if(!st.empty() && st.top()==s[i]){
                st.pop();
            }else{
                st.push(s[i]);
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