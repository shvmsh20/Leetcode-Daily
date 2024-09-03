int getLucky(string s, int k) {
        string str;
        for(char x: s){
            int lastDigit = (x-'a')+1;
            str = str + to_string(lastDigit);
        }
        int res = 0;
        for(char x: str){
            res+= (x-'0');
        }
        k--;
        while(k--){
            int newRes = 0;
            while(res){
                newRes+= res%10;
                res/=10;
            }
            res = newRes;
        }
        return res;
    }