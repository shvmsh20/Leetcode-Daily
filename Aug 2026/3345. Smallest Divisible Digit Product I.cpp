bool check(int n, int t){
        int product = 1;
        while(n){
            product = product*(n%10);
            n/=10;
        }
        return (product%t)==0;
    }
    int smallestNumber(int n, int t) {
        while(true){
            if(check(n, t)){
                return n;
            }
            n++;
        }
        return -1;
    }