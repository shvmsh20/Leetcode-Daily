int numOfSubarrays(vector<int>& arr) {
        int sum=0;
        int ans=0;
         int e=1;
         int o=0;
        for(auto it:arr){
          sum+=it;
          if(sum%2){
            o++;
            ans+=e;
          }else{
            e++;
            ans+=o;
          }
         ans=ans%1000000007;
        }

        return ans;
    }