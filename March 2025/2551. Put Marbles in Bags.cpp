long long putMarbles(vector<int>& weights, int k) {
        if(k==1){
            return 0;
        }
        priority_queue<int> mn;
        priority_queue<int, vector<int>, greater<int>> mx;
        k--;
        int n = weights.size();
        for(int i=0; i<n-1; i++){
            int x = weights[i]+weights[i+1];
            if(mn.size()<k){
                mn.push(x);
            }else if(mn.top()>x){
                mn.pop();
                mn.push(x);
            }
            if(mx.size()<k){
                mx.push(x);
            }else if(mx.top()<x){
                mx.pop();
                mx.push(x);
            }
        }
        long long mxSum = 0, mnSum = 0;
        while(mx.size()){
            mxSum+= mx.top();
            mx.pop();
            mnSum+= mn.top();
            mn.pop();
        }
        return mxSum-mnSum;
    }