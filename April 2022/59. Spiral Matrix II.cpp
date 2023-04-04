void fillmatrix(vector<vector<int>> &v, int n){
        int x=0;
        int top=0, left=0, bottom=n-1, right=n-1;
        while(top<=bottom && left<=right){
            int j=0;
            if(j==0){
                for(int i=left; i<=right; i++){
                    v[top][i] = ++x;
                }
                top++;
                j++;
            }
            if(j==1){
                for(int i=top; i<=bottom; i++){
                    v[i][right] = ++x;
                }
                right--;
                j++;
            }
            if(j==2){
                for(int i=right; i>=left; i--){
                    v[bottom][i] = ++x;
                }
                bottom--;
                j++;
            }
            if(j==3){
                for(int i=bottom; i>=top; i--){
                    v[i][left] = ++x;
                }
                left++;
            }
        }
    }
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> v(n, vector<int> (n, 0));
        fillmatrix(v, n);
        return v;
    }