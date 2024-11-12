int solve(int price, vector<int> &mxBeauty, vector<vector<int>>& items){
        int st = 0, end = items.size()-1;
        int res = -1;
        while(st<=end){
            int mid = (st+end)/2;
            if(items[mid][0]<=price){
                res = mid;
                st = mid+1;
            }else{
                end = mid-1;
            }
        }
        if(res!=-1){
            return mxBeauty[res];
        }
        return 0;
    }
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n = items.size(), m = queries.size();
        sort(items.begin(), items.end());
        vector<int> res(m);
        vector<int> mxBeauty(n);
        int curr = 0;
        for(int i=0; i<n; i++){
            curr = max(curr, items[i][1]);
            mxBeauty[i] = curr;
        }
        for(int i=0; i<m; i++){
            res[i] = solve(queries[i], mxBeauty, items);
        }
        return res;
    }