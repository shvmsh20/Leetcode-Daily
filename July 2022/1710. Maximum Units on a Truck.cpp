static bool cmp(vector<int> a, vector<int> b){
        return a[1]>b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), cmp);
        int res=0;
        for(int i=0; i<boxTypes.size() && truckSize>0; i++){
            if(truckSize>=boxTypes[i][0]){
                truckSize-=boxTypes[i][0];
                res+= boxTypes[i][0]*boxTypes[i][1];
            }else{
                res+= boxTypes[i][1]*truckSize;
                truckSize=0;
            }
        }
        return res;
    }