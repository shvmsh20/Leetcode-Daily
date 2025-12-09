 int specialTriplets(vector<int>& nums) {
        int mod = 1e9+7;
        int n = nums.size();
        unordered_map<int, int> before;
        unordered_map<int, int> after;
        for(int i=0; i<n; i++){
            after[nums[i]]++;
        }
        long long res = 0;
         after[nums[0]]--;
        if(after[nums[0]]==0) after.erase(nums[0]);
         before[nums[0]]++;
        for(int i=1; i<n-1; i++){
            after[nums[i]]--;
        if(after[nums[i]]==0) after.erase(nums[i]);
            int num = nums[i]*2;
            if(before.find(num)!=before.end() && after.find(num)!=after.end()){
                
                    long long temp = (long long)before[num]*after[num];
                    temp = temp%mod;
                    res = (res + temp)%mod;
                
            }
            before[nums[i]]++;
            
        }
        return res;
    }