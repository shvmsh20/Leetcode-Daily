int res = INT_MAX;
    void solve(int ind , int k, vector<int>& cookies, vector<int> &v){
        if(ind==cookies.size()){
            int mx = INT_MIN;
            for(int i=0; i<k; i++){
                mx = max(mx, v[i]);
            }
            res = min(res, mx);
            return;
        }
        for(int i=0; i<k; i++){
            v[i]+= cookies[ind];
            solve(ind+1, k, cookies, v);
            v[i]-= cookies[ind];
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> v(k, 0);
        solve(0, k, cookies, v);
        return res;
    }