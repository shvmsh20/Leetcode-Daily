int bitwiseComplement(int n) {
        if(n==0) return 1;
        string binaryRep;
        bool flag = false;
        for(int i=31; i>=0; i--){
            if(n & (1<<i)){
                flag = true;
                binaryRep.push_back('1');
            }else{
                if(flag){
                    binaryRep.push_back('0');
                }
            }
        }
        int m = binaryRep.size();
        for(int i=0; i<m; i++){
            if(binaryRep[i]=='0'){
                binaryRep[i] = '1';
            }else{
                binaryRep[i] = '0';
            }
        }
        int res = 0;
        for(int i=m-1; i>=0; i--){
           
            if(binaryRep[i]=='1'){
                res =  res | (1<<(m-1-i));
            }
        }
        
        return res;
    }