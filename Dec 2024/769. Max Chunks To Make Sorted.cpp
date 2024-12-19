int solve(int index, int n, vector<int> &arr, string &s){
        if(index==n){
            return 0;
        }
        string curr;
        for(int i=index; i<n; i++){
            curr.push_back('0'+arr[i]);
            sort(curr.begin(), curr.end());
            if(curr == s.substr(index, i-index+1)){
                return 1+solve(i+1, n, arr, s);
            }
        }
        return 1;
    }
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        string s;
        for(int i=0; i<n; i++){
            s.push_back('0'+arr[i]);
        }
        sort(s.begin(), s.end());
        return solve(0, n, arr, s);
    }