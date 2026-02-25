static bool cmp(int x, int y){
        int bitSetX = __builtin_popcount(x);
        int bitSetY = __builtin_popcount(y);
        if(bitSetX!=bitSetY){
            return bitSetX<bitSetY;
        }
        return x<y;
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), cmp);
        return arr;
    }