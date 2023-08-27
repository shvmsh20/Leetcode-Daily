bool solve(int currPos, int k, int lastPos, unordered_set<int> &s, unordered_map<string, bool> &dp){
        if(currPos==lastPos){
            return true;
        }
        if(currPos>lastPos){
            return false;
        }
        string key = to_string(currPos)+'#'+to_string(k);
        if(dp.find(key)!=dp.end()){
            return dp[key];
        }
        bool res = false;
        if(s.find(currPos+k)!=s.end()){
            res = solve(currPos+k, k, lastPos, s, dp);
        }
        if(res){
            return dp[key] = res;
        }
        if(k-1!=0 && s.find(currPos+k-1)!=s.end()){
            res = solve(currPos+k-1, k-1, lastPos, s, dp);
        }
        if(res){
            return dp[key] = res;
        }
        if(s.find(currPos+k+1)!=s.end()){
            res = solve(currPos+k+1, k+1, lastPos, s, dp);
        }
        return dp[key] = res;
    }
    bool canCross(vector<int>& stones) {
        unordered_set<int> s;
        for(int x: stones){
            s.insert(x);
        }
        if(stones[0]+1!=stones[1]){
            return false;
        }
        int n = stones.size();
        int lastStone = stones[n-1];
        unordered_map<string, bool> dp;
        return solve(stones[1], 1, lastStone, s, dp);
    }