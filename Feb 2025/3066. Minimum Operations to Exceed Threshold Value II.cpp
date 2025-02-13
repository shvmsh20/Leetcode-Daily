int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        int res = 0;
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for(int i=0; i<n; i++){
            pq.push(nums[i]);
        }
        while(pq.size()>=2){
            long long x = pq.top();
            if(x>=k){
                break;
            }
            pq.pop();
            long long y = pq.top();
            pq.pop();
            // cout << x << " " << y << endl;
            
            res++;
           
            long long newNum = (min(x, y)*2) + max(x, y);
            // cout << newNum << endl;
            pq.push(newNum);
        }
        return res;
    }