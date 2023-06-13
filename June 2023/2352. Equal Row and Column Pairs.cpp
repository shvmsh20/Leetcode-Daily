int equalPairs(vector<vector<int>>& grid) {
        int cnt = 0, n = grid.size();
        unordered_map<string, int> mp;
        for(int i=0; i<n; i++){
            string tmp;
            for(int j=0; j<n; j++){
                tmp+= (to_string(grid[i][j])+'#');
            }
            mp[tmp]++;
        }
        for(int j=0; j<n; j++){
            string tmp;
            for(int i=0; i<n; i++){
                tmp+= (to_string(grid[i][j])+'#');
            }
            if(mp.find(tmp)!=mp.end()){
                cnt+= mp[tmp];
            }
        }
        return cnt;
    }