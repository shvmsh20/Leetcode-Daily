// T/C: O(nlogn)
static bool cmp(pair<int, int> &a, pair<int, int> &b){
        return a.second>b.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int n = nums.size();
        for(int i=0; i<n; i++){
            mp[nums[i]]++;
        }
        vector<pair<int, int>> v;
        for(auto it: mp){
            v.push_back(it);
        }
        sort(v.begin(), v.end(), cmp);
        vector<int> res;
        for(int i=0; i<k; i++){
            res.push_back(v[i].first);
        }
        return res;
        
    }

// T/C: O(klogn)
    
struct cmp {
        bool operator()(const pair<int, int>  &a, const pair<int, int> &b) {
            return a.second < b.second;
        };
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq(mp.begin(), mp.end());
        vector<int> res;
        while(k--){
            pair<int, int> t = pq.top();
            pq.pop();
            res.push_back(t.first);
        }
        return res;
    }