int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        int left = 0, right = 1, res = 0;
        while(right<(n+k-1)){
            if(colors[right%n]==colors[(right-1)%n]){
                if((right-left+1)>=k){
                    res+= right-left-k+1;
                }
                left = right;
            }
            right++;
        }
        if((right-left+1)>=k){
            res+= right-left-k+1;
        }
        return res;
    }