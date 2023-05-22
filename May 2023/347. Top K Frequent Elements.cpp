static bool cmp(pair<int, int> &a, pair<int, int> &b){
        return a.second>b.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int n = nums.size();
        for(int i=0; i<n; i++){
            mp[nums[i]]++;
        }
        vector<pair<int, int>> arr;
        for(auto x: mp){
            arr.push_back({x.first, x.second});
        }
        sort(arr.begin(), arr.end(), cmp);
        vector<int> res;
        for(int i=0; i<arr.size() && i<k; i++){
            res.push_back(arr[i].first);
        }
        return res;
    }