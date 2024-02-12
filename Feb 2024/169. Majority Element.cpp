int majorityElement(vector<int>& nums) {
        int freq = 1, res = nums[0];
        for(int i=1; i<nums.size(); i++){
            if(nums[i]==res){
                freq++;
            }else{
                freq--;
            }
            if(freq==0){
                freq = 1;
                res = nums[i];
            }
        } 
        return res;
    }