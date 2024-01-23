bool check(string &s, vector<int> &freq){
        for(int i=0; i<s.size(); i++){
            if(freq[s[i]-'a']){
                return false;
            }
        }
        return true;
    }
    bool dup(string &x){
        unordered_set<char> y(x.begin(), x.end());
        if(x.size()!=y.size()){
            return true;
        }
        return false;
    }
    void solve(int index, int n, vector<string>& arr, int currAns, vector<int> &freq, int &res){
        if(index==n){
            return;
        }
        if(check(arr[index], freq) && !dup(arr[index])){
            currAns+= arr[index].size();
            res = max(res, currAns);
            for(int i=0; i<arr[index].size(); i++){
                freq[arr[index][i]-'a']++;
            }
            solve(index+1, n, arr, currAns, freq, res);
            for(int i=0; i<arr[index].size(); i++){
                freq[arr[index][i]-'a']--;
            }
            currAns-= arr[index].size();
        }
        solve(index+1, n, arr, currAns, freq, res);
    }
    int maxLength(vector<string>& arr) {
        int res = 0, n = arr.size();
        vector<int> freq(26, 0);
        solve(0, n, arr, 0, freq, res);
        return res;
    }