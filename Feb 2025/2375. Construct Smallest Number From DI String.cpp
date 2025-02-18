string smallestNumber(string pattern) {
        stack<int> st;
        string res;
        for(int i=0; i<=pattern.size(); i++){
            st.push(i+1);
            if(i==pattern.size() || pattern[i]=='I'){
                while(!st.empty()){
                    res.push_back((st.top()+'0'));
                    st.pop();
                }
            }
        }
        return res;
    }