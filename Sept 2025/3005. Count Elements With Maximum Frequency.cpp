int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> mp;
        int mxFreq = INT_MIN;
        for(int x: nums){
            mp[x]++;
            mxFreq = max(mxFreq, mp[x]);
        }
        int res = 0;
        for(pair<int, int> x: mp){
            if(mxFreq==x.second){
                res+= mxFreq;
            }
        }
        return res;
    }