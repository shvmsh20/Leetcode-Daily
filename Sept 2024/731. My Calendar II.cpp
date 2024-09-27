MyCalendarTwo() {
        
    }
    map<int, int> mp;
    bool book(int start, int end) {
        mp[start]++;
        mp[end]--;
        int sum=0;
        for(auto x: mp){
            sum+=x.second;
            if(sum==3){
                mp[start]--;
                mp[end]++;
                return false;
            }
        }
        return true;
    }
};