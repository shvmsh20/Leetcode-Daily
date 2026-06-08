vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> res(n);
        int greaterPivotCount = 0;
        for(int i=0; i<n; i++){
            if(nums[i]>pivot){
                greaterPivotCount++;
            }
        }
        int smallPivotIndex=0, greaterPivotIndex=n-greaterPivotCount;
        for(int i=0; i<n; i++){
            if(nums[i]>pivot){
                res[greaterPivotIndex] = nums[i];
                greaterPivotIndex++;
            }else if(nums[i]<pivot){
                res[smallPivotIndex] = nums[i];
                smallPivotIndex++;
            }
        }
        while(smallPivotIndex<n-greaterPivotCount){
            res[smallPivotIndex] = pivot;
            smallPivotIndex++;
        }
        return res;
    }