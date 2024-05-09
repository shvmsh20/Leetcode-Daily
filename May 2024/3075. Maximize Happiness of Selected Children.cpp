long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long int curr_sub = 0, max_happ = 0;
        
        priority_queue<int>pq;
        for(int h:happiness){
            pq.push(h);
        }
        
        while(k>0 and pq.size()>0 and pq.top() + curr_sub >= 0) {
            int curr_happ = pq.top() + curr_sub;
            max_happ += curr_happ;
            pq.pop();
            curr_sub -= 1;
            k--;
        }
        return max_happ;
    }