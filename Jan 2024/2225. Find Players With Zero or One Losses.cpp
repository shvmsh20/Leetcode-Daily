vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> won, lost;
        for(auto x: matches){
            won[x[0]]++;
            lost[x[1]]++;
        }
        vector<vector<int>> res(2);
        for(auto x: won){
            if(lost.find(x.first)==lost.end()){
                res[0].push_back(x.first);
            }
        }
        for(auto x: lost){
            if(x.second==1){
                res[1].push_back(x.first);
            }
        }
        sort(res[0].begin(), res[0].end());
        sort(res[1].begin(), res[1].end());
        return res;
    }