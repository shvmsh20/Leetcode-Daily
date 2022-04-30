void dfs(string s, string e, unordered_map<string, vector<pair<string, double>>> &mp, 
            unordered_set<string> &v, double &ans, double temp){
        if(v.find(s)!=v.end()) return;
        v.insert(s);
        if(s==e){
            ans = temp;
        }
        for(auto x: mp[s]){
            dfs(x.first, e, mp, v, ans, temp*x.second);
        }
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> mp;
        for(int i=0; i<values.size(); i++){
            string a = equations[i][0];
            string b = equations[i][1];
            double val = values[i];
            mp[a].push_back({b, val});
            mp[b].push_back({a, 1/val});
        }
        vector<double> res;
        for(auto q: queries){
            double ans = -1.0;
            double temp = 1.0;
            string s = q[0];
            string e = q[1];
            unordered_set<string> v;
            if(mp.find(s)!=mp.end() && mp.find(e)!=mp.end()){
                dfs(s, e, mp, v, ans, temp);
            }
            res.push_back(ans);
        }
        return res;
    }