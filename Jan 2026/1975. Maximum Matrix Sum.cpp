long long maxMatrixSum(vector<vector<int>>& matrix) {
        int mx = INT_MIN, mn = INT_MAX;
        long long cnt = 0, neg = 0, pos = 0;
        bool posFlag = false;
        int n = matrix.size(), m = matrix[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j]<0){
                    cnt++;
                    mx = max(mx, matrix[i][j]);
                    neg += abs(matrix[i][j]);
                }else{
                    mn = min(mn, matrix[i][j]);
                    pos += matrix[i][j];
                    posFlag = true;
                }
            }
        }
        if(cnt%2==0){
            return pos+neg;
        }
        if(posFlag){
            if(abs(mx)>mn){
                return pos+neg-(2*mn);
            }
            
        }
        return pos+neg-(2*abs(mx));
        
    }