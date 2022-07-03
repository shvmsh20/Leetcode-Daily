int wiggleMaxLength(vector<int>& nums) {
        int inc=1, dec=1;
        for(int i=1; i<nums.size(); i++){
            if(nums[i]>nums[i-1]){
                inc = dec+1;
            }else if(nums[i]<nums[i-1]){
                dec = inc+1;
            }
        }
        return max(inc, dec);
    }

//OR
int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            return 1;
        }
        int prev = nums[1]-nums[0];
        int count= nums[0]==nums[1]?1:2;
        for(int i=2; i<n; i++){
            int curr = nums[i]-nums[i-1];
            if((curr>0 && prev<=0) || (curr<0 && prev>=0)){
                count++;
                prev = curr;
            }
        }
        return count;
    }    