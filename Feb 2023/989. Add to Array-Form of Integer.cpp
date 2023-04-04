vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> res;
        int n = num.size()-1;
        int carry = 0;
        while(n>=0 || carry || k){
            int sum = (n>=0?num[n]:0) + carry + k%10;
            k/=10;
            res.push_back(sum%10);
            carry = sum/10;
            n--;
        }
        reverse(res.begin(), res.end());
        return res;
    }