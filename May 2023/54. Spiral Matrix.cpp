vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int top=0, bottom= matrix.size()-1;
        int left = 0, right = matrix[0].size()-1;
        vector<int> res;
        int d=0;
        while(top<=bottom && left<=right){
            if(d==0 && top<=bottom && left<=right){
                for(int j=left; j<=right; j++){
                    res.push_back(matrix[top][j]);
                }
                top++;
                d++;
            }
            if(d==1 && top<=bottom && left<=right){
                for(int i=top; i<=bottom; i++){
                    res.push_back(matrix[i][right]);
                }
                right--;
                d++;
            }
            if(d==2 && top<=bottom && left<=right){
                for(int j=right; j>=left; j--){
                    res.push_back(matrix[bottom][j]);
                }
                bottom--;
                d++;
            }
            if(d==3 && top<=bottom && left<=right){
                for(int i=bottom; i>=top; i--){
                    res.push_back(matrix[i][left]);
                }
                left++;
                d=0;
            }
        }
        return res;
    }