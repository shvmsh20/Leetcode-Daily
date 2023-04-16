int MOD = 1e9+7;
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        long long int maxLen = INT_MIN, maxHei = INT_MIN;
        long long int prev = 0, n1 = horizontalCuts.size(), n2 = verticalCuts.size();
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        for(int i=0; i<n1; i++){
            maxHei = max(maxHei, horizontalCuts[i]-prev);
            prev = horizontalCuts[i];
        }
        maxHei = max(maxHei, h-prev);
        prev = 0;
        for(int i=0; i<n2; i++){
            maxLen = max(maxLen, verticalCuts[i]-prev);
            prev = verticalCuts[i];
        }
        maxLen = max(maxLen, w-prev);
        long long int ans = (maxLen*maxHei)%MOD;
        return ans;
        
    }