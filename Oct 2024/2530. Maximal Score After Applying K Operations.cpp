long long maxKelements(vector<int>& nums, int k) {
        long long res = 0;
        int n = nums.size();
        priority_queue<int> pq(nums.begin(), nums.end());
        while(k--){
            int top = pq.top();
            pq.pop();
            res+= top;
            int afterOp = ceil((1.0*top)/3.00);
            // cout << afterOp << endl;
            pq.push(afterOp);
        }
        return res;
    }