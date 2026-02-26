int numSteps(string s) {
        int res = 0, n = s.size(), carry = 0;
        for(int i=n-1; i>0; i--){
            int binarySum = ((s[i]-'0')+carry)%2;
            if(binarySum==0){
                res++;
            }else{
                res+=2;
                carry = 1;
            }
        }
        return res+carry;
    }