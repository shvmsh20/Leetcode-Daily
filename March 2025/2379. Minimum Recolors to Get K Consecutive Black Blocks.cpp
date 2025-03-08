int minimumRecolors(string blocks, int k) {
        int curr = 0, n = blocks.size();
        for(int i=0; i<k; i++){
            if(blocks[i]=='W'){
                curr++;
            }
        }
        int res = curr;
        for(int i=k; i<n; i++){
            if(blocks[i-k]=='W'){
                curr--;
            }
            if(blocks[i]=='W'){
                curr++;
            }
            res = min(res, curr);
        }
        return res;
    }