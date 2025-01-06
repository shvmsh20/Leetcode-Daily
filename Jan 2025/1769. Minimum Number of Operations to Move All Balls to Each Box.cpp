vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> res;
        for(int i=0; i<n; i++){
            int ans = 0;
            for(int left = 0; left<i; left++){
                ans += (boxes[left]=='1' ? (i-left) : 0);
            }
            for(int right = n-1; right>i; right--){
                ans+= (boxes[right]=='1' ? (right-i) : 0);
            }
            res.push_back(ans);
        }
        return res;
    }