bool isPoss(vector<long long> &nums, long long n, long long val){
       long long sum=0;
      for(int i=0; i<n; i++){
          sum+=nums[i];
          if(sum>((i+1)*val)){
              return false;
          }
      }

        return true;
    }
    int minimizeArrayValue(vector<int>& temp) {
        long long lo=0, hi=1e9, n=temp.size();
        vector<long long> nums(temp.begin(), temp.end());
        int res=-1;
        while(lo<=hi){
            long long mid = lo+(hi-lo)/2;
            //cout << mid << " ";
            if(isPoss(nums, n, mid)){
                res = mid;
                hi = mid-1;
            }else{
                lo = mid+1;
            }
        }
        return res;
    }