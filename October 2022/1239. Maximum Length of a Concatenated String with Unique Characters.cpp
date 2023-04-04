int res = INT_MIN;
    bool isCheck(string &s, vector<int> freq){
        for(int i=0; i<s.length(); i++){
            freq[s[i]-'a']++;
            if(freq[s[i]-'a']>=2){
                return false;
            }
        }
        return true;
    }
    void solve(int index, int n, vector<string> &arr, vector<int> &freq, int currlen){
        if(index==n){
            return;
        }
        if(isCheck(arr[index], freq)){
            currlen+=arr[index].length();
            res = max(res, currlen);
            for(int i=0; i<arr[index].length(); i++){
                freq[arr[index][i]-'a']++;
            }
            solve(index+1, n, arr, freq, currlen);
            for(int i=0; i<arr[index].length(); i++){
                freq[arr[index][i]-'a']--;
            }
            currlen-=arr[index].length();
        }
        solve(index+1, n, arr, freq, currlen);
    }
    int maxLength(vector<string>& arr) {
        vector<int> freq(26, 0);
        int n = arr.size();
        solve(0, n, arr, freq, 0);
        return res==INT_MIN?0:res;
    }