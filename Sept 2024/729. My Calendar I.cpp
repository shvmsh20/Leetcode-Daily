class MyCalendar {
public:
    map<int, int> mp;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        mp[start]++;
        mp[end]--;
        int cnt = 0;
        for(auto x: mp){
            cnt+= x.second;
            if(cnt==2){
                mp[start]--;
                mp[end]++;
                return false;
            }
        }
        return true;
    }
};
