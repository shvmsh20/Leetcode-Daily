bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int lo = 0, hi = n-1;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(matrix[mid][m-1]<target){
                lo = mid+1;
            }else if(matrix[mid][0]>target){
                hi = mid-1;
            }else{
                break;
            }
        }
        if(lo>hi){
            return false;
        }
        
        int r = lo+(hi-lo)/2;
        lo = 0, hi = m-1;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(matrix[r][mid]==target){
                return true;
            }else if(matrix[r][mid]<target){
                lo = mid+1;
            }else{
                hi = mid-1;
            }
        }
        return false;
    }