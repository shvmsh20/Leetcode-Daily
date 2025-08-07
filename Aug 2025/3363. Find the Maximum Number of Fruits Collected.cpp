int n;
    vector<vector<int>>dp;
    int child1(vector<vector<int>>&fruits){
        int ans=0;

        // Will collect diagonal fruits bcoz (n-1) steps
        for(int i=0;i<n;i++){
            ans+=fruits[i][i];
        }
        return ans;
    }
    int child2(vector<vector<int>>&fruits,int i,int j){
        if(i>=n || j<0 || j>=n){
            return 0;
        }

        // Can't cross diagonal -> (n-1) Steps
        if(i==j || i>j) return 0;

        // Reached End
        if(i==n-1 && j==n-1) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];

        // Explore All Directions
        int bottomLeft=fruits[i][j]+child2(fruits,i+1,j-1);
        int bottomRight=fruits[i][j]+child2(fruits,i+1,j+1);
        int bottom=fruits[i][j]+child2(fruits,i+1,j);

        return dp[i][j]=max({bottomLeft,bottomRight,bottom});
    }
    int child3(vector<vector<int>>&fruits,int i,int j){
        if(i>=n || j<0 || j>=n){
            return 0;
        }

        // Can't cross diagonal -> (n-1) Steps
        if(i==j || i<j) return 0;
        
        // Reached End
        if(i==n-1 && j==n-1) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        // Explore All Directions
        int right=fruits[i][j]+child3(fruits,i,j+1);
        int rightUp=fruits[i][j]+child3(fruits,i-1,j+1);
        int rightDown=fruits[i][j]+child3(fruits,i+1,j+1);

        return dp[i][j]=max({right,rightUp,rightDown});
    }
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        n=fruits.size();

        dp.resize(n+1,vector<int>(n+1,-1));

        int c1=child1(fruits);
        int c2=child2(fruits,0,n-1);
        int c3=child3(fruits,n-1,0);

        return c1+c2+c3;
    }