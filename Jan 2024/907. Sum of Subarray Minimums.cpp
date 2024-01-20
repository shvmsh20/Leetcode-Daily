int sumSubarrayMins(vector<int>& arr) {
        stack<int> left;
        stack<int> right;
        int n = arr.size();
        int mod = 1e9+7;
        vector<int> leftS(n), rightS(n);
        for(int i=0; i<n; i++){
            while(left.empty()==false && arr[left.top()]>arr[i]){
                left.pop();
            }
            if(left.empty()){
                leftS[i] = -1;
            }else{
                leftS[i] = left.top();
            }
            left.push(i);
        }
        for(int i=n-1; i>=0; i--){
            while(right.empty()==false && arr[right.top()]>=arr[i]){
                right.pop();
            }
            if(right.empty()){
                rightS[i] = n;
            }else{
                rightS[i] = right.top();
            }
            right.push(i);
        }
        // for(int i=0; i<n; i++){
        //     cout << leftS[i] << " ";
        // }
        // cout << endl;
        // for(int i=0; i<n; i++){
        //     cout << rightS[i] << " ";
        // }
        long long res = 0;
        for(int i=0; i<n; i++){
            long long temp = (((rightS[i]-i)%mod)*((i-leftS[i])%mod))%mod; 
            res+= (temp*arr[i])%mod;
        }
        return res%mod;
    }