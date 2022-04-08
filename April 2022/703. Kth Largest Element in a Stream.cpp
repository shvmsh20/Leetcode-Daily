class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int K;
    KthLargest(int k, vector<int>& nums) {
        int n = nums.size(), i;
        for(i=0; i<n && i<k; i++){
            pq.push(nums[i]);
        }
        while(i<n){
            if(nums[i]>pq.top()){
                pq.pop();
                pq.push(nums[i]);
            }
            i++;
        }
        K=k;
    }
    
    int add(int val) {
        if(pq.size()<K){
            pq.push(val);
        }
        else if(val>pq.top()){
            pq.pop();
            pq.push(val);
        }
        return pq.top();
    }
};