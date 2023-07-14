int longestSubsequence(vector<int>& arr, int diff) {
        int n = arr.size();
        unordered_map<int, int> mp;
        
        for(int i=0; i<n; i++){
            if(mp.find(arr[i]-diff)!=mp.end()){
                mp[arr[i]] = 1+mp[arr[i]-diff];
            }else{
                mp[arr[i]] = 1;
            }
        }
        int ans = 1;
        for(int i=0; i<n; i++){
            ans = max(ans, mp[arr[i]]);
        }
        return ans;
    }