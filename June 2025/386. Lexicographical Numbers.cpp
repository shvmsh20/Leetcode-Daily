void dfs(int num, int n, vector<int> &res){
        if(num>n) return;
        res.push_back(num);
        for(int i=0; i<=9; i++){
            int newNum = num*10 + i;
            dfs(newNum, n, res);
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        for(int i=1; i<=9; i++){
            dfs(i, n, res);
        }
        return res;
    }