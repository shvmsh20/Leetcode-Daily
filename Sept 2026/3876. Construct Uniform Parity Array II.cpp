bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        int mnOdd = INT_MAX;
        for(int i=0; i<n; i++){
            if(nums1[i]%2!=0){
                mnOdd = min(mnOdd, nums1[i]);
            }
        }
        // check for even
        bool ansPoss = true;
        for(int i=0; i<n; i++){
            if(nums1[i]%2!=0 && nums1[i]-mnOdd<1){
                ansPoss = false;
                break;
            }
        }
        if(ansPoss) return ansPoss;
        // check for odd
        ansPoss = true;
        for(int i=0; i<n; i++){
            if(nums1[i]%2==0 && nums1[i]-mnOdd<1){
                ansPoss = false;
                break;
            }
        }
        return ansPoss;
    }