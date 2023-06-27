vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
       
        int n = nums1.size(), m = nums2.size();
        set<pair<int, int>> mp;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({nums1[0]+nums2[0], 0, 0});
        vector<vector<int>> res;
        while(res.size()<k && !pq.empty()){
            vector<int> tmp = pq.top();
            pq.pop();
           
            pair<int, int> p = make_pair(tmp[1], tmp[2]);
            if(mp.find(p)==mp.end()){
                mp.insert(p);
                res.push_back({nums1[tmp[1]], nums2[tmp[2]]});
                if(tmp[1]+1<n){
                    pq.push({nums1[tmp[1]+1]+nums2[tmp[2]], tmp[1]+1, tmp[2]});
                }
                if(tmp[2]+1<m){
                    pq.push({nums1[tmp[1]]+nums2[tmp[2]+1], tmp[1], tmp[2]+1});
                }
            }
    
        }
        return res;
    }