void solve(int k, int n, vector<int> &num, vector<vector<int>> &res,
               vector<int> &temp, int index){
        if(n==0 && k==0){
            res.push_back(temp);
            return;
        }
        if(n<=0 || k==0){
            return;
        }
        for(int i=index; i<9; i++){
            temp.push_back(num[i]);
            solve(k-1, n-num[i], num, res, temp, i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> num = {1,2,3,4,5,6,7,8,9};
        vector<vector<int>> res;
        vector<int> temp;
        solve(k, n, num, res, temp, 0);
        return res;
    }