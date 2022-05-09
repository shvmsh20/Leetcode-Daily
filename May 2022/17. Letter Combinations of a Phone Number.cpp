void solve(string digits, unordered_map<char, string> &mp, vector<string> &res,
              string temp, int index){
        if(index==digits.size()){
            if(temp.empty()){
                return;
            }
            res.push_back(temp);
            return;
        }
        for(auto x: mp[digits[index]]){
            temp.push_back(x);
            solve(digits, mp, res, temp, index+1);
            temp.pop_back();
        }
        
    }
    vector<string> letterCombinations(string digits) {
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
        vector<string> res;
        string temp;
        solve(digits, mp, res, temp, 0);
        return res;
    }