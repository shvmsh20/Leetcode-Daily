bool isSquare(int n){
        int x = sqrt(n);
        return n == x*x;
    }
    void dfs(int node, map<int, int>& vis, map<int, int>& mp, int& cnt){
        vis[node] = 1;
        if(vis.find(mp[node]) == vis.end() && mp[node]!=0){
            cnt++;
            // cout<<mp[node]<<" ";
            dfs(mp[node], vis, mp, cnt);
        }
    }
    int longestSquareStreak(vector<int>& nums) {
        map<int, int> mp, mpp;
        for(auto it: nums) mpp[it]++;
        //build the graph->
        for(int i=0; i<nums.size(); i++){
            int n = sqrt(nums[i]);
            if(isSquare(nums[i]) && mpp.find(n)!=mpp.end()){
                mp[n] = nums[i];
            }
        }
        if(mp.size() == 0) return -1;
        int maxi=0;
        //do dfs on the graph
        map<int, int> vis;
        for(auto it: mp){
            int node = it.first;
            if(vis.find(node) == vis.end()){
                int cnt=1;
                // cout<<node<<endl;
                dfs(node, vis, mp, cnt);
                // cout<<endl;
                maxi = max(maxi, cnt);
            }
        }
        return maxi;
    }