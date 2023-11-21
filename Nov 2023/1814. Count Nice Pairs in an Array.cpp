int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        vector<int>rev(n);
        int ans=0;
        for(int i=0;i<n;i++){
            int val=nums[i];
            int newval=0,flg=0,p=0;
            while(val){
                if(val%10==0 and flg==1){
                    newval = (newval*10) + val%10;
                }else if(val%10!=0){
                    flg=1;
                    newval = (newval*10) + val%10;
                }
                p++;
                val/=10;
            }
            rev[i]=newval;
        }
        unordered_map<int,int>m;
        for(int i=0;i<n;i++){
            int val =nums[i]-rev[i];
            if(m.find(val)!=m.end()){
                ans = (ans+m[val])%MOD;
            }
            m[val]++;
        }
        return ans;
    }