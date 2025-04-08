int minimumOperations(vector<int>& nums) {
        unordered_map<int, int> mp;
        int n = nums.size();
        for(int i=0; i<n; i++){
            mp[nums[i]]++;
        }
        int m = n, currIndex = 0, res = 0;
        while(mp.size()!=m){
            res++;
            for(int i=0; i<3; i++){
                if(currIndex<n){
                    mp[nums[currIndex]]--;
                    if(mp[nums[currIndex]]==0) mp.erase(nums[currIndex]);
                    m--;
                    currIndex++;
                }else{
                    break;
                }
            }
        }
        return res;
    }