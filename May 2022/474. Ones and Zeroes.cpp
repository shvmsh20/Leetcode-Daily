//Memoization Top-Down
int dp[101][101][601];
    int solve(vector<vector<int>> &v, int m, int n, int index){
        if(index<0){
            return 0;
        }
        if(dp[m][n][index]!=-1){
            return dp[m][n][index];
        }
        if(m>=v[index][0] && n>=v[index][1]){
            return dp[m][n][index] = max(1+solve(v, m-v[index][0], n-v[index][1], index-1), 
                      solve(v, m, n, index-1));
        }else{
            return dp[m][n][index] = solve(v, m, n, index-1);
        }
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int size = strs.size();
        vector<vector<int>> v(size, vector<int> (2));
        memset(dp, -1, sizeof(dp));
        for(int i=0; i<size; i++){
            string s = strs[i];
            int ones=0, zeros=0;
            for(auto x: s){
                if(x=='1'){
                    ones++;
                }else{
                    zeros++;
                }
            }
            v[i][0] = zeros;
            v[i][1] = ones;
        }
        int ans = solve(v, m, n, size-1);
        return ans;
    }

//Tabulation Bottom-Up
int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>> dp(strs.size()+1, vector<vector<int>> (m+1, vector<int>(n+1)));
        for(int i=1; i<=strs.size(); i++){
            int countZeros = count(strs[i-1].begin(), strs[i-1].end(), '0');
            int countOnes = strs[i-1].size() - countZeros;
            for(int j=0; j<=m; j++){
                for(int k=0; k<=n; k++){
                    if(j-countZeros>=0 && k-countOnes>=0){
                        dp[i][j][k]=max(1+dp[i-1][j-countZeros][k-countOnes], dp[i-1][j][k]);
                    }
                    else{
                        dp[i][j][k] = dp[i-1][j][k];
                    }
                }
            }
        }
        return dp[strs.size()][m][n];
    }    