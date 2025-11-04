static bool cmp(pair<int, int> &a, pair<int, int> &b){
        if(a.second!=b.second) return a.second>b.second;
        return a.first>b.first;
    }
    int solve(unordered_map<int, int> &mp, int x){
        vector<pair<int, int>> tmp;
        for(auto it: mp){
            tmp.push_back({it.first, it.second});
        }
        int res = 0;
        sort(tmp.begin(), tmp.end(), cmp);
        for(int i=0; i<tmp.size()&&i<x; i++){
            res+= tmp[i].first*tmp[i].second;
        }
        return res;
    }
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> res;
        unordered_map<int, int> mp;
        for(int i=0; i<k-1; i++){
            mp[nums[i]]++;
        }

        for(int i=k-1; i<nums.size(); i++){
            mp[nums[i]]++;
            res.push_back(solve(mp, x));
            mp[nums[i-k+1]]--;
        }
        return res;
    }