nt minOperations(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        int res = 0;
        for(auto x: mp){
            int freq = x.second;
            if(freq==1){
                return -1;
            }
            if(freq%3==0){
                res+= freq/3;
            }else{
                res+= (freq/3)+1;
            }
        }
        return res;
    }