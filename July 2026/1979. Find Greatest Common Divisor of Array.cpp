int gcd(int a, int b){
        if(a==0){
            return b;
        }
        return gcd(b%a, a);
    }
    int findGCD(vector<int>& nums) {
        int mx = INT_MIN, mn = INT_MAX;
        for(int i=0; i<nums.size(); i++){
            mx = max(nums[i], mx);
            mn = min(nums[i], mn);
        }
        return gcd(mn, mx);
    }