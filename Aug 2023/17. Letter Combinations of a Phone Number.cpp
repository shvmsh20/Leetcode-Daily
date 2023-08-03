void solve(int index, int n, string &s, string &temp, vector<string> &res, unordered_map<char, string> &mp){
        if(index==n){
            res.push_back(temp);
            return;
        }
        for(int i=0; i<mp[s[index]].size(); i++){
            temp+=mp[s[index]][i];
            solve(index+1, n, s, temp, res, mp);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.size()==0){
            return res;
        }
        int n = digits.size();
        unordered_map<char, string> mp;
        mp['1']="";
        mp['2']="abc";
        mp['3']="def";
        mp['4']="ghi";
        mp['5']="jkl";
        mp['6']="mno";
        mp['7']="pqrs";
        mp['8']="tuv";
        mp['9']="wxyz";
        string temp;
        solve(0, n, digits, temp, res, mp);
        return res;
        
    }