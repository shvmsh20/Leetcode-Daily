long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long res=0, st=0, mn=-1, mx=-1;
        bool fMin=false, fMax=false;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]<minK || nums[i]>maxK){
                fMin = false;
                fMax = false;
                st = i+1;
            }
            if(nums[i]==minK){
                fMin = true;
                mn=i;
            }
            if(nums[i]==maxK){
                fMax = true;
                mx=i;
            }
            if(fMin && fMax){
                res+= (min(mn, mx)-st+1);
            }
        }
        return res;
    }