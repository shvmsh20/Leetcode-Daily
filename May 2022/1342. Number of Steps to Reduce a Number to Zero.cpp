int numberOfSteps(int n) {
        if(n==0){
            return 0;
        }
        else if(n==1){
            return 1;
        }else{
            int count=0;
            while(n!=0){
                count++;
                if(n&1){
                    n = n&(n-1);
                }else{
                    n = n>>1;
                }
            }
            return count;
        }
    }