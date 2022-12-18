vector<int> dailyTemperatures(vector<int>& temp) {
        stack<pair<int, int>> st;
        int n = temp.size();
        vector<int> res(n);
        st.push({temp[n-1], n-1});
        for(int i=n-2; i>=0; i--){
            while(!st.empty() && st.top().first<=temp[i]){
                st.pop();
            }
            if(!st.empty()){
                res[i] = st.top().second-i;
            }
            st.push({temp[i], i});
        }
        return res;
    }