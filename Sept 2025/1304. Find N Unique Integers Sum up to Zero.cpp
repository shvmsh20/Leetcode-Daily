vector<int> sumZero(int n) {
        vector<int> res;
        int curr = 1;
        while(n){
            if(n==1){
                res.push_back(0);
                break;
            }else{
                res.push_back(curr);
                res.push_back(curr*-1);
                curr++;
            }
            n-=2;
        }
        return res;
    }