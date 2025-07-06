class FindSumPairs {
public:
    vector<int> a,b;
    unordered_map<int,int> umb;
    int mx=0;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        a=nums1;
        b=nums2;

        sort(begin(a), end(a));

        for(auto& val:b){umb[val]++; mx=max(mx, val);}
    }
    
    void add(int index, int val) {
        umb[b[index]]--;

        b[index] += val;
        mx = max(mx, b[index]);

        umb[b[index]]++;
    }
    
    int count(int tot) {
        int pairs = 0;
        
        int mn_key = lower_bound(a.begin(), a.end(), tot - mx) - a.begin();

        for(int i=mn_key;i<a.size();i++){
            int remain = tot - a[i];

            if(umb.count(remain)){
                int calc = umb[remain];
                pairs += calc;
            }
        }

        return pairs;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */