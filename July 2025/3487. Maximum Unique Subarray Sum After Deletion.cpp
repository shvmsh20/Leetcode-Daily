int maxSum(vector<int>& nums) {
        unordered_set<int> s;
        int res = 0;
        int mx = INT_MIN;
        for(int x: nums){
            mx = max(mx, x);
            if(x>0 && s.find(x)==s.end()){
                s.insert(x);
                res+=x;
            }
        }
        return res==0?mx:res;
    }