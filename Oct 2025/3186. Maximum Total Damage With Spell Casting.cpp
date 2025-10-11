long long maximumTotalDamage(vector<int>& power) {
        int n = power.size();
        unordered_map<int, long long> mp;
        for(int i=0; i<n; i++){
            mp[power[i]]++;
        }
        vector<long long> arr;
        for(auto it = mp.begin(); it!=mp.end(); it++){
            arr.push_back(it->first);
        }
        sort(arr.begin(), arr.end());
        int m = arr.size();
        vector<long long> dp(m);
        dp[0] = arr[0]*mp[arr[0]];
        for(int i=1; i<m; i++){
            long long totalCurrDamage = arr[i]*mp[arr[i]];
            dp[i] = dp[i-1];
            int prevIndex = i-1;
            while(prevIndex>=0 && (arr[prevIndex]+1==arr[i] || arr[prevIndex]+2==arr[i])){
                prevIndex--;
            }
            if(prevIndex>=0){
                dp[i] = max(dp[i], totalCurrDamage+dp[prevIndex]);
            }else{
                dp[i] = max(dp[i], totalCurrDamage);
            }
        }
        return dp[m-1];
    }