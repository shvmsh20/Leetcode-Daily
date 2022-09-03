void solve(int n, int k, int prev, string& temp, vector<int> &res){
        if(n==0){
            if(!temp.empty()){
                int ans = stoi(temp);
                res.push_back(ans);
            }
            return;
        }
        if(prev==-1){
            for(int i=1; i<=9; i++){
                temp+= to_string(i);
                solve(n-1, k, i, temp, res);
                temp.pop_back();
            }
        }else{
            int t1 = prev-k;
            if(t1>=0){
                temp+= to_string(t1);
                solve(n-1, k, t1, temp, res);
                temp.pop_back();
            }
            int t2 = prev+k;
            if(t1!=t2 && t2<=9){
                temp+= to_string(t2);
                solve(n-1, k, t2, temp, res);
                temp.pop_back();
            }
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> res;
        string temp;
        solve(n, k, -1, temp, res);
        return res;
    }