int findDigitSum(int x){
        int sum = 0;
        while(x){
            sum+= x%10;
            x/=10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
       unordered_map<int, int> mp;
       int res = -1;
       for(int x: nums){
        int digitSum = findDigitSum(x);
        if(mp.find(digitSum)!=mp.end()){
            res = max(res, mp[digitSum]+x);
            if(x>mp[digitSum]){
                mp[digitSum] = x;
            }
        }else{
            mp[digitSum] = x;
        }
       }
       return res;
    }