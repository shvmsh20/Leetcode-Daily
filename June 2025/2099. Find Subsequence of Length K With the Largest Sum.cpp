vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());
        unordered_map<int, int> mp;
        while(k--){
            mp[pq.top()]++;
            pq.pop();
        }
        vector<int> res;
        for(int i=0; i<nums.size(); i++){
            if(mp.find(nums[i])!=mp.end()){
                res.push_back(nums[i]);
                mp[nums[i]]--;
                if(mp[nums[i]]==0){
                    mp.erase(nums[i]);
                }
                
            }
        }
        return res;
    }