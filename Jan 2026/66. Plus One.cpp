vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        while(n-1>=0 && digits[n-1]==9){
            digits[n-1] = 0;
            n--;
        }
        if(n-1>=0){
            digits[n-1]++;
        }else{
            digits[0] = 1;
            digits.push_back(0);
        }
        return digits;
    }