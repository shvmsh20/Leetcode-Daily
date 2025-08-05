int numOfUnplacedFruits(vector<int>& f, vector<int>& b) {
        int n = f.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(b[j]!=-1 && b[j]>=f[i]){
                    b[j] = -1;
                    break;
                }
            }
        }
        int res = 0;
        for(int i=0; i<n; i++){
            if(b[i]!=-1){
                res++;
            }
        }
        return res;
    }