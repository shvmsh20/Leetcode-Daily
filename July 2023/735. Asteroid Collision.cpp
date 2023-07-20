vector<int> asteroidCollision(vector<int>& as) {
        stack<int> st;
        
        for(int i=0; i<as.size(); i++){
            st.push(as[i]);
            while(st.size()>=2){
                int x = st.top();
                st.pop();
                int y = st.top();
                st.pop();
                if(x*y>0 || (x>0 && y<0)){
                    st.push(y);
                    st.push(x);
                    break;
                }else{
                    if(abs(x)>abs(y)){
                        st.push(x);
                    }else if(abs(y)>abs(x)){
                        st.push(y);
                    }
                }
            }
        }

        vector<int> res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;

    }