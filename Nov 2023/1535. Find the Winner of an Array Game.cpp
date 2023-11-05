int getWinner(vector<int>& arr, int k) {
        int mx = INT_MIN;
        int n = arr.size();
        for(int i=0; i<n; i++){
            mx = max(mx, arr[i]);
        }
        if(k>=n){
            return mx;
        }
        
        int currCnt = 0, currIndex = 0, nextIndex = 1;
        while(currCnt!=k && nextIndex<n){
            if(arr[currIndex]>arr[nextIndex]){
                currCnt++;
                nextIndex++;
            }else{
                currIndex = nextIndex;
                nextIndex++;
                currCnt = 1;
            }
        }
        
        return arr[currIndex];
       
    }