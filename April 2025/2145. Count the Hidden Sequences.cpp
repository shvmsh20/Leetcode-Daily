int numberOfArrays(vector<int>& diff, int lower, int upper) {
        long mn = diff[0], mx = diff[0], n = diff.size();
        long curr = diff[0];
        for(int i=1; i<n; i++){
            curr+= diff[i];
            mn = min(mn, curr);
            mx = max(mx, curr);
        }
        mx = max(mx, (long) 0);
        long less = abs(min(mn, (long) 0));
        long x = lower+less;
        // cout << x << " " << less << endl;
        if((x+mx)>upper){
            return 0;
        }
        return upper-(x+mx)+1;
    }