int minimumDistance(vector<int>& nums) {
        unordered_map<int, pair<int,int>> mp;
        int mini = INT_MAX;

        for(int i = 0; i < nums.size(); i++) {
            if(mp.find(nums[i]) == mp.end()) {
                mp[nums[i]] = {-1, i};
            } else {
                auto &[prev, last] = mp[nums[i]];
                
                if(prev != -1) {
                    int a = prev, b = last, c = i;
                    int diff = 2 * (c - a);
                    mini = min(mini, diff);
                }
                
                prev = last;
                last = i;
            }
        }

        return mini == INT_MAX ? -1 : mini;
    }