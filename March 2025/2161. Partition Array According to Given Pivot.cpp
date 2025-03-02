vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> res(n);
        int i=0, j=n-1;
        for(int left=0, right=n-1; left<n; left++, right--){
            if(nums[left]<pivot){
                res[i] = nums[left];
                i++;
            }
            if(nums[right]>pivot){
                res[j] = nums[right];
                j--;
            }
        }
        while(i<=j){
            res[i] = pivot;
            i++;
        }
        
        return res;
    }