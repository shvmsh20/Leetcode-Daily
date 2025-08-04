int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> mp;
        int n = fruits.size();
        int left = 0, res = 0;
        for(int right=0; right<n; right++){
            mp[fruits[right]]++;
            while(mp.size()==3){
                mp[fruits[left]]--;
                 if(mp[fruits[left]]==0){
                    mp.erase(fruits[left]);
                }
                left++;
            }
            res = max(res, right-left+1);
        }
        return res;
    }