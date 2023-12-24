int minOperations(string s) {
        int n = s.length();
        int y1 = 0, y2 = 1;
        int x1 = 0, x2 = 0;
        for(int i=0; i<n; i++){
            if(s[i]!=(y1+'0')){
                x1++;
            }
            if(s[i]!=(y2+'0')){
                x2++;
            }
            y1 = y1^1;
            y2 = y2^1;
        }
        return min(x1, x2);
    }