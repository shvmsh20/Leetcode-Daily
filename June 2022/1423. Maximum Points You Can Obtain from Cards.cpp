int maxScore(vector<int>& cardPoints, int k) {
        int sum = 0,mx, n= cardPoints.size();
        for(int i=n-k; i<n; i++)
            sum += cardPoints[i];
        mx = sum;
        for(int i=0; i<k; i++){
            sum -= cardPoints[n-k+i];
            sum += cardPoints[i];
            mx = max(sum, mx);
        }
        return mx;
    }