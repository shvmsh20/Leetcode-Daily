bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        int odd = 0;
        for(int i=0; i<n; i++){
            if(nums1[i]%2!=0){
                odd++;
            }
            if(odd>=2){
                break;
            }
        }
        // check for even
        bool ansPoss = true;
        for(int i=0; i<n; i++){
            if(nums1[i]%2!=0 && odd==1){
                ansPoss = false;
                break;
            }
        }
        if(ansPoss){
            return true;
        }
        // check for odd
        ansPoss = true;
        for(int i=0; i<n; i++){
            if(nums1[i]%2==0 && odd==0){
                ansPoss = false;
                break;
            }
        }
        return ansPoss;
    }