int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> s;
        for(int i=0; i<nums.size(); i++){
            s.insert(nums[i]);
        }
        
        int x = s.size();
        int res = 0, n = nums.size();
        for(int i=0; i<n; i++){
            unordered_set<int> tmp;
            for(int j=i; j<n; j++){
                tmp.insert(nums[j]);
                if(tmp.size()==x){
                    res+= n - j;
                    break;
                }
            }
        }
        return res;
    }