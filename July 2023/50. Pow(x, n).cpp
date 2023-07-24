double myPow(double x, int n) {
        double ans=1;
        double xCpy = x;
        int sign;
        bool negMin = false;
        if(n==0){
            return 1;
        }
        if(n<0){
            sign = -1;
            if(n==INT_MIN){
                n = abs(1+n);
                cout << n << endl;
                negMin = true;
            }else{
                n = abs(n);
            }
        }else{
            sign = 1;
        }
        
        while(n>0){
            if(n%2==0){
                n/=2;
                x = x*x;
            }else{
                ans*=x;
                n--;
            }
        }
        if(sign==-1){
            if(negMin){
                return 1/(xCpy*ans);
            }else{
                return 1/ans;
            }
        }else{
            return ans;
        }
        
    }