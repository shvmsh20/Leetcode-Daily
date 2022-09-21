vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int> res(n);
        int sum=0;
        for(int x: nums){
            if(x%2==0){
                sum+=x;
            }
        }
        for(int i=0; i<n; i++){
            int index = queries[i][1];
            int to_add = queries[i][0];
            
            if(nums[index]%2==0){
                sum-=nums[index];
                if((nums[index]+to_add)%2==0){
                    sum+=(nums[index]+to_add);
                }
            }else{
                if((nums[index]+to_add)%2==0){
                    sum+=(nums[index]+to_add);
                }
            }
            nums[index] = nums[index]+to_add;
            res[i] = sum;
        }
        return res;
    }