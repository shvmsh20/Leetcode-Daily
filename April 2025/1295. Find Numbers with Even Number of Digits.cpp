bool check(int x){
        int cnt = 0;
        while(x){
            cnt++;
            x/=10;
        }
        return cnt%2==0;
    }
    int findNumbers(vector<int>& nums) {
        int res = 0;
        for(int x: nums){
            if(check(x)){
                res++;
            }
        }
        return res;
    }