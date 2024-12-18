vector<int> finalPrices(vector<int>& prices) {
        stack<int> st;
        int n = prices.size();
        vector<int> res(n);
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && st.top()>prices[i]){
                st.pop();
            }
            if(st.empty()){
                res[i] = prices[i];
            }else{
                res[i] = prices[i]-st.top();
            }
            st.push(prices[i]);
        }
        return res;
    }