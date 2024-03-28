int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int n = nums.size();
        int i=0, j=0, res=0;
        while(j<n){
            if(mp[nums[j]]<k){
                mp[nums[j]]++;
                res = max(res, j-i+1);
                j++;
            }else{
                mp[nums[i]]--;
                i++;
            }
        }
        return res;
    }