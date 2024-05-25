void util(int ind, int n, string &s, unordered_map<string, int> &mp, vector<string> &res, vector<string> &temp){
        if(ind==n){
            string ans="";
            for(int i=0; i<temp.size(); i++){
                if(i==temp.size()-1)  ans+= temp[i];
                else ans += temp[i]+" ";
            }
            res.push_back(ans);
            return;
        }
        for(int i=ind; i<n; i++){
            if(mp[s.substr(ind, i-ind+1)]){
                temp.push_back(s.substr(ind, i-ind+1));
                util(i+1, n, s, mp, res, temp);
                temp.pop_back();
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> res;
        vector<string> temp;
        int n = s.size();
        unordered_map<string, int> mp;
        for(string x: wordDict){
            mp[x]++;
        }
        util(0, n, s, mp, res, temp);
        return res;
    }