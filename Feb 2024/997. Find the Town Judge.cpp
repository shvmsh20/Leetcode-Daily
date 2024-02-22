int findJudge(int n, vector<vector<int>>& trust) {
        vector<bool> arr(n+1, true);
        map<int, unordered_set<int>> mp;
        for(auto x: trust){
            arr[x[0]] = false;
            mp[x[0]].insert(x[1]);
        }
        for(int i=1; i<=n; i++){
            if(arr[i]==true){
                bool flag = true;
                for(int j=1; j<=n; j++){
                    if(j==i){
                        continue;
                    }
                    if(mp[j].find(i)==mp[j].end()){
                        flag = false;
                        break;
                    }
                }
                if(flag){
                    return i;
                }
            }
        }
        return -1;
    }