int findSumOfDigits(int n){
        int sum = 0;
        while(n){
            sum+= n%10;
            n/=10;
        }
        return sum;
    }
    int countLargestGroup(int n) {
        unordered_map<int, int> mp; 
        int mx = 0, res = 0;
        for(int i=1; i<=n; i++){
            int sumOfDigits = findSumOfDigits(i);
            mp[sumOfDigits]++;
            if(mp[sumOfDigits]>mx){
                mx = mp[sumOfDigits];
            }
        }
        for(auto it: mp){
            if(it.second==mx){
                res++;
            }
        }
        return res;
    }