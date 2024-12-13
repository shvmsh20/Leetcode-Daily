struct cmp{
        bool operator()(pair<int, int> &p1, pair<int, int> &p2){
            if(p1.first!=p2.first){
                return p1.first>p2.first;
            }else{
                return p1.second>p2.second;
            }
        }
    };
    long long findScore(vector<int>& nums) {
        long long res = 0;
        unordered_set<int> s;
        int n = nums.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
        for(int i=0; i<n; i++){
            pq.push({nums[i], i});
        }
        while(!pq.empty()){
            pair<int, int> p = pq.top();
            pq.pop();
            int val = p.first, index = p.second;
            if(s.find(index)!=s.end()){
                continue;
            }
            res+= val;
            s.insert(index);
            if(index+1<n){
                s.insert(index+1);
            }
            if(index-1>=0){
                s.insert(index-1);
            }
        }
        return res;
    }