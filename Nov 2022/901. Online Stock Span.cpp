stack<pair<int, int>> st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int d=1;
        while(!st.empty() && st.top().first<=price){
            d+= st.top().second;
            st.pop();
        }
        st.push({price, d});
        return d;
    }