int findJudge(int n, vector<vector<int>>& trust) {
        stack<int> st;
        map<int, unordered_set<int>> mp;
        for(auto x: trust){
            mp[x[0]].insert(x[1]);
        }
        for(auto x: trust){
            if(st.empty()){
                st.push(x[1]);
            }else{
                int a = st.top();
                st.pop();
                int b = x[1];
                if(mp[a].find(b)!=mp.end() )
            }
        }
        return -1;
    }