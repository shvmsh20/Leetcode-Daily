vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i = 0, j = 0, n = nums1.size(), m = nums2.size();
        vector<int> res;
        while(i<n && j<m){
            while(i>0 && i<n && nums1[i]==nums1[i-1]){
                i++;
            }
            while(j>0 && j<m && nums2[j]==nums2[j-1]){
                j++;
            }
            if(i==n || j==m){
                break;
            }
            if(nums1[i]==nums2[j]){
                res.push_back(nums1[i]);
                i++;
                j++;
            }else if(nums1[i]<nums2[j]){
                i++;
            }else{
                j++;
            }
        }
        return res;
    }