int trap(vector<int>& height) {
        int i=0, j=height.size()-1;
        int maxLeft = height[i], maxRight = height[j], res=0;
        while(i<=j){
            if(maxLeft<=maxRight){
                if(height[i]>maxLeft){
                    maxLeft = height[i];
                }else{
                    res+= maxLeft - height[i];
                }
                i++;
            }else{
                if(height[j]>maxRight){
                    maxRight = height[j];
                }else{
                    res+= maxRight - height[j];
                }
                j--;
            }
        }
        return res;
    }