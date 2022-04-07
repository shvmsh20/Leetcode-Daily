int threeSumMulti(vector<int>& arr, int target) {
        int mod = 1e9+7, i, j;
        int n = arr.size();
        int res=0;
        sort(arr.begin(), arr.end());
        for(int k=0; k<=n-3; k++){
            i=k+1;
            j=n-1;
            while(i<j){
                if(arr[k]+arr[i]+arr[j]==target){
                    int count1=1;
                    int count2=1;
                    while(i<j && arr[i]==arr[i+1]){
                        count1++;
                        i++;
                    }
                    while(i<j && arr[j]==arr[j-1]){
                        count2++;
                        j--;
                    }
                    if(i==j){
                        res = (res + (count1 * (count1-1)/2)%mod)%mod;
                    }else{
                        res = (res + (count1*count2)%mod)%mod;
                    }
                    i++;
                    j--;
                }else{
                    if(arr[k]+arr[i]+arr[j]<target){
                        i++;
                    }else{
                        j--;
                    }
                }
            }
            
        }
        return res;
    }