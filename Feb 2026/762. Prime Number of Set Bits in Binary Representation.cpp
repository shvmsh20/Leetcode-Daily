int countPrimeSetBits(int left, int right) {
        unordered_set<int> s = {2,3,5,7,11,13,17,19,23,29,31};
        int res = 0;
        for(int i=left; i<=right; i++){
            int setBits = __builtin_popcount(i);
            if(s.find(setBits)!=s.end()){
                res++;
            }
        }
        return res;
    }