int maxResult(vector<int>& nums, int k) {
        
        int n = nums.size();
        vector<int> dp(n);
        dp[n-1] = nums[n-1];
        priority_queue<pair<int, int>> pq;
        pq.push({nums[n-1], n-1});
        for(int i=n-2; i>=0; i--){
            if(pq.size()<=k){
                dp[i] = nums[i]+pq.top().first;
            }else{
                while(pq.top().second>i+k){
                    pq.pop();
                }
                dp[i] = nums[i]+pq.top().first;
            }
            //cout << dp[i] << " ";
            pq.push({dp[i], i});
            
        }
        return dp[0];
        
    }