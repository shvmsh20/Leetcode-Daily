bool isSymmetric(int num){
        int digits = 0;
        int temp = num, totalSum = 0;
        while(temp){
            digits++;
            totalSum+=temp%10;
            temp = temp/10;
        }
        if(digits&1){
            return false;
        }
        int n = digits/2;
        int lastX = 0;
        while(n){
            lastX+= num%10;
            num/=10;
            n--;
        }
        return 2*lastX == totalSum;
    }
    int countSymmetricIntegers(int low, int high) {
        int cnt = 0;
        for(int i=low; i<=high; i++){
            if(isSymmetric(i)){
                cnt++;
            }
        }
        return cnt;
    }