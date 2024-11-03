bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) return 0;
        
        goal += goal;
        
        int a = 0, b = 0, res = 0, prev = 0;
        while (a < s.size() && b < goal.size()) {
            if (s[a] == goal[b]) {
                a++;
                if(a >= s.size()) return 1;
            } else {
                a = 0;
                b = prev;
                prev++;
            }
            b++;
        }
        return 0;
    }