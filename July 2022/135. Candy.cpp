int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> left(n, 1);
        vector<int> right(n, 1);
        for(int i=1; i<n; i++){
            if(ratings[i]>ratings[i-1]){
                left[i] = left[i-1]+1;
            }
        }
        int res=0;
        for(int i=n-2; i>=0; i--){
            if(ratings[i]>ratings[i+1]){
                right[i] = right[i+1]+1;
            }
            res+= max(right[i], left[i]);
        }
        res+= max(right[n-1], left[n-1]);
        return res;
    }