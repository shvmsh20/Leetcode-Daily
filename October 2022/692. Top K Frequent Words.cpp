struct cmp{
        bool operator()(pair<string, int> &a, pair<string, int> &b){
            if(a.second!=b.second){
                return a.second<b.second;
            }
            return a.first>b.first;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        for(int i=0; i<words.size(); i++){
            mp[words[i]]++;
        }
        vector<string> res;
        priority_queue<pair<string, int>, vector<pair<string, int>>, cmp> pq(mp.begin(), mp.end());
        while(k--){
            res.push_back(pq.top().first);
            pq.pop();
        }
        return res;
    }