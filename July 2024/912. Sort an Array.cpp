void merge(vector<int> &nums, int st, int mid, int end){
        vector<int> temp;
        int p1 = st, p2 = mid+1;
        while(p1<=mid && p2<=end){
            if(nums[p1]<=nums[p2]){
                temp.push_back(nums[p1++]);
            }else{
                temp.push_back(nums[p2++]);
            }
        }
        while(p1<=mid){
            temp.push_back(nums[p1++]);
        }
        while(p2<=end){
            temp.push_back(nums[p2++]);
        }
        for(int i=st; i<=end; i++){
            nums[i] = temp[i-st];
        }
    }
    void mergeSort(vector<int> &nums, int st, int end){
        if(st>=end){
            return;
        }
        int mid = st+(end-st)/2;
        mergeSort(nums, st, mid);
        mergeSort(nums, mid+1, end);
        merge(nums, st, mid, end);
    }
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size()-1);
        return nums;
    }