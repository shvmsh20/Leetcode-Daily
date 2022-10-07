MyCalendarThree() {
        
    }
    
     map<int, int> count = {{-1, 0}};
    int res = 0;
    int book(int s, int e) {
        auto start = count.emplace(s, (--count.upper_bound(s))->second);
        auto end = count.emplace(e, (--count.upper_bound(e))->second);
        for (auto i = start.first; i != end.first; ++i)
            res = max(res, ++(i->second));
        return res;
    }