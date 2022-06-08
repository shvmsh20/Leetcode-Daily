void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0, j;
        if(n==0) return;
        if(m==0){
            nums1 = nums2;
            return;
        }
        while(i<m){
            if(nums2[0]<nums1[i]){
                swap(nums1[i], nums2[0]);
                int temp = nums2[0];
                // place nums2[0] in its correct position
                for(j=1; j<n && nums2[j]<temp; j++){
                    nums2[j-1] = nums2[j];
                }
                nums2[j-1] = temp;  
            }
            i++;
        }
        for(int i=0; i<n;i++){
            nums1[i+m] = nums2[i];
        }
    }