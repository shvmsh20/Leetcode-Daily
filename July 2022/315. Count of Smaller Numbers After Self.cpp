void merge(int l, int mid, int h, vector<pair<int, int>> &v, vector<int> &res){
        int i = l;
        int j = mid+1;
        vector<pair<int, int>> temp;
        while(i<=mid && j<=h){
            if(v[i].first>v[j].first){
                res[v[i].second] += h-j+1;
                temp.push_back({v[i].first, v[i].second});
                i++;
            }else{
                temp.push_back({v[j].first, v[j].second});
                j++;
            }
        }
        while(i<=mid){
            temp.push_back({v[i].first, v[i].second});
            i++;
        }
        while(j<=h){
            temp.push_back({v[j].first, v[j].second});
            j++;
        }
        for(int i=0; i<temp.size(); i++){
            v[l+i] = temp[i]; 
        }
    }
    void mergeSort(int l, int h, vector<pair<int, int>> &v, vector<int> &res){
        if(l<h){
            int mid = l+(h-l)/2;
            mergeSort(l, mid, v, res);
            mergeSort(mid+1, h, v, res);
            merge(l, mid, h, v, res);
        }
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        vector<pair<int, int>> v;
        for(int i=0; i<n; i++){
            v.push_back({nums[i], i});
        }
        mergeSort(0, n-1, v, res);
        return res;
    }