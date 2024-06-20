bool isPoss(int x, vector<int> &arr, int n, int m){
        int cnt = 1;
        int prev = 0;
        for(int i=1; i<n && cnt<m; i++){
            if(arr[i]-arr[prev]>=x){
                cnt++;
                prev = i;
            }
        }
        if(cnt==m){
            return true;
        }
        return false;
    }
    int maxDistance(vector<int>& arr, int m) {
        int n = arr.size(), res = 1;
        sort(arr.begin(), arr.end());
        int end = arr[n-1]-arr[0], st = 1;
        while(st<=end){
            int mid = st+(end-st)/2;
            if(isPoss(mid, arr, n, m)){
                res = mid;
                st = mid+1;
            }else{
                end = mid-1;
            }
        }
        return res;
    }