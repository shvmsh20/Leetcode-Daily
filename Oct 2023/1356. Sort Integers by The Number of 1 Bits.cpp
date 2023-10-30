int noSet(int n){
        int count=0;
        while(n){
            n = n&(n-1);
            count++;
        }
        return count;
    }
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int, int>> res;
        int n = arr.size();
        for(int i=0; i<n; i++){
            res.push_back({noSet(arr[i]), arr[i]});
        }
        sort(res.begin(), res.end());
        vector<int> ans;
        for(int i=0; i<n; i++)
            ans.push_back(res[i].second);
        return ans;
    }