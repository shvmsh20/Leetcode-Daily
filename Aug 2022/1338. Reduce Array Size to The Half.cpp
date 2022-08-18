struct cmp{
        bool operator()(pair<int, int> &a, pair<int, int> &b){
            return a.second<b.second;
        }
    };
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> mp;
        for(int x: arr){
            mp[x]++;
        }
        int n = arr.size()/2;
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq(mp.begin(), mp.end());
        int count=0;
        while(n>0){
            auto p = pq.top();
            pq.pop();
            int freq = p.second;
            n-=freq;
            count++;
        }
        return count;
        
    }