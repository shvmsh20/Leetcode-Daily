long long countGood(vector<int>& nums, int k) {
        unordered_map <int,int> mpp;
        long long  cnt = 0;
        for (int i = 0, left = 0 ; i < nums.size() ; i++) {
            k -= mpp[nums[i]]++;
            while (k <= 0) k += --mpp[nums[left++]];
            cnt += left;
        }
        return cnt;
    }