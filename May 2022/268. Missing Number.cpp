int missingNumber(vector<int>& nums) {
        int sum=0;
        for(int x: nums){
            sum+=x;
        }
        int n = nums.size();
        return n*(n+1)/2-sum;
    }