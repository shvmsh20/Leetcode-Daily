int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> rightOnes;
        for(int i=0; i<n; i++){
            int cnt = 0, j = n-1;
            while(j>=0){
                if(grid[i][j]==0){
                    cnt++;
                    j--;
                }else{
                    break;
                }
            }
            rightOnes.push_back(cnt);
        }
        int res = 0, index = 0;
        for(int req = n-1; req>0; req--){
            if(rightOnes[index]>=req){
                index++;
            }else{
                int i = index+1;
                while(i<n && rightOnes[i]<req){
                    i++;
                }
                if(i==n) return -1;
                while(i>index){
                    swap(rightOnes[i], rightOnes[i-1]);
                    res++;
                    i--;
                }
                index++;
            }
        }
        return res;
    }