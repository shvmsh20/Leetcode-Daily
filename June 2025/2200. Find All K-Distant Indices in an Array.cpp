ector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        vector<int> res;
        for(int i=0; i<n; i++){
            int currIndex = i;
            int K = k+1;
            bool flag = false;
            while(K && currIndex>=0){
                if(nums[currIndex]==key){
                    flag = true;
                    res.push_back(i);
                    break;
                }else{
                    K--;
                    currIndex--;
                }
            }
            K = k+1;
            currIndex = i;
            while(flag==false && K && currIndex<n){
                if(nums[currIndex]==key){
                    flag = true;
                    res.push_back(i);
                    break;
                }else{
                    K--;
                    currIndex++;
                }
            }
        }
        return res;
    }