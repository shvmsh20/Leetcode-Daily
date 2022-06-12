int maximumUniqueSubarray(vector<int>& nums) {
        int i = 0 ; 
        int j = 0 ; 
        
        unordered_map <int , int> umap ; 
        int ans = INT_MIN ; 
        int sum = 0 ; 
        
        while (j < nums.size()) {
            
            umap[nums[j]]++ ; 
            sum += nums[j] ;
            
            if(umap.size() <  (j-i+1)) {
                while(umap.size() <  (j-i+1)) {
                    umap[nums[i]]-- ; 
                    if(umap[nums[i]] == 0) umap.erase(nums[i]) ; 
                    sum -= nums[i] ; 
                    i++ ; 
                }
            }
            
            ans = max (ans , sum) ; 
            j++ ;  
            
            
        }
        
        return ans ; 
    }