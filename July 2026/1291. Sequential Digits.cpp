int generateNext(int x){
        int lstD = x%10;
        if(lstD==9){
            return -1;
        }
        return ((x*10)+(lstD+1));
    }
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;
        for(int firstD=1; firstD<=9; firstD++){
            int num = firstD;
            while(num<=high){
                if(num>=low){
                    res.push_back(num);
                }
                num = generateNext(num);
                if(num==-1){
                    break;
                }
            }
        }
        sort(res.begin(), res.end());
        return res;
    }