int maxArea(vector<int>& height) {
        int i=0, j=height.size()-1;
        int ans=INT_MIN, temp;
        while(i<j){
            if(height[i]<=height[j]){
                temp = height[i]*(j-i);
                ans = max(ans, temp);
                i++;
            }else{
                temp = height[j]*(j-i);
                ans = max(ans, temp);
                j--;
            }
        }
        return ans;
    }