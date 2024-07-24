int helper(int x, vector<int> &mapping){
        int res = 0;
        long place = 1;
        do{
            int lastDigit = x%10;
            x/=10;
            res = res + (place*mapping[lastDigit]);
            place*=10;
        }while(x);
        
        return res;
    }
    static bool cmp(pair<int, int> &p1, pair<int, int> &p2){
        return p1.first<p2.first;
       
        
    }
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int, int>> temp;
        for(int x: nums){
            int y = helper(x, mapping);
            temp.push_back({y, x});
            // cout << y << " ";
        }
        sort(temp.begin(), temp.end(), cmp);
        vector<int> res;
        for(auto x: temp){
            res.push_back(x.second);
        }
        return res;

    }