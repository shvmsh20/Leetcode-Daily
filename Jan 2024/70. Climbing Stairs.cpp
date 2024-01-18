int climbStairs(int n) {
        int a = 1;
        int b = 1;
        for(int i=2; i<=n; i++){
            int t = a+b;
            a = b;
            b = t;
        }
        return b;
    }