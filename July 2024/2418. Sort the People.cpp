vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int, int>> temp;
        int n = names.size();
        for(int i=0; i<n; i++){
            temp.push_back({heights[i], i});
        }
        sort(temp.rbegin(), temp.rend());
        vector<string> res;
        for(int i=0; i<n; i++){
            res.push_back(names[temp[i].second]);
        }
        return res;
    }