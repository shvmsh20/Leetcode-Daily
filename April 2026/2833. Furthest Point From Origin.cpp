int furthestDistanceFromOrigin(string moves) {
        int left = 0, right = 0, t = 0;
        for(char x: moves){
            if(x=='L'){
                left++;
            }else if(x=='R'){
                right++;
            }else {
                t++;
            }
        }
        return abs(left-right)+t;
    }