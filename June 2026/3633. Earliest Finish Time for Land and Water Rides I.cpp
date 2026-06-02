nt earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int res = INT_MAX, n = landStartTime.size(), m = waterStartTime.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(waterStartTime[j]>=landStartTime[i]+landDuration[i]){
                    res = min(res, waterStartTime[j]+waterDuration[j]);
                }else{
                    res = min(res, landStartTime[i]+landDuration[i]+waterDuration[j]);
                }
            }
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(landStartTime[j]>=waterStartTime[i]+waterDuration[i]){
                    res = min(res, landStartTime[j]+landDuration[j]);
                }else{
                    res = min(res, waterStartTime[i]+waterDuration[i]+landDuration[j]);
                }
            }
        }
        return res;
    }