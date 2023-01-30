int tribonacci(int n) {
        if(n<=1) return n;
        if(n==2) return 1;
        int c1=0, c2=1, c3=1;
        for(int i=3; i<=n; i++){
            int temp = c1+c2+c3;
            c1 = c2;
            c2 = c3;
            c3 = temp;
        }
        return c3;
    }