bool find132pattern(vector<int>& nums) {
        stack<int> st;
        int thirdElement = INT_MIN, n = nums.size();
        for(int i=n-1; i>=0; i--){
            if(thirdElement>nums[i]){
                return true;
            }
            while(!st.empty() && st.top() < nums[i]){
                thirdElement = st.top();
                st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }