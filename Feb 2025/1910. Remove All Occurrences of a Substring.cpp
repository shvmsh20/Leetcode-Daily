bool checkAndRemove(stack<char> &st, string &part, int m){
        if(m==0){
            return true;
        }
        if(st.top()!=part[m-1]){
            return false;
        }
        char x = st.top();
        st.pop();
        if(checkAndRemove(st, part, m-1)){
            return true;
        }
        st.push(x);
        return false;
    }
    string removeOccurrences(string s, string part) {
        stack<char> st;
        int n = s.length(), m = part.size();
        for(int i=0; i<n; i++){
            st.push(s[i]);
            if(s[i]==part[m-1] && st.size()>=m){
                checkAndRemove(st, part, m);
            }
        }
        string res;
        while(!st.empty()){
            res = st.top() + res;
            st.pop();
        }
        return res;
    }