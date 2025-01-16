int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int res = 0, n = nums1.size(), m = nums2.size();
        if(m%2){
            for(int i=0; i<n; i++){
                res = res ^ nums1[i];
            }
        }
        if(n%2){
            for(int i=0; i<m; i++){
                res = res ^ nums2[i];
            }
        }
        return res;
    }