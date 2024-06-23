int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size(), res = 1;
        multiset<int> mset;
        int st = 0, end = 0;
        while(end<n){
            mset.insert(nums[end]);
            auto last = mset.end();
            last--;
            auto first = mset.begin();
            int p1 = *last;
            int p2 = *first;
            while(mset.size()>=2 && (p1-p2)>limit){
                mset.erase(mset.find(nums[st]));
                last = mset.end();
                last--;
                first = mset.begin();
                p1 = *last;
                p2 = *first;
                st++;
            }
            // cout << st << " " << end << " " << p1 << " " << p2 << endl;
            res = max(res, end-st+1);
            end++;
        }
        return res;
    }