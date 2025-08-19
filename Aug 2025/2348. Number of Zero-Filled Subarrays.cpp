long long zeroFilledSubarray(vector<int>& nums) {
        long long res=0, count=0;
        vector<int> t;
        for(int x: nums){
            if(x==0){
                count++;
            }else{
                t.push_back(count);
                count=0;
            }
        }
        if(count>0){
            t.push_back(count);
        }
        for(long long x: t){
            res+= (x*(x+1)/2);
        }
        return res;
    }