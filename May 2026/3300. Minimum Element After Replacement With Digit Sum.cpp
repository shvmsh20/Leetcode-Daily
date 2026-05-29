int findDigitSum(int x){
        int res = 0;
        while(x){
            res+= x%10;
            x/=10;
        }
        return res;
    }
    int minElement(vector<int>& nums) {
        int res = INT_MAX;
        for(int x: nums){
            res = min(res, findDigitSum(x));
        }
        return res;
    }