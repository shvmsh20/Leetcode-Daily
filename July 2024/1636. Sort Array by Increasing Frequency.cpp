static bool cmp(pair<int, int> &p1, pair<int, int> &p2){
        if(p1.second!=p2.second){
            return p1.second<p2.second;
        }
        return p1.first>p2.first;
    }
    vector<int> frequencySort(vector<int>& nums) {
        vector<pair<int, int>> res;
        unordered_map<int, int> mp;
        for(int x: nums){
            mp[x]++;
        }
        for(auto x: mp){
            res.push_back(x);
        }
        sort(res.begin(), res.end(), cmp);
        vector<int> ans;
        for(pair<int, int> p: res){
            int freq = p.second;
            while(freq--){
                ans.push_back(p.first);
            }
        }
        return ans;
    }