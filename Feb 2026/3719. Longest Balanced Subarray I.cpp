int longestBalanced(vector<int>& nums) {
      int n = nums.size(), res = 0;
      for(int i=0; i<n; i++){
        unordered_map<int, int> evenCnt, oddCnt;
        for(int j=i; j<n; j++){
            if(nums[j]%2){
                evenCnt[nums[j]]++;
            }else{
                oddCnt[nums[j]]++;
            }
            if(evenCnt.size()==oddCnt.size()){
                res = max(res, j-i+1);
            }
        }
      }
      return res;  
    }