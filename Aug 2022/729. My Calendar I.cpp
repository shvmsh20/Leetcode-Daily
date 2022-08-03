map<int, int> mp;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        mp[start]++;
        mp[end]--;
        int sum=0;
        for(auto x: mp){
            sum+= x.second;
            if(sum==2){
                mp[start]--;
                mp[end]++;
                return false;
            }
        }
        return true;
        
    }