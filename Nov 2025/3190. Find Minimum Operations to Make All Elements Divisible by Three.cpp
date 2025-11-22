int minimumOperations(vector<int>& nums) {
        int res = 0;
        for(int x: nums){
            int rem = x%3;
            if(rem==1 || rem==2){
                // cout << x << " ";
                res++;
            }
        }
        return res;
    }