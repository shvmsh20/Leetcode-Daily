long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq(gifts.begin(), gifts.end());
        while(k--){
            int top = pq.top();
            pq.pop();
            int x = sqrt(top);
            pq.push(x);
        }
        long long res = 0;
        while(!pq.empty()){
            res+= pq.top();
            pq.pop();
        }
        return res;
    }