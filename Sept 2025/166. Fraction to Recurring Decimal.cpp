string fractionToDecimal(int num, int den) {
        bool neg = false;
        if((num<0 || den<0) && !(num<0 && den<0) && num!=0){
            neg = true;
        }
        num = abs(num);
        den = abs(den);
        long long q = num/den;
        long long r = num%den;
        if(r==0){
            if(neg){
                return "-"+to_string(q);
            }
            return to_string(q);
        }
        string res = to_string(q);
        res+='.';
        unordered_map<int, int> mp;
        while(r!=0){
            if(mp.find(r)!=mp.end()){
                res.insert(mp[r], "(");
                res+=')';
                break;
            }else{
                mp[r] = res.size();
            }
            r = r*10;
            q = r/den;
            r = r%den;
            res+=to_string(q);
        }
        if(neg){
            return "-"+res;
        }
        return res;
    }