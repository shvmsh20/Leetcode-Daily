vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int, int>> pq;
        int n = arr.size();
        for(int i=0; i<k; i++){
            pq.push({abs(x-arr[i]), arr[i]});
        }
        for(int i=k; i<n; i++){
            int val = abs(x-arr[i]);
            if(pq.top().first>val){
                pq.pop();
                pq.push({val, arr[i]});
            }
        }
        vector<int> res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        sort(res.begin(), res.end());
        return res;
    }