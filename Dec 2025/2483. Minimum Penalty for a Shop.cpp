int bestClosingTime(string customers) {
        int n = customers.size();
        vector<int> left(n+1), right(n+1);
        int cnt = 0;
        for(int i=0; i<n; i++){
            left[i] = cnt;
            if(customers[i]=='N'){
                cnt++;
            }
        }
        left[n] = cnt;
        cnt = 0;
        for(int i=n-1; i>=0; i--){
            right[i] = cnt;
            if(customers[i]=='Y'){
                cnt++;
            }
        }
        int mn = INT_MAX, res = 0;
        for(int i=0; i<n; i++){
            int ans = left[i]+right[i];
            if(customers[i]=='Y'){
                ans++;
            }
            if(ans<mn){
                res = i;
                mn = ans;
            }
        }
        if(left[n]<mn){
            res = n;
        }
        return res;
    }