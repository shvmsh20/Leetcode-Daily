double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> prevFlowed = {(double)poured};
        for(int i=1; i<=query_row; i++){
            vector<double> currFlowed(i+1, 0);
            for(int j=0; j<i; j++){
                double extraChampagne = prevFlowed[j]-1;
                if(extraChampagne>0){
                    currFlowed[j]+= extraChampagne/2;
                    currFlowed[j+1]+= extraChampagne/2;
                }
            }
            prevFlowed = currFlowed;
        }
        return prevFlowed[query_glass]>1?1:prevFlowed[query_glass];
    }