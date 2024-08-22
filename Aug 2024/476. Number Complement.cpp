int findComplement(int num) {
        bool flag = false;
        for(int i=30; i>=0; i--){
            if(num & 1<<i){
                if(!flag){
                    flag = true;
                }
                num = num & (~((~num | (1<<i))));
                continue;
            }
            if(flag){
                num = num | (1<<i);
            }
        }
        return num;
    }