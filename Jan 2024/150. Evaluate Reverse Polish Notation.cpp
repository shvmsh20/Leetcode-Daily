bool isOperator(string x){
        if(x=="+" || x=="-" || x=="*" || x=="/"){
            return true;
        }else{
            return false;
        }
    }
    int evalRPN(vector<string>& tokens) {
        stack<long int> st;
        for(string x: tokens){
            if(isOperator(x)){
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                if(x=="+"){
                    st.push(a+b);
                }else if(x=="-"){
                    st.push(a-b);
                }else if(x=="*"){
                    st.push((long int)a*b);
                }else if(x=="/"){
                    st.push(a/b);
                }
            }else{
                st.push(stoi(x));
            }
        }
        return st.top();
    }