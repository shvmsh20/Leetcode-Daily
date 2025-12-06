int countPartitions(vector<int>& nums, int k) {
          const int mod = 1e9 + 7;
        int n = (int)nums.size();
        
        int P[n + 1];
        multiset<int> S;
        for(int r = 1, l = 1; r <= n; r ++){
            S.insert(nums[r - 1]);
            while(*prev(S.end()) - *S.begin() > k){
                S.erase(S.find(nums[l - 1]));
                l += 1;
            }
            P[r] = l;
            //current window [l, r]
        }

        int dp[n + 1];
        dp[0] = 1;
        for(int r = 1; r <= n; r ++){
            dp[r] = 0;
            int max_el = nums[r - 1];
            int min_el = nums[r - 1];
            for(int l = r; l >= P[r]; l --){
                max_el = max(max_el, nums[l - 1]);
                min_el = min(min_el, nums[l - 1]);
                if(max_el - min_el <= k){
                    dp[r] += dp[l - 1];
                    dp[r] %= mod;
                }
            }
        }
        return dp[n];
    }