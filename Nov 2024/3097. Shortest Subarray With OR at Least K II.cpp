int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        if(k==0){
            for(int i=0; i<n; i++){
                if(nums[i]>0){
                    return 1;
                }
            }
            return 1;
        }
        vector<int> bits(32, 0);
        int i=0, j=0, res=INT_MAX, currVal=0;
        while(j<n){
            // cout << j << " " << i << endl;
            if(currVal<k){
                int temp = 0;
                int num = nums[j];
                for(int x=0; x<31; x++){
                    if((num>>x) & 1){
                        bits[x]++;
                    }
                    if(bits[x]>0){
                        temp = temp | (1<<x);
                    }
                }
                // cout << temp << endl;
                currVal = temp;
                if(currVal>=k){
                    res = min(res, j-i+1);
                }
                j++;
            }else{
                int temp = 0;
                int num = nums[i];
                for(int x=0; x<31; x++){
                    if((num>>x) & 1){
                        bits[x]--;     
                    }
                     if(bits[x]>0){
                        temp = temp | (1<<x);
                    }
                }
                currVal = temp;
                i++;
                if(currVal>=k){
                    res = min(res, j-i);
                }
                
            }
        }
        while(i<j){
            int temp = 0;
                int num = nums[i];
                for(int x=0; x<31; x++){
                    if((num>>x) & 1){
                        bits[x]--;     
                    }
                     if(bits[x]>0){
                        temp = temp | (1<<x);
                    }
                }
                currVal = temp;
                i++;
                if(currVal>=k){
                    res = min(res, j-i);
                }
        }
        return res == INT_MAX?-1:res;
    }