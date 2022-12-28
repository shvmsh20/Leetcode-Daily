int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq(piles.begin(), piles.end());
        for(int i=0; i<k; i++){
            int x = pq.top();
            pq.pop();
            x = x - x/2;
            pq.push(x);
        }
        int res = 0;
        while(!pq.empty()){
            res+=pq.top();
            pq.pop();
        }
        return res;
    }