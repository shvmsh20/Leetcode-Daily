vector<int> arrayRankTransform(vector<int>& arr) {
        unordered_map<int, int> mp;
        set<int> s(arr.begin(), arr.end());
        int rank = 1;
        for(int x: s){
            mp[x] = rank;
            rank++;
        }
        vector<int> res;
        for(int x: arr){
            res.push_back(mp[x]);
        }
        return res;
    }