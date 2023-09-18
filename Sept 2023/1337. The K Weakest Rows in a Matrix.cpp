int help(vector<int> arr, int n){
        int res = 0;
        for(int i=0; i<n; i++){
            if(arr[i]==1){
                res++;
            }else{
                break;
            }
        }
        return res;
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = mat.size(), m = mat[0].size();
        vector<pair<int, int>> res;
        for(int i=0; i<n; i++){
            res.push_back({help(mat[i], m), i});
        }
        sort(res.begin(), res.end());
        vector<int> ans;
        for(int i=0; i<n && i<k; i++){
            ans.push_back(res[i].second);
        }
        return ans;
    }