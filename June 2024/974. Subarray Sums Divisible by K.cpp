int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int currSum = 0, res = 0;
        for(int x: nums){
            currSum+= x;
            currSum %= k;
            if(currSum<0){
                currSum+=k;
            }
            
            if(mp.find(currSum)!=mp.end()){
                res+= mp[currSum];
            }
            mp[currSum]++;
        }
        return res;
    }