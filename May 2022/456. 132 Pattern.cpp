bool find132pattern(vector<int>& nums) {
        stack<pair<int, int>> st;
        int n = nums.size();
        int currMin = nums[0];
        st.push({nums[0], INT_MAX});
        for(int i=1; i<n; i++){
            while(!st.empty() && st.top().first<=nums[i]){
                st.pop();
            }
            if(!st.empty() && nums[i]>st.top().second){
                return true;
            }
            st.push({nums[i], currMin});
            currMin = min(currMin, nums[i]);
        }
        return false;
    }