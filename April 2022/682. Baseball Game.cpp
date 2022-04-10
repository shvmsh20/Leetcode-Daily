bool isNumber(const string& s)
 {  
    if(s[0]=='-') return true;    
    return s.find_first_not_of("0123456789") == string::npos;
 }
    int calPoints(vector<string>& ops) {
        stack<int> st;
        for(int i=0; i<ops.size(); i++){
            string op = ops[i];
            if(isNumber(op)){
                st.push(stoi(op));
            }else if(op=="C"){
                st.pop();
            }else if(op=="D"){
                st.push(st.top()*2);
            }else if(op=="+"){
                int prev1 = st.top();
                st.pop();
                int prev2 = st.top();
                st.push(prev1);
                st.push(prev1+prev2);
            }
        }
        int res=0;
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        return res;
    }