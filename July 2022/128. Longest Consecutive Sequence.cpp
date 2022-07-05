int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set;
        for(int x: nums){
            set.insert(x);
        }
        int res=0;
        for(int i=0; i<nums.size(); i++){
            int curr_num = nums[i];
            int count=1;
            if(set.find(curr_num-1)==set.end()){
                while(set.find(curr_num+count)!=set.end()){
                    count++;
                }
            }
            res = max(res, count);
            
        }
        return res;
    }