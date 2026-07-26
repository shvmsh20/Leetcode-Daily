int maximumProduct(vector<int>& nums) {
         int a=nums[0], b=nums[1], c=nums[2];
        // 3-element sort 
        auto [x2, x0]=ranges::minmax({a, b, c});
        int x1=(a+b+c)-x0-x2;
        int m0=x2, m1=x1;

        const int n=nums.size();
        for (int i=3; i<n; i++) {
            const int x=nums[i];
            if (x>=x0) x2=x1,x1=exchange(x0, x);
            else if (x>=x1) x2=exchange(x1, x);
            else if (x>=x2) x2=x;
            // Track 2 smallest 
            if (x<=m0) m1=exchange(m0, x);
            else if (x<=m1) m1=x;
        }
        return max(x0*x1*x2, x0*m0*m1);
    }