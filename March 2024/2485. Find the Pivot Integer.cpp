int pivotInteger(int n) {
        int totalSum = n*(n+1)/2, currSum = 0;
        for(int i=1; i<=n; i++){
            currSum+= i;
            if(totalSum==currSum){
                return i;
            }
            totalSum-=i;
        }
        return -1;
    }