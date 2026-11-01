 int minMoves(vector<int>& nums) {
        int mn = INT_MAX;
        for(int x: nums){
            mn = min(mn, x);
        }
        int ans=0;
        for(int x: nums){
            ans+= x-mn;
        }
        return ans;
    }