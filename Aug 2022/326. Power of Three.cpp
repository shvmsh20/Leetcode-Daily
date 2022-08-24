bool isPowerOfThree(int n) {
        
        if(n ==1 || n==3){
            return true;
        }
        if(n<3){
            return false;
        }
        else if(n%3!=0){
            return false;
        }
        return isPowerOfThree(n/3);
    }