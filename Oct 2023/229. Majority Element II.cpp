vector<int> majorityElement(vector<int>& nums) {
        int maj1=-1, maj2=-1;
        int count1=0, count2=0;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(nums[i]==maj1){
                count1++;
            }else if(nums[i]==maj2){
                count2++;
            }else if(count1==0){
                count1++;
                maj1=nums[i];
            }else if(count2==0){
                count2++;
                maj2=nums[i];
            }else{
                count1--;
                count2--;
            }
        }
        count1=0, count2=0;
        for(int i=0; i<n; i++){
            if(nums[i]==maj1){
                count1++;
            }else if(nums[i]==maj2){
                count2++;
            }
        }
        vector<int> res;
        if(count1>n/3){
            res.push_back(maj1);
        }
        if(count2>n/3){
            res.push_back(maj2);
        }
        return res;
    }