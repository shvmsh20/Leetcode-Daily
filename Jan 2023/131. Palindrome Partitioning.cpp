vector<vector<string>> res;
    bool isPal(int st, int end, string &s){
        while(st<end){
            if(s[st]!=s[end]){
                return false;
            }
            st++;
            end--;
        }
        return true;
    }
    void solve(int st, int n, string &s, vector<string> &ans){
        if(st==n){
            res.push_back(ans);
            return;
        }
        string temp;
        for(int i=st; i<n; i++){
            temp+= s[i];
            if(isPal(st, i, s)){
                ans.push_back(temp);
               
                solve(i+1, n, s, ans);
                ans.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n = s.length();
        vector<string> ans;
       
        solve(0, n, s, ans);
        return res;
    }